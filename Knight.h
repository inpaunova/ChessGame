#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor)
	{
		(fieldColor == WHITE) ? cout << " H " : cout << " h ";
	}
};