#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
	virtual bool canMove(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (canMoveDiagonally(sourceX, sourceY, destinationX, destinationY))
			return true;
		else
			return false;
	}

	virtual void printAsLetter(Colors colorOfTheFigure) override
	{
		(colorOfTheFigure == WHITE) ? cout << " B " : cout << " b ";
	}
	
	virtual bool isKing()
	{
		return false;
	}

private:
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
