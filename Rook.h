#pragma once
#include "Figure.h"

class Rook : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " R " : cout << " r ";
	}
};