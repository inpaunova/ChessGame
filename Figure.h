#pragma once

enum Color { WHITE, BLACK, NONE };

class Figure
{
public:
	virtual void printAsLetter(Color fieldColor) = 0;
	virtual bool canMove(Color ** fieldsColors, int sourceX, int sourceY, int destinationX, int destinationY) = 0;
	virtual bool isKing() = 0;
};