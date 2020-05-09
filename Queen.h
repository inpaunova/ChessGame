#pragma once
#include "Figure.h"

class Queen : public Figure
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
		(colorOfTheFigure == WHITE) ? cout << " Q " : cout << " q ";
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
		if (sourceX != destinationY && sourceY == destinationY)
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

	bool canMoveDiagonally(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (abs(sourceX - destinationX) == abs(sourceY - destinationY))
		{
			int moveStepByX = (destinationX - sourceX) / (abs(destinationX - sourceX));
			int moveStepByY = (destinationY - sourceY) / (abs(destinationY - sourceY));

			int xCoordinate, yCoordinate;
			for (int i = 1; i < abs(sourceX - destinationX); i++)
			{
				xCoordinate = sourceX + moveStepByX * i;
				yCoordinate = sourceY + moveStepByY * i;
				if (colorsOfBoardFigures[xCoordinate][yCoordinate] != NONE)
					return false;
			}
			return true;
		}
		return false;
	}
};