#pragma once
#include "Figure.h"

class Bishop : public Figure
{
	bool canMoveDiagonally(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (abs(sourceX - destinationX) == abs(sourceY - destinationY))
		{
			int moveStepByX = (destinationX - sourceX) / (abs(destinationX - sourceX));
			int moveStepByY = (destinationY - sourceY) / (abs(destinationY - sourceY));

			int xCoordinate, yCoordinate;
			for (int i = 1; i < abs(sourceX - destinationX); i++)
			{
				xCoordinate = sourceX + xIncrement * i;
				yCoordinate = sourceY + yIncrement * i;
				if (fieldsColorsOfFiguresOnBoard[xCoordinate][yCoordinate] != NONE)
					return false;
			}
			return true;
		}
		return false;
	}
public:
	virtual void printAsLetter(Color fieldColorOfFigure) override
	{
		(fieldColorOfFigure == WHITE) ? cout << " B " : cout << " b ";
	}

	virtual bool canMove(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		if (canMoveDiagonally(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY))
			return true;
		else
			return fale;
	}

	virtual bool isKing()
	{
		return false;
	}
};