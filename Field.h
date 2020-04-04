#pragma once
#include<iostream>
#include <cmath>
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