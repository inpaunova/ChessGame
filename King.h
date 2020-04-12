#pragma once
#include "Figure.h"

class King : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " K " : cout << " k ";
	}

	virtual bool canMoveFigure(Color ** fieldsColors, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		if (abs(destinationX - sourceX) == 1)
		{
			if (abs(destinationY - sourceY) == 1)
			{
				return true;
			}
			else return false;
		}
		return false;
	}

	virtual bool isKing()
	{
		return true;
	}
};