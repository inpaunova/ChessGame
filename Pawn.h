#pragma once
#include "Figure.h"

class Pawn : public Figure
{
	bool canMoveWhitePawnHorizontally(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		
		bool ifXCoordinatesMatch = sourceX == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY + 1;
		bool isdestinationFieldEmpty = fieldsColorsOfFiguresOnBoard[destinationX][destinationY] == NONE;

		if (fieldsColorsOfFiguresOnBoard[sourceX][sourceY] == WHITE)
		{
			if (ifXCoordinatesMatch && areYCoordinatesAdjacent && isdestinationFieldEmpty)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveBlackPawnHorizontally(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{

		bool ifXCoordinatesMatch = sourceX == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY - 1;
		bool isdestinationFieldEmpty = fieldsColorsOfFiguresOnBoard[destinationX][destinationY] == NONE;

		if (fieldsColorsOfFiguresOnBoard[sourceX][sourceY] == BLACK)
		{
			if (ifXCoordinatesMatch && areYCoordinatesAdjacent && isdestinationFieldEmpty)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveWhitePawnDiagonally(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		bool areXCoordinatesAdjacent = sourceX + 1 == destinationX || sourceX - 1 == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY + 1;
		bool isDestinationFieldBlack = fieldsColors[destinationX][destinationY] == BLACK;
		if (fieldsColorsOfFiguresOnBoard[sourceX][sourceY] == WHITE)
		{
			if (areXCoordinatesAdjacent && areYCoordinatesAdjacent && isDestinationFieldBlack)
			{
				return true;
			}
		}
		return false;
	}

	bool canMoveBlackPawnDiagonally(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		bool areXCoordinatesAdjacent = sourceX + 1 == destinationX || sourceX - 1 == destinationX;
		bool areYCoordinatesAdjacent = destinationY == sourceY - 1;
		bool isDestinationFieldWhite = fieldsColors[destinationX][destinationY] == WHITE;
		if (fieldsColorsOfFiguresOnBoard[sourceX][sourceY] == WHITE)
		{
			if (areXCoordinatesAdjacent && areYCoordinatesAdjacent && isDestinationFieldWhite)
			{
				return true;
			}
		}
		return false;
	}

public:
	virtual void printAsLetter(Color fieldColorOfFigure)
	{
		(fieldColorOfFigure == WHITE) ? cout << " P " : cout << " p ";
	}

	virtual bool canMove(Color ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		bool canMoveHorizontally = canMoveWhitePawnHorizontally(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY) ||
			                       canMoveBlackPawnHorizontally(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY);

		bool canMoveDiagonally = canMoveWhitePawnDiagonally(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY) ||
			                     canMoveBlackPawnDiagonally(fieldsColorsOfFiguresOnBoard, sourceX, sourceY, destinationX, destinationY);

		if (canMoveHorizontally || canMoveDiagonally)
			return true;
		else 
			return false;
	}
	

	virtual bool isKing()
	{
		return false;
	}
};