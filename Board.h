#pragma once
#include "Field.h"

class Board
{
public:
	void setGameBoard();
	void printGameBoard();

	Colors** takeCurrentColorsOfBoard();

	bool isCoordinateInBoundsOfBoard(int);

	Field* getField(int, int);
	void setField(Field *, int, int);
	int getSize();

private:
	static const int BOARD_SIZE = 8;
	Field fields[BOARD_SIZE][BOARD_SIZE];

	void setPawnsOnFields();
	void setEmptyFields();
	void setFieldCoordinates();

	void printFigure(Figure*, Colors);
};