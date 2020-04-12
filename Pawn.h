#pragma once
#include "Figure.h"

class Pawn : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " P " : cout << " p ";
	}

	virtual bool canMoveFigure(Color ** fieldsColors, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		if (fieldsColors[sourceX][sourceY] == WHITE)
		{
			if (sourceX == destinationX && destinationY == sourceY + 1 && fieldsColors[destinationX][destinationY] == NONE)
			{
				return true;
			}
			else if ((sourceX + 1 == destinationX || sourceX - 1 == destinationX) &&
				sourceY + 1 == destinationY && fieldsColors[destinationX][destinationY] == BLACK)
			{
				return true;
			}
			else
				return false;
		}
		else if (fieldsColors[sourceX][sourceY] == BLACK)
		{
			if (sourceX == destinationX && destinationY == sourceY - 1 && fieldsColors[destinationX][destinationY] == NONE)
			{
				return true;
			}
			else if ((sourceX + 1 == destinationX || sourceX - 1 == destinationX) &&
				sourceY - 1 == destinationY && fieldsColors[destinationX][destinationY] == WHITE)
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}

	virtual bool isKing()
	{
		return false;
	}
};