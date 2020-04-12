#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " H " : cout << " h ";
	}

	virtual bool canMoveFigure(Color ** fieldsColors, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		if ((abs(sourceX - destinationX) == 2 && abs(sourceY - destinationY) == 1) ||
			(abs(sourceX - destinationX) == 1 && abs(sourceY - destinationY) == 2))
		{
			return true;
		}
		else
			return false;
	}

	virtual bool isKing()
	{
		return false;
	}
};