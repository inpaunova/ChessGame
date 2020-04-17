#pragma once
#include "Figure.h"

class Knight : public Figure
{
	
public:
	virtual void printAsLetter(Color fieldColorOfFigure)
	{
		(fieldColorOfFigure == WHITE) ? cout << " H " : cout << " h ";
	}

	virtual bool canMove(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)

		bool ifDifferenceByXIsTwo = abs(sourceX - destinationX) == 2;
		bool ifDifferenceByYIsTwo = abs(sourceY - destinationY) == 2;
		bool ifDifferenceByXIsOne = abs(sourceX - destinationX) == 1;
		bool ifDifferenceByYIsOne = abs(sourceY - destinationY) == 1;

		bool canMoveHorizontally = ifDifferenceByXIsOne && ifDifferenceByYIsTwo;
		bool canMoveVertically = ifDifferenceByXIsTwo && ifDifferenceByYIsOne;

		if (canMoveHorizontally || canMoveVertically)
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