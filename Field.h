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

public:
	Field()
	{
		figure = nullptr;
		color = NONE;
		xCoordinate = -1;
		yCoordinate = -1;
	}

	void setFigureAndColor(Figure* figure, Color color)
	{
		this->figure = figure;
		this->color = color;
	}

	void setXcoordinate(int xCoordinate)
	{
		this->xCoordinate = xCoordinate;
	}

	void setYcoordinate(int yCoordinate)
	{
		this->yCoordinate = yCoordinate;
	}

	void setEmptyField()
	{
		color = NONE;
		figure = nullptr;
	}

	void setField(Field* field)
	{
		color = field->getColor();
		figure = field->getFigure();
	}

	Colors getColor()
	{
		return color;
	}

	Figure* getFigure()
	{
		return figure;
	}

	int getXCoordinate()
	{
		return xCoordinate;
	}

	int getYCoordinate()
	{
		return yCoordinate;
	}

private:
	Figure* figure;
	Colors color;
	int xCoordinate, yCoordinate;

};