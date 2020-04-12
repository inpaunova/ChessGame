#pragma once
#include "Figure.h"

class Rook : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " R " : cout << " r ";
	}

	bool canMoveFigure(Color** fieldsColors, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)

		if (sourceX != destinationX || sourceY != destinationY)
		{
			if (sourceX == destinationX)
			{
				int yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));
				for (int i = sourceY + yIncrement; i != destinationY; i += yIncrement)
				{
					if (fieldsColors[destinationX][i] != NONE)
						return false;
				}
			}
			else if (sourceY == destinationY)
			{
				int xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
				for (int i = sourceX + xIncrement; i != destinationX; i += xIncrement)
				{
					if (fieldsColors[i][destinationY] != NONE)
						return false;
				}
			}
			else
				return false;
		}

		return true;
	}

	virtual bool isKing()
	{
		return false;
	}
};