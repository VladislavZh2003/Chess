#include "Figures.h"

Figures::Figures()
{
	this->player = 0;
	for(int i = 0; i<4; i++)
		this->rookCast[i] = 0;
		
	for(int i = 0; i<2; i++)
		for(int j = 0; j<8; j++)
			this->pawnPassant[i][j] = 0;
	
	this->kingCast[0] = 0;
	this->kingCast[1] = 0;
	
	this->rAttacker = "";
	this->rVictim = "";
	this->AttCh = "";
	this->VicCh = "";
	
	this->RowCh = 0;
	this->ColumnCh = 0;
	this->GoRowCh = 0;
	this->GoColumnCh = 0;
};

int Figures::ConvertCharToInt(char letter)
{
	switch(letter)
	{
		case 'a': case 'A':
			return 0;
		case 'b': case 'B':
			return 1;
		case 'c': case 'C':
			return 2;
		case 'd': case 'D':
			return 3;
		case 'e': case 'E':
			return 4;
		case 'f': case 'F':
			return 5;
		case 'g': case 'G':
			return 6;
		case 'h': case 'H':
			return 7;
		default:
			return -1;
	}
}

int Figures::ReturnColor(int _row, int _column)
{
	if(BoardFigures[_row][_column][1] == 'W') 
	return 0;
	else if(BoardFigures[_row][_column][1] == 'B')
	return 1;
}

int Figures::RelocationFigura(int _row, int _column, int _goRow, int _goColumn)
{
	rMay = _row;
	cMay = _column;
	attMay = BoardFigures[_row][_column];
	goRMay = _goRow;
	goCMay = _goColumn;
	vicMay = BoardFigures[_goRow][_goColumn];	
	
	if(BoardFigures[_row][_column][1] == 'W' && BoardFigures[_goRow][_goColumn][1] == 'W' || BoardFigures[_row][_column][1] == 'B' && BoardFigures[_goRow][_goColumn][1] == 'B')
	{
		if(Castling(_row,_column,_goRow,_goColumn) == 1)
		goto RElOCATON_MEMORY_VAR;
		else
		return 0;
	}
	else if(_row == _goRow && _goColumn == _column)
	return 0;
	else if(BoardFigures[_row][_column][0] == 'P')
	{
		if(CheckPawnMove(_row,_column,_goRow,_goColumn) == 1)
		goto RElOCATON_MEMORY_VAR;
		else
		return 0;
	}
	else if(BoardFigures[_row][_column][0] == 'R')
	{
		if(CheckRookMove(_row,_column,_goRow,_goColumn) == 1)
		goto RElOCATON_MEMORY_VAR;
		else
		return 0;
	}
	else if(BoardFigures[_row][_column][0] == 'H')
	{
		if(CheckHorseMove(_row,_column,_goRow,_goColumn) == 1)
		goto RElOCATON_MEMORY_VAR;
		else
		return 0;
	}
	else if(BoardFigures[_row][_column][0] == 'O')
	{
		if(CheckOfficerMove(_row,_column,_goRow,_goColumn) == 1)
		goto RElOCATON_MEMORY_VAR;
		else
		return 0;
	}
	else if(BoardFigures[_row][_column][0] == 'Q')
	{
		if(CheckQueenMove(_row,_column,_goRow,_goColumn) == 1)
		goto RElOCATON_MEMORY_VAR;
		else
		return 0;
	}
	else if(BoardFigures[_row][_column][0] == 'K')
	{
		if(CheckKingMove(_row,_column,_goRow,_goColumn) == 1)
		goto RElOCATON_MEMORY_VAR;
		else
		return 0;
	}
	else
	return 0;
	RElOCATON_MEMORY_VAR:
		rRow = rMay;
		rColumn = cMay;
		rAttacker = attMay;
		rGoRow = goRMay;
		rGoColumn = goCMay;
		rVictim = vicMay;
		return 1;
	
}

