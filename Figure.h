#pragma once

enum Colors { WHITE, BLACK, NONE };

class Figure
{
public:
	virtual void printAsLetter(Colors fieldColorOfFigure) = 0;
	virtual bool canMove(Colors ** fieldsColorsOfFiguresOnBoard, int sourceX, int sourceY, int destinationX, int destinationY) = 0;
	virtual bool isKing() = 0;
};