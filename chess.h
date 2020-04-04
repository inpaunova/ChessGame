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

class Board
{
	Field ** board;
	bool isGamePlaying;
	Color colorAtTheMoment;

	void printFigure(Figure*, Color);
	void printGameBoard();
	string getUserInput();
	void switchColorAtTheMoment();
	bool isCoordinateInBoundsOfBoard(int);
	bool isGameEnd(int, int, int, int);
	bool canMoveKing(Field*, Field*);
	bool canMoveQueen(Field*, Field*);
	bool canMoveRook(Field*, Field*);
	bool canMoveBishop(Field*, Field*);
	bool canMoveKnight(Field*, Field*);
	bool canMovePawn(Field*, Field*);
	bool canMakeMove(int, int, int, int);

	
public:
	ChessGame()
	{
		isGamePlaying = true;
		colorAtTheMoment = WHITE;
		board = new Field*[8];
		for (int i = 0; i < 8; i++)
		{
			board[i] = new Field[8];
		}

	}
	
	Field* getField(int x, int y) 
	{
		return &board[x][y];
	}

	void setField(Field * field, int x, int y) 
	{
		board[x][y] = *field;
	}
	
	~ChessGame()
	{

		for (int i = 0; i < 8; i++)
		{
			delete board[i];
		}
		delete[] board;
	}

	void setGameBoard();
	void moveFigure();
	void playNextTurn();
};

