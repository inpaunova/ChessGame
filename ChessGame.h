#pragma once
#include "Board.h"

class ChessGame
{
public:
	Board board;
	bool isGamePlaying;
	
	ChessGame()
	{
		isGamePlaying = true;
		colorAtTheMoment = WHITE;
	}

	void moveFigure();
	void playNextTurn();
	
private:
	Colors colorAtTheMoment;

	string getUserInput();

	void switchColorAtTheMoment();
	bool isGameEnd(int, int, int, int);
	bool canMakeMove(int, int, int, int);
	bool canMoveFigure(Field*, Field*);
	
};



