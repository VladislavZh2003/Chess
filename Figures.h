#ifndef FIGURES_H
#define FIGURES_H

#include "ChessBoard.h"

#include <iostream>
#include <string>
using namespace std;

class Figures : public ChessBoard
{
	private:
			
	public:
		int rRow;
		int rColumn;
		string rAttacker;
		int rGoRow;
		int rGoColumn;
		string rVictim;
		
		int rMay;
		int cMay;
		string attMay;
		int goRMay;
		int goCMay;
		string vicMay;
		
		int RowCh;
		int ColumnCh;
		string AttCh;
		int GoRowCh;
		int GoColumnCh; 
		string VicCh;
		
		int kingCast[2];
		int rookCast[4];
		int pawnPassant[2][8];
		
		int numRow;
		char lettColumn;
		int goRow;
		char goColumn;
			
		int player;
		
		Figures();
		
		int ConvertCharToInt(char letter);
		int ReturnColor(int _row, int _column);
		int RelocationFigura(int _row, int _column, int _goRow, int _goColumn);
		void UnRelocationFig(int _row, int _column, int _goRow, int _goColumn);
		int CheckPawnMove(int _row, int _column, int _goRow, int _goColumn);
		int CheckRookMove(int _row, int _column, int _goRow, int _goColumn);
		int CheckHorseMove(int _row, int _column, int _goRow, int _goColumn);
		int CheckOfficerMove(int _row, int _column, int _goRow, int _goColumn);
		int CheckQueenMove(int _row, int _column, int _goRow, int _goColumn);
		int CheckKingMove(int _row, int _column, int _goRow, int _goColumn);
		int Castling(int _row, int _column, int _goRow, int _goColumn);
		int ChessMove();
		int Checkmate();
		
		~Figures();
	protected:
};

#endif
