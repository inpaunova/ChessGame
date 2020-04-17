#pragma once
#include "Figure.h"

class Queen : public Figure
{
	bool canMoveHorizontally(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (sourceX == destinationX && sourceY != destinationY)
		{
			int moveStep = (destinationY - sourceY) / (abs(destinationY - sourceY));
			for (int i = sourceY + moveStep; i != destinationY; i += moveStep)
			{
				if (fieldsColorsOfFiguresOnBoard[destinationX][i] != NONE)
					return false;
			}
			return true;
		}
		return false;
	}

	bool canMoveVertically(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		if (sourceX != destinationY && sourceY == destinationY)
		{
			int moveStep = (destinationX - sourceX) / (abs(destinationX - sourceX));
			for (int i = sourceX + moveStep; i != destinationX; i += moveStep)
			{
				if (fieldsColorsOfFiguresOnBoard[i][destinationY] != NONE)
					return false;
			}
			return true;
		}
		return false;
	}

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
	virtual void printAsLetter(Color fieldColorOfFigure)
	{
		(fieldColorOfFIgure == WHITE) ? cout << " Q " : cout << " q ";
	}
	virtual bool canMove(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		if (canMoveHorizontally(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY) ||
			canMoveVertically(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY) ||
			canMoveVertically(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY))
		{
			return true;
		}
		return false;
	}

	virtual bool isKing()
	{
		return false;
	}
};