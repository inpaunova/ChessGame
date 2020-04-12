#pragma once
#include "Figure.h"

class Queen : public Figure
{
public:
	virtual void printAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " Q " : cout << " q ";
	}
	virtual bool canMove(Color ** fieldsColors, int sourceX, int sourceY, int destinationX, int destinationY)
	{
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		int yIncrement;
		int xIncrement;
		if (sourceX != destinationX || sourceY != destinationY)
		{
			if (sourceX == destinationX)
			{
				yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));
				for (int i = sourceY + yIncrement; i != destinationY; i += yIncrement)
				{
					if (fieldsColors[destinationX][i] != NONE)
						return false;
				}
			}
			else if (sourceY == destinationY)
			{
				xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
				for (int i = sourceX + xIncrement; i != destinationX; i += xIncrement)
				{
					if (fieldsColors[i][destinationY] != NONE)
						return false;
				}
			}
			else if (abs(sourceX - destinationX) == abs(sourceY - destinationY))
			{
				xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
				yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));
				for (int i = 1; i < abs(sourceX - destinationX); i++)
				{
					std::cout << "It got here somehow";
					if (fieldsColors[sourceX + xIncrement * i][sourceY + yIncrement * i] != NONE)
						return false;
				}
			}
			else
				return false;

		}
		return true;
	}

	virtual bool isKing()
	{
		return false;
	}
};