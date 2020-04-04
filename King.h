#pragma once
#include "Figure.h"

class King : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " K " : cout << " k ";
	}
};