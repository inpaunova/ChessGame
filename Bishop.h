#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor) override
	{
		(fieldColor == WHITE) ? cout << " B " : cout << " b ";
	}
};