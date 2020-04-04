#pragma once

enum Color { WHITE, BLACK, NONE };

class Figure
{
public:
	virtual void printFigureAsLetter(Color fieldColor) = 0;
};