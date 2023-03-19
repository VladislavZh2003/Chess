#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
using namespace std;

class ChessBoard
{
	private:
		const int maxRow = 8*4+1;
		const int maxColumn = 9*8+1;
		
		int x;
		int y;
		int firstCounter = 0;
		int secondCounter = 0;
		
	public:
	
		ChessBoard();
		
		void ChooseFigura(char chooser, int num, char color);
		void PrintBoard();
		void Number_Print(int count);
		void Pawn_Print(int num, char color);
		void Rook_Print(int num, char color);
		void Officer_Print(int num, char color);
		void Horse_Print(int num, char color);
		void King_Print(int num, char color);
		void Queen_Print(int num, char color);
		void HelpFile();
		void ClearConsole();
		
		~ChessBoard();
	protected:
		string BoardFigures[8][8];
};

#endif
