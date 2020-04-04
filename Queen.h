#pragma once
#include "Figure.h"

class Queen : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " Q " : cout << " q ";
	}
};