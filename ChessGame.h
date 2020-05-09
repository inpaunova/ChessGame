#pragma once
#include "Board.h"

class ChessGame
{
public:
	ChessGame()
	{
		isGamePlaying = true;
		colorAtTheMoment = WHITE;
	}

	void play();
	void playNextTurn();
	void makeOneMove();

private:
	Board board;
	Colors colorAtTheMoment;
	bool isGamePlaying;

	string getUserInput();
	bool isPlayerFigure(int, int);
	bool canMakeMove(int, int, int, int);
	void moveFigure(int, int, int, int);
	void switchColorAtTheMoment();
	bool canMoveFigure(Field*, Field*);
	bool isGameEnd(int, int, int, int);
};


