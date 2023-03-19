#include <iostream>
using namespace std;

#include "ChessBoard.h"
#include "Figures.h"

int main(int argc, char** argv)
{
	Figures fc;
	
	int row;
	char column;
	int goRow;
	char goColumn;
			
	fc.PrintBoard();

	while(true)
	{
		if(fc.ChessMove() == 1)
		{		
			if(fc.Checkmate() == 1)
			break;
			else
			cout<<"You are in chess!"<<endl;
		}
		cout<<"Player: "<<fc.player+1<<" turn."<<endl;
		
		cout<<"Input the field of your figura(for help press 9i): ";
		cin>>row>>column;
		
		if(row == 9 && column == 'i')
		{
			fc.HelpFile();
			continue;
		}
		
		cout<<"Input the field you want to go to: ";
		cin>>goRow>>goColumn;
		fc.numRow = row-1;
		fc.lettColumn = column;
		fc.goRow = goRow-1;
		fc.goColumn = goColumn;
		
		if(fc.numRow < 0 && fc.numRow > 7 && fc.ConvertCharToInt(fc.lettColumn) < 0)
		{
			cout<<"Invalid move!"<<endl;
			continue;
		}
		else if(fc.goRow < 0 && fc.goRow > 7 && fc.ConvertCharToInt(fc.goColumn) < 0)
		{
			cout<<"Invalid move!"<<endl;
			continue;
		}
		else if(fc.player != fc.ReturnColor(fc.numRow,fc.ConvertCharToInt(fc.lettColumn)))
		{
			cout<<"This is not your figura!"<<endl;
			continue;
		}
		else if(fc.RelocationFigura(fc.numRow,fc.ConvertCharToInt(fc.lettColumn),fc.goRow,fc.ConvertCharToInt(fc.goColumn)) == 0)
		{
			cout<<"Invalid move!"<<endl;
			continue;
		}
			
		if(fc.ChessMove() == 1)
		{
			fc.UnRelocationFig(fc.numRow,fc.ConvertCharToInt(fc.lettColumn),fc.goRow,fc.ConvertCharToInt(fc.goColumn));
			cout<<"Look for chess!"<<endl;
			continue;
		}
		
		fc.ClearConsole();
		fc.PrintBoard();
		
		if(fc.player == 0)
		fc.player = 1;
		else
		fc.player = 0;
	}
	if(fc.player == 0)
	fc.player = 1;
	else
	fc.player = 0;
	cout<<"Player: "<<fc.player+1<<" win!"<<endl;
	
	return 0;
}
