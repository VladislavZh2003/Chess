#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	for(int i = 0; i<8; i++)
	{
		this->BoardFigures[1][i] = "PB";
		this->BoardFigures[6][i] = "PW";
	}
	this->BoardFigures[0][0] = "RB";
	this->BoardFigures[0][1] = "HB";
	this->BoardFigures[0][2] = "OB";
	this->BoardFigures[0][3] = "QB";
	this->BoardFigures[0][4] = "KB";
	this->BoardFigures[0][5] = "OB";
	this->BoardFigures[0][6] = "HB";
	this->BoardFigures[0][7] = "RB";
	
	this->BoardFigures[7][0] = "RW";
	this->BoardFigures[7][1] = "HW";
	this->BoardFigures[7][2] = "OW";
	this->BoardFigures[7][3] = "QW";
	this->BoardFigures[7][4] = "KW";
	this->BoardFigures[7][5] = "OW";
	this->BoardFigures[7][6] = "HW";
	this->BoardFigures[7][7] = "RW";
};

void ChessBoard::PrintBoard()
{
	x = 0;
	y = 0;
	
	for (int i = 0; i<maxRow; ++i)
	{
		for(int j = 0; j<maxColumn;++j)
		{	
			
		    if(i%4 > 0 && i%4 < 4 && j%9 == 1)
			{
				if(BoardFigures[x][y] != "")
				{
					ChooseFigura(BoardFigures[x][y][0],secondCounter+1,BoardFigures[x][y][1]);
					if(secondCounter == 0)
					j+=6;
					else
					j+=7;
				}
				else
				cout<<" ";				
				y++;
			}	
			else if(j%9 == 0)
			{
				if(i%4 == 0)
				{
					cout<<"+";
				}
				else
				{
					cout<<"|";
				}
			}
			else if(i%4 == 0)
			{
				cout<<"-";
			}	
			else if(i%4 == 1 && (j+1)%9 == 0)
			{
				if((i-1)%8 == 4 ^ (j+1)%18 == 0)
				cout<<"*";
				else
				cout<<" ";
			}
			else
			{
				cout<<" ";
			}	
		}
		if(i%4 > 0 && i%4 < 4)
		{
			y = 0;
			this->firstCounter = 0;
			this->secondCounter++;
			if(secondCounter == 3)
			{
				this->secondCounter = 0;		
			}
			if(i%4 == 3)
			{
				x++;
			}
		}
		Number_Print(i);
	}
	cout<<"\n";
    cout<<"    /\\      |^^)     /^^\\     |^^\\     |^^^     |^^^     /^^\\     |  |"<<endl;
    cout<<"   /--\\     |--)    (         |   )    |---     |---    (  __     |--|"<<endl;
	cout<<"  /    \\    |__)     \\__/     |__/     |___     |        \\__/     |  |"<<endl;		
}

void ChessBoard::Number_Print(int count)
{
	if(count == 1)
	cout<<"  /|"<<endl;
	else if(count == 2)
	cout<<"   |"<<endl;
	else if(count == 3)
	cout<<"  _|_"<<endl;
	else if(count == 5)
	cout<<"  |^\\"<<endl;
	else if(count == 6)
	cout<<"    /"<<endl;
	else if(count == 7)
	cout<<"   /__"<<endl;
	else if(count == 9)
	cout<<"  /^\\"<<endl;
	else if(count == 10)
	cout<<"    /"<<endl;
	else if(count == 11)
	cout<<"  \\_\\"<<endl;
	else if(count == 13)
	cout<<"  |  |"<<endl;
	else if(count == 14)
	cout<<"  |__|"<<endl;
	else if(count == 15)
	cout<<"     |"<<endl;
	else if(count == 17)
	cout<<"  |^^^"<<endl;
	else if(count == 18)
	cout<<"  \\--\\"<<endl;
	else if(count == 19)
	cout<<"   __/"<<endl;
	else if(count == 21)
	cout<<"  |^^^"<<endl;
	else if(count == 22)
	cout<<"  |--\\"<<endl;
	else if(count == 23)
	cout<<"  |__|"<<endl;
	else if(count == 25)
	cout<<"  ^^^/"<<endl;
	else if(count == 26)
	cout<<"    /"<<endl;
	else if(count == 27)
	cout<<"   /"<<endl;
	else if(count == 29)
	cout<<"  |^^|"<<endl;
	else if(count == 30)
	cout<<"  |--|"<<endl;
	else if(count == 31)
	cout<<"  |__|"<<endl;
	else
	cout << "\n";
}

void ChessBoard::ChooseFigura(char chooser, int num, char color)
{
	switch(chooser)
	{
		case 'P':
			this->Pawn_Print(num,color);
			break;
		case 'R':
			this->Rook_Print(num,color);
			break;
		case 'O':
			this->Officer_Print(num,color);
			break;
		case 'H':
			this->Horse_Print(num,color);
			break;
		case 'K':
			this->King_Print(num,color);
			break;
		case 'Q':
			this->Queen_Print(num,color);
			break;
	}	
}

void ChessBoard::Pawn_Print(int num, char color)
{
	if(num == 1)
	cout<<color<<"  __  ";
	else if(num == 2)
	cout<<"   ||   ";
	else
	cout<<"  /==\\  ";
}

void ChessBoard::Rook_Print(int num, char color)
{
	if(num == 1)
	cout<<color<<"  ^^  ";
	else if(num == 2)
	cout<<"  |[]|  ";
	else
	cout<<" |||||| ";
}

void ChessBoard::Officer_Print(int num, char color)
{
	if(num == 1)
	cout<<color<<"  ++  ";
	else if(num == 2)
	cout<<"   ||   ";
	else
	cout<<" _====_ ";
}

void ChessBoard::Horse_Print(int num, char color)
{
	if(num == 1)
	cout<<color<<"  #\\  ";
	else if(num == 2)
	cout<<"  /\\ |~ ";
	else
	cout<<" /==\\   ";
}

void ChessBoard::King_Print(int num, char color)
{
	if(num == 1)
	cout<<color<<"  ||  ";
	else if(num == 2)
	cout<<"  /\\/\\  ";
	else
	cout<<" /\\/\\/\\ ";
}

void ChessBoard::Queen_Print(int num, char color)
{
	if(num == 1)
	cout<<color<<"  !!  ";
	else if(num == 2)
	cout<<"  ()()  ";
	else
	cout<<" &&&&&& ";
}

void ChessBoard::HelpFile()
{
	string helpStr = "\nTo play, enter the field where the \nfigure you want to use is located.\nThen enter the field you want your figure to go to.\n(the field consists of a row and a column like 7h)\nThe castling is made by the king.\nJust have fun and enjoy the game!\n";
	cout<<helpStr<<endl;
}

void ChessBoard::ClearConsole()
{
	system("cls");
}

ChessBoard::~ChessBoard()
{
};

