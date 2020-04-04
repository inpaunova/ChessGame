#pragma once
#include<iostream>
#include "Figure.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"

class Field
{
	Figure* figure;
	Color color;
	int x, y;
public:
	Field()
	{
		figure = nullptr;
		color = NONE;
	}

	void setField(Field* field)
	{
		color = field->getColor();
		figure = field->getFigure();
	}

	void setEmptyField()
	{
		color = NONE;
		figure = nullptr;
	}

	void setFigureAndColor(Figure* figure, Color color)
	{
		this->figure = figure;
		this->color = color;
	}

	Color getColor()
	{
		return color;
	}

	Figure* getFigure()
	{
		return figure;
	}

	void setX(int x)
	{
		this->x = x;
	}

	void setY(int y)
	{
		this->y = y;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}
};

class Board
{
	Field square[8][8];
	Color turn = WHITE;

	bool moveKing(Square* thisKing, Square* thatSpace);
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool moveRook(Square* thisRook, Square* thatSpace);
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();

	void printFigure(Figure*, Color);
public:
	Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	void setSquare(Square * s, int x, int y) {
		square[x][y] = *s;
	}
	bool doMove();

	void setBoard();
	bool playGame();
};

