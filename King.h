#pragma once
#include "Figure.h"

class King : public Figure
{
public:
	virtual bool canMove(int sourceX, int sourceY, int destinationX, int destinationY)
	{

		if (canMoveHorizontally(sourceX, sourceY, destinationX, destinationY) ||
			canMoveVertically(sourceX, sourceY, destinationX, destinationY) ||
			canMoveDiagonally(sourceX, sourceY, destinationX, destinationY))
		{
			return true;
		}
		return false;
	}

	virtual void printAsLetter(Colors colorOfTheFigure)
	{
		(colorOfTheFigure == WHITE) ? cout << " K " : cout << " k ";
	}

	virtual bool isKing()
	{
		return true;
	}

private:
	bool canMoveHorizontally(int sourceX, int sourceY, int destinationX, int destinationY)
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

	bool canMoveVertically(int sourceX, int sourceY, int destinationX, int destinationY)
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

	bool canMoveDiagonally(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (abs(destinationX - sourceX) == 1)
		{
			if (abs(destinationY - sourceY) == 1)
			{
				return true;
			}
		}
		return false;
	}
};