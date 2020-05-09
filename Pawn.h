#pragma once
#include "Figure.h"

class Pawn : public Figure
{
public:
	virtual bool canMove(int sourceX, int sourceY, int destinationX, int destinationY)
	{

		bool canMoveHorizontally = canMoveWhitePawnHorizontally(sourceX, sourceY, destinationX, destinationY) ||
			canMoveBlackPawnHorizontally(sourceX, sourceY, destinationX, destinationY);

		bool canMoveDiagonally = canMoveWhitePawnDiagonally(sourceX, sourceY, destinationX, destinationY) ||
			canMoveBlackPawnDiagonally(sourceX, sourceY, destinationX, destinationY);

		if (canMoveHorizontally || canMoveDiagonally)
			return true;
		else
			return false;
	}

	virtual void printAsLetter(Colors colorOfTheFigure)
	{
		(colorOfTheFigure == WHITE) ? cout << " P " : cout << " p ";
	}

	virtual bool isKing()
	{
		return false;
	}

private:
	bool canMoveWhitePawnHorizontally(int sourceX, int sourceY, int destinationX, int destinationY)
	{

		bool ifXCoordinatesMatch = sourceX == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY + 1;
		bool isdestinationFieldEmpty = colorsOfBoardFigures[destinationX][destinationY] == NONE;

		if (colorsOfBoardFigures[sourceX][sourceY] == WHITE)
		{
			if (ifXCoordinatesMatch && areYCoordinatesAdjacent && isdestinationFieldEmpty)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveBlackPawnHorizontally(int sourceX, int sourceY, int destinationX, int destinationY)
	{

		bool ifXCoordinatesMatch = sourceX == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY - 1;
		bool isdestinationFieldEmpty = colorsOfBoardFigures[destinationX][destinationY] == NONE;

		if (colorsOfBoardFigures[sourceX][sourceY] == BLACK)
		{
			if (ifXCoordinatesMatch && areYCoordinatesAdjacent && isdestinationFieldEmpty)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveWhitePawnDiagonally(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		bool areXCoordinatesAdjacent = sourceX + 1 == destinationX || sourceX - 1 == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY + 1;
		bool isDestinationFieldBlack = colorsOfBoardFigures[destinationX][destinationY] == BLACK;

		if (colorsOfBoardFigures[sourceX][sourceY] == WHITE)
		{
			if (areXCoordinatesAdjacent && areYCoordinatesAdjacent && isDestinationFieldBlack)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveBlackPawnDiagonally(int sourceX, int sourceY, int destinationX, int destinationY)
	{
		bool areXCoordinatesAdjacent = sourceX + 1 == destinationX || sourceX - 1 == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY - 1;
		bool isDestinationFieldWhite = colorsOfBoardFigures[destinationX][destinationY] == WHITE;

		if (colorsOfBoardFigures[sourceX][sourceY] == WHITE)
		{
			if (areXCoordinatesAdjacent && areYCoordinatesAdjacent && isDestinationFieldWhite)
			{
				return true;
			}
		}
		return false;
	}
};