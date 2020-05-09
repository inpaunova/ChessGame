#pragma once
#include "Figure.h"

class Rook : public Figure
{
public:
	bool canMove(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (canMoveHorizontally(sourceX, sourceY, destinationX, destinationY) ||
			canMoveVertically(sourceX, sourceY, destinationX, destinationY))
		{
			return true;
		}
		return false;
	}

	virtual void printAsLetter(Colors colorOfTheFigure)
	{
		(colorOfTheFigure == WHITE) ? cout << " R " : cout << " r ";
	}
	
	virtual bool isKing()
	{
		return false;
	}

private:
	bool canMoveHorizontally(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (sourceX == destinationX && sourceY != destinationY)
		{
			int moveStep = (destinationY - sourceY) / (abs(destinationY - sourceY));
			for (int y = sourceY + moveStep; y != destinationY; y += moveStep)
			{
				if (colorsOfBoardFigures[destinationX][y] != NONE)
					return false;
			}
			return true;
		}
		return false;
	}

	bool canMoveVertically(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (sourceX != destinationX && sourceY == destinationY)
		{
			int moveStep = (destinationX - sourceX) / (abs(destinationX - sourceX));
			for (int x = sourceX + moveStep; x != destinationX; x += moveStep)
			{
				if (colorsOfBoardFigures[x][destinationY] != NONE)
					return false;
			}
			return true;
		}
		return false;
	}
};