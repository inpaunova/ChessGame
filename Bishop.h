#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor) override
	{
		(fieldColor == WHITE) ? cout << " B " : cout << " b ";
	}

	virtual bool canMoveFigure(Color ** fieldsColors, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		if (abs(sourceX - destinationX) == abs(sourceY - destinationY))
		{
			int xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
			int yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));

			for (int i = 1; i < abs(sourceX - destinationX); i++)
			{
				cout << "It got here somehow!";
				if (fieldsColors[sourceX + xIncrement * i][sourceY + yIncrement * i] != NONE)
					return false;

			}
		}
		else
			return false;

		return true;
	}

	virtual bool isKing()
	{
		return false;
	}
};