void Figures::UnRelocationFig(int _row = -1, int _column = -1, int _goRow = -1, int _goColumn = -1)
{
	if(_row > -1 && _column > -1 && _goRow > -1 &&_goColumn > -1)
	{
		if(VicCh == "" && AttCh == "")
		{
			this->BoardFigures[RowCh][ColumnCh] = " ";
			this->BoardFigures[RowCh][ColumnCh] = "";
			this->BoardFigures[GoRowCh][GoColumnCh] = " ";
			this->BoardFigures[GoRowCh][GoColumnCh] = "";
		}
		else if(VicCh == "")
		{
			this->BoardFigures[GoRowCh][GoColumnCh] = " ";
			this->BoardFigures[GoRowCh][GoColumnCh] = "";
			this->BoardFigures[RowCh][ColumnCh] = this->AttCh;
		}
		else if(AttCh == "")
		{
			this->BoardFigures[RowCh][ColumnCh] = " ";
			this->BoardFigures[RowCh][ColumnCh] = "";
			this->BoardFigures[GoRowCh][GoColumnCh] = this->VicCh;
		}
		else
		{
			this->BoardFigures[RowCh][ColumnCh] = this->AttCh;
			this->BoardFigures[GoRowCh][GoColumnCh] = this->VicCh;
		}
	}
	else
	{
		if(rAttacker == "" && rVictim == "")
		{
			this->BoardFigures[rRow][rColumn] = " ";
			this->BoardFigures[rRow][rColumn] = "";
			this->BoardFigures[rGoRow][rGoColumn] = " ";
			this->BoardFigures[rGoRow][rGoColumn] = "";
		}
		else if(rAttacker == "")
		{
			this->BoardFigures[rRow][rColumn] = " ";
			this->BoardFigures[rRow][rColumn] = "";
			this->BoardFigures[rGoRow][rGoColumn] = rVictim;
		}
		else if(rVictim == "")
		{
			this->BoardFigures[rGoRow][rGoColumn] = " ";
			this->BoardFigures[rGoRow][rGoColumn] = "";
			this->BoardFigures[rRow][rColumn] = rAttacker;
		}
		else
		{
			BoardFigures[rRow][rColumn] = rAttacker;
			BoardFigures[rGoRow][rGoColumn] = rVictim;
		}
	}	
} 

int Figures::CheckPawnMove(int _row, int _column, int _goRow, int _goColumn)
{
	if(BoardFigures[_row][_column][1] == 'W')
	{
		if(_goRow == _row-1 && _goColumn == _column && BoardFigures[_goRow][_goColumn] == "")
		goto NOTPASS;
		else if(_goRow == _row-1 && _goColumn == _column+1 && BoardFigures[_goRow][_goColumn] != "")
		goto NOTPASS;
		else if(_goRow == _row-1 && _goColumn == _column-1 && BoardFigures[_goRow][_goColumn] != "")
		goto NOTPASS;
		else if(_row == 6 && _goRow == 4 && _goColumn == _column && BoardFigures[_goRow][_goColumn] == "")
		goto PASSANT;
		else if(pawnPassant[0][_goColumn] == 1 && _row == 3 && _goRow == 2 && (_column == _goColumn-1 || _column == _goColumn+1))
		goto EN_PASSANT_RELOCATION;
	}
	else if(BoardFigures[_row][_column][1] == 'B')
	{
		if(_goRow == _row+1 && _goColumn == _column && BoardFigures[_goRow][_goColumn] == "")
		goto NOTPASS;
		else if(_goRow == _row+1 && _goColumn == _column+1 && BoardFigures[_goRow][_goColumn] != "")
		goto NOTPASS;
		else if(_goRow == _row+1 && _goColumn == _column-1 && BoardFigures[_goRow][_goColumn] != "")
		goto NOTPASS;
		else if(_row == 1 && _goRow == 3 && _goColumn == _column && BoardFigures[_goRow][_goColumn] == "")
		goto PASSANT;
		else if(pawnPassant[1][_goColumn] == 1 && _row == 4 && _goRow == 5 && (_column == _goColumn-1 || _column == _goColumn+1))
		goto EN_PASSANT_RELOCATION;
	}
	return 0;
	PASSANT:
		for(int i = 0; i<2; i++)
			for(int j = 0; j<8; j++)
				this->pawnPassant[i][j] = 0;
		if(BoardFigures[_row][_column][1] == 'B')
		pawnPassant[0][_column] = 1;
		else if(BoardFigures[_row][_column][1] == 'W')
		pawnPassant[1][_column] = 1;	
		goto P_RELOCATION;
	NOTPASS:
		for(int i = 0; i<2; i++)
			for(int j = 0; j<8; j++)
				this->pawnPassant[i][j] = 0;
		if(BoardFigures[_row][_column][1] == 'B')
		pawnPassant[0][_column] = 0;
		else if(BoardFigures[_row][_column][1] == 'W')
		pawnPassant[1][_column] = 0;
		goto P_RELOCATION;
	P_RELOCATION:
		BoardFigures[_goRow][_goColumn] = BoardFigures[_row][_column];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_row][_column] = "";
		return 1;
	EN_PASSANT_RELOCATION:
		for(int i = 0; i<2; i++)
			for(int j = 0; j<8; j++)
				this->pawnPassant[i][j] = 0;
		if(BoardFigures[_row][_column][1] == 'B')
		pawnPassant[0][_column] = 0;
		else if(BoardFigures[_row][_column][1] == 'W')
		pawnPassant[1][_column] = 0;
		for(int i = 0; i<2; i++)	
		BoardFigures[_goRow][_goColumn] = BoardFigures[_row][_column];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_row][_column] = "";
		BoardFigures[_row][_goColumn] = " ";
		BoardFigures[_row][_goColumn] = "";
		return 1;
		
}

