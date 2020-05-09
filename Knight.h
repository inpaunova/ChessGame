#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
	virtual bool canMove(int sourceX, int sourceY, int destinationX, int destinationY)
	{
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

	virtual void printAsLetter(Colors colorOfTheFigure)
	{
		(colorOfTheFigure == WHITE) ? cout << " H " : cout << " h ";
	}
	
	virtual bool isKing()
	{
		return false;
	}
};