#pragma once
#include "Figure.h"

class Pawn : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " P " : cout << " p ";
	}
};