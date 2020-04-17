#pragma once
#include "Figure.h"

class King : public Figure
{
	bool canMoveHorizontally(sourceX, sourceY, destinationX, destinationY)
	{
		if (sourceX == destinationX)
		{
			if (abs(destinationY - sourceY) == 1)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveVertically(sourceX, sourceY, destinationX, destinationY)
	{
		if (sourceY == destinationY)
		{
			if (abs(destinationX - sourceX) == 1)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveDiagonally(sourceX, sourceY, destinationX, destinationY)
	{
		if (abs(destinationX - sourceX) == 1)
		{
			if (abs(abs(destinationY - sourceY) == 1) == 1)
			{
				return true;
			}
		}
		return false;
	}

public:
	virtual void printAsLetter(Color fieldColorOfFigure)
	{
		(fieldColorOfFigure == WHITE) ? cout << " K " : cout << " k ";
	}

	virtual bool canMove(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		if (canMoveHorizontally(sourceX, sourceY, destinationX, destinationY) ||
			canMoveVertically(sourceX, sourceY, destinationX, destinationY) ||
			canMoveVertically(sourceX, sourceY, destinationX, destinationY))
		{
			return true;
		}
		return false;
	}

	virtual bool isKing()
	{
		return true;
	}
};