int Figures::CheckRookMove(int _row, int _column, int _goRow, int _goColumn)
{
	if(_goColumn == _column)
	{
		if(_goRow > _row)
		{
			for(int i = _row+1; i<_goRow; i++)
				if(BoardFigures[i][_column] != "")
					return 0;
			goto R_RELOCATION;
		}
		else if(_goRow < _row)
		{
			for(int i = _row-1; i>_goRow; i--)
				if(BoardFigures[i][_column] != "")
					return 0;
			goto R_RELOCATION;
		}
	}
	else if(_goRow == _row)
	{
		if(_goColumn > _column)
		{
			for(int i = _column+1; i<_goColumn; i++)
				if(BoardFigures[_row][i] != "")
					return 0;
			goto R_RELOCATION;
		}
		else if(_goColumn < _column)
		{
			for(int i = _column-1; i>_goColumn; i--)
				if(BoardFigures[_row][i] != "")
					return 0;
			goto R_RELOCATION;
		}
	}
	return 0;
	R_RELOCATION:
		if(BoardFigures[_row][_column][0] == 'R')
		{
			if(_row == 0 && _column == 0)
			rookCast[0] = 1;
			else if(_row == 0 && _column == 7)
			rookCast[1] = 1;
			else if(_row == 7 && _column == 0)
			rookCast[2] = 1;
			else if(_row == 7 && _column == 7)
			rookCast[3] = 1;
		}
		BoardFigures[_goRow][_goColumn] = BoardFigures[_row][_column];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_row][_column] = "";
		return 1;
}

int Figures::CheckHorseMove(int _row, int _column, int _goRow, int _goColumn)
{
	if(_goRow == _row-2)
	{
		if(_goColumn == _column+1)
			goto H_RELOCATION;
		else if(_goColumn == _column-1)
			goto H_RELOCATION;
	}
	else if(_goRow == _row+2)
	{
		if(_goColumn == _column+1)
			goto H_RELOCATION;
		else if(_goColumn == _column-1)
			goto H_RELOCATION;
	}
	else if(_goColumn == _column+2)
	{
		if(_goRow == _row+1)
			goto H_RELOCATION;
		else if(_goRow == _row-1)
			goto H_RELOCATION;
	}
	else if(_goColumn == _column-2)
	{
		if(_goRow == _row+1)
			goto H_RELOCATION;
		else if(_goRow == _row-1)
			goto H_RELOCATION;
	}
	return 0;
	H_RELOCATION:
		BoardFigures[_goRow][_goColumn] = BoardFigures[_row][_column];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_row][_column] = "";
		return 1;
}

int Figures::CheckOfficerMove(int _row, int _column, int _goRow, int _goColumn)
{
	if(_row + _column == _goRow + _goColumn )
	{
		if(_goRow > _row && _goColumn < _column)
		{
			for(int i = _row+1, j = _column-1; i<_goRow, j>_goColumn; i++, j--)
				if(BoardFigures[i][j] != "")
					return 0;
			goto O_RELOCATION;
		}
		else if(_goRow < _row && _goColumn > _column)
		{
			for(int i = _row-1, j = _column+1; i>_goRow, j<_goColumn; i--, j++)
				if(BoardFigures[i][j] != "")
					return 0;
			goto O_RELOCATION;
		}
	}
	else if(_row + _goColumn == _column + _goRow)
	{
		if(_goRow < _row && _goColumn < _column)
		{
			for(int i = _row-1, j = _column-1; i>_goRow,j>_goColumn; i--,j--)
				if(BoardFigures[i][j] != "")
					return 0;
			goto O_RELOCATION;
		}
		else if(_goRow > _row && _goColumn > _column)
		{
			for(int i = _row+1, j = _column+1; j<_goColumn, i<_goRow; i++, j++)
				if(BoardFigures[i][j] != "")
					return 0;
			goto O_RELOCATION;
		}
	}
	return 0;
	O_RELOCATION:
		BoardFigures[_goRow][_goColumn] = BoardFigures[_row][_column];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_row][_column] = "";
		return 1;
}

int Figures::CheckQueenMove(int _row, int _column, int _goRow, int _goColumn)
{
	if(CheckRookMove(_row,_column,_goRow,_goColumn) == 1)
	{
		return 1;
	}
	else if(CheckOfficerMove(_row,_column,_goRow,_goColumn) == 1)
	{
		return 1;
	}
	else
	return 0;
}

int Figures::CheckKingMove(int _row, int _column, int _goRow, int _goColumn)
{
	if(BoardFigures[_row][_column][1] != BoardFigures[_goRow][_goColumn][1])
	{
		if((_goRow == _row+1 && _goColumn == _column) || (_goRow == _row && _goColumn == _column+1))
		goto K_RELOCATION;
		else if((_goRow == _row-1 && _goColumn == _column) || (_goRow == _row && _goColumn == _column-1))
		goto K_RELOCATION;
		else if((_goRow == _row+1 && _goColumn == _column+1) || (_goRow == _row-1 && _goColumn == _column-1))
		goto K_RELOCATION;
		else if((_goRow == _row+1 && _goColumn == _column-1) || (_goRow == _row-1 && _goColumn == _column+1))
		goto K_RELOCATION;
	}
	return 0;
	K_RELOCATION:
		BoardFigures[_goRow][_goColumn] = BoardFigures[_row][_column];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_row][_column] = "";
		if(player == 0)
			this->kingCast[0] = 1;
		else if(player == 1)
			this->kingCast[1] = 1;
		return 1;
}

int Figures::Castling(int _row, int _column, int _goRow, int _goColumn)
{
	if(BoardFigures[_row][_column][0] == 'K' && BoardFigures[_goRow][_goColumn][0] == 'R' && kingCast[player] != 1)
	{
		if(BoardFigures[_row][_column][1] == 'W' && _row == 7 && _column == 4 && _goRow == _row)
		{
			if(_goColumn == 7)
			{
				for(int i = _column+1; i<_goColumn; i++)
					if(BoardFigures[_row][i] != "")
						return 0;
				if(rookCast[3] != 1)
				goto CASTLING_RIGHT;
			}
			else if(_goColumn == 0)
			{
				for(int i = _column-1; i>_goColumn; i--)
					if(BoardFigures[_row][i] != "")
						return 0;
				if(rookCast[2] != 1)
				goto CASTLING_LEFT;
			}
		}
		else if(BoardFigures[_row][_column][1] == 'B' && _row == 0 && _column == 4 && _goRow == _row)
		{
			if(_goColumn == 7)
			{
				for(int i = _column+1; i<_goColumn; i++)
					if(BoardFigures[_row][i] != "")
						return 0;
				if(rookCast[1] != 1)
				goto CASTLING_RIGHT;
			}
			else if(_goColumn == 0)
			{
				for(int i = _column-1; i>_goColumn; i--)
					if(BoardFigures[_row][i] != "")
						return 0;
				if(rookCast[0] != 1)
				goto CASTLING_LEFT;
			}
		}
	}
	return 0;
	CASTLING_LEFT:
		BoardFigures[_row][_column-2] = BoardFigures[_row][_column];
		BoardFigures[_goRow][_goColumn+3] = BoardFigures[_goRow][_goColumn];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_goRow][_goColumn] = " ";
		BoardFigures[_row][_column] = "";
		BoardFigures[_goRow][_goColumn] = "";
		return 1;
	CASTLING_RIGHT:
		BoardFigures[_row][_column+2] = BoardFigures[_row][_column];
		BoardFigures[_goRow][_goColumn-2] = BoardFigures[_goRow][_goColumn];
		BoardFigures[_row][_column] = " ";
		BoardFigures[_goRow][_goColumn] = " ";
		BoardFigures[_row][_column] = "";
		BoardFigures[_goRow][_goColumn] = "";
		return 1;
}

int Figures::ChessMove()
{
	GoRowCh = rGoRow;
	GoColumnCh = rGoColumn;
	VicCh = rVictim;
	RowCh = rRow;
	ColumnCh = rColumn;
	AttCh = rAttacker;
					
	int Iremember = 0;
	int Jremember = 0;
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(player == 0 && BoardFigures[i][j] == "KW" || player == 1 && BoardFigures[i][j] == "KB")
			{
				Iremember = i;
				Jremember = j;
			}
		}
	}	
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if((this->player == 0 && BoardFigures[i][j][1] == 'B' || this->player == 1 && BoardFigures[i][j][1] == 'W') && BoardFigures[i][j] != "")
			{
				if(RelocationFigura(i,j,Iremember,Jremember) == 1)
				{
					UnRelocationFig();
					return 1;
				}
			}
		}
	}
	return 0;	
}

int Figures::Checkmate()
{
	int rowViCheck = rGoRow;
    int colViCheck = rGoColumn;
    int rowAtCheck = rRow;
    int colAtCheck = rColumn;
    
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(RelocationFigura(i,j,rowAtCheck,colAtCheck) == 1)
			{
				if(ChessMove() == 0)
				{
					UnRelocationFig();
					return 0;
				}
				UnRelocationFig(i,j,rowAtCheck,colAtCheck);
			}
		}
	}

	for(int row = 0; row<8; row++)
	{
		for(int column = 0; column<8; column++)
		{
			if(BoardFigures[row][column] != "" && BoardFigures[row][column][1] == BoardFigures[rowViCheck][colViCheck][1])
			{
				if(rowViCheck == rowAtCheck)
				{
					if(colViCheck > colAtCheck)
					{
						for(int i = colViCheck-1; i>colAtCheck; i--)
						{
							if(RelocationFigura(row,column,rowAtCheck,i) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,rowAtCheck,i);
							}
						}
					}
					else if(colViCheck < colAtCheck)
					{
						for(int i = colViCheck+1; i<colAtCheck; i++)
						{
							if(RelocationFigura(row,column,rowAtCheck,i) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,rowAtCheck,i);
							}
						}
					}
				}
				else if(colViCheck == colAtCheck)
				{
					if(rowViCheck > rowAtCheck)
					{
						for(int i = rowViCheck-1; i>rowAtCheck; i--)
						{
							if(RelocationFigura(row,column,colAtCheck,i) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,colAtCheck,i);
							}
						}
					}
					else if(rowViCheck < rowAtCheck)
					{
						for(int i = rowViCheck+1; i<rowAtCheck; i++)
						{
							if(RelocationFigura(row,column,colAtCheck,i) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,colAtCheck,i);
							}
						}
					}
				}
				else if(rowViCheck >  rowAtCheck && colViCheck != colAtCheck)
				{
					if(colViCheck > colAtCheck)
					{
						for(int i = rowViCheck-1, j = colViCheck-1; i>rowAtCheck,j>colAtCheck; i--,j--)
						{
							if(RelocationFigura(row,column,i,j) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,i,j);
							}
						}
					}
					else if(colViCheck < colAtCheck)
					{
						for(int i = rowViCheck-1, j = colViCheck+1; i>rowAtCheck,j<colAtCheck; i--,j++)
						{
							if(RelocationFigura(row,column,i,j) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,i,j);
							}
						}
					}
				}
				else if(rowViCheck < rowAtCheck && colViCheck != colAtCheck)
				{
					if(colViCheck > colAtCheck)
					{
						for(int i = rowViCheck+1, j = colViCheck-1; i<rowAtCheck,j>colAtCheck; i++,j--)
						{
							if(RelocationFigura(row,column,i,j) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,i,j);
							}
						}
					}
					else if(colViCheck < colAtCheck)
					{
						for(int i = rowViCheck+1, j = colViCheck+1; i<rowAtCheck,j<colAtCheck; i++,j++)
						{
							if(RelocationFigura(row,column,i,j) == 1)
							{
								if(ChessMove() == 0)
								{
									UnRelocationFig();
									return 0;
								}
								UnRelocationFig(row,column,i,j);
							}
						}
					}
				}
			}
		}
	}
	
	for(int i = -1; i<2; i++)
	{
		for(int j = -1; j<2; j++)
		{
			if(rowViCheck+i >= 0 && rowViCheck+i <= 7 && colViCheck+j >= 0 && colViCheck+j <= 7)
			{
				if(RelocationFigura(rowViCheck,colViCheck,rowViCheck+i,colViCheck+j) == 1)
				{
					if(ChessMove() == 0)
					{
						UnRelocationFig();
						return 0;
					}
					UnRelocationFig(rowViCheck,colViCheck,rowViCheck+i,colViCheck+j);
				}
			}
		}
	}
	return 1;
}
	
Figures::~Figures()
{
};
