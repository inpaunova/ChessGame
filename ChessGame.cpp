#include "ChessGame.h"
using namespace std;

void ChessGame::play()
{
	bool wantNewGame = true;
	string yesNoAnswer;
	while (wantNewGame)
	{
		board.setGameBoard();

		while (isGamePlaying)
		{
			playNextTurn();
		}

		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> yesNoAnswer;
		if (yesNoAnswer != "y")
			wantNewGame = false;
	}
}

void ChessGame::playNextTurn()
{
	system("cls");
	board.printGameBoard();
	makeOneMove();
}

void ChessGame::makeOneMove()
{
	string coordinatesOfMoving;
	int sourceX, sourceY, destinationX, destinationY;
	bool isFigureMoved = false;

	while (!isFigureMoved)
	{
		coordinatesOfMoving = getUserInput();

		sourceX = coordinatesOfMoving[0] - '0';
		sourceY = coordinatesOfMoving[1] - '0';
		destinationX = coordinatesOfMoving[2] - '0';
		destinationY = coordinatesOfMoving[3] - '0';

		if (isPlayerFigure(sourceX, sourceY))
		{
			if (!canMakeMove(sourceX, sourceY, destinationX, destinationY))
			{
				cout << "Invalid move, try again." << "\n";
			}
			else
			{
				moveFigure(sourceX, sourceY, destinationX, destinationY);
				isFigureMoved = true;
			}
		}
		else
			cout << "That's not your piece. Try again." << "\n";
	}
	
	switchColorAtTheMoment();
}

string ChessGame::getUserInput()
{
	string coordinatesOfMoving;

	(colorAtTheMoment == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
	cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;

	cin >> coordinatesOfMoving;

	return coordinatesOfMoving;
}

bool ChessGame::isPlayerFigure(int x, int y)
{
	return board.getField(x, y)->getColor() == colorAtTheMoment;
}

bool ChessGame::canMakeMove(int sourceX, int sourceY, int destinationX, int destinationY)
{
	if (!board.isCoordinateInBoundsOfBoard(sourceX) ||
		!board.isCoordinateInBoundsOfBoard(sourceY) ||
		!board.isCoordinateInBoundsOfBoard(destinationX) ||
		!board.isCoordinateInBoundsOfBoard(destinationY))
	{
		cout << "One of your inputs was our of bounds" << endl;
		return false;
	}

	Field* source = board.getField(sourceX, sourceY);
	Field* destination = board.getField(destinationX, destinationY);

	if (source->getColor() == destination->getColor() && destination->getColor() != NONE)
	{
		cout << "Invalid move: cannot land on your own field" << endl;
		return false;
	}

	return canMoveFigure(source, destination);
}

void ChessGame::moveFigure(int sourceX, int sourceY, int destinationX, int destinationY)
{
	if (isGameEnd(sourceX, sourceY, destinationX, destinationY))
	{
		isGamePlaying = false;
		return;
	}

	Field* source = board.getField(sourceX, sourceY);
	Field* destination = board.getField(destinationX, destinationY);
	destination->setField(source);
	source->setEmptyField();
}

void ChessGame::switchColorAtTheMoment()
{
	if (colorAtTheMoment == BLACK)
		colorAtTheMoment = WHITE;
	else
		colorAtTheMoment = BLACK;
}

bool ChessGame::canMoveFigure(Field * source, Field * destination)
{
	Colors ** fieldsColors = board.takeCurrentColorsOfBoard();

	source->getFigure()->setColorOfFiguresOnTheBoard(fieldsColors);

	bool canMoveCurrentFigure = source->getFigure()->canMove(source->getXcoordinate(),
		source->getYcoordinate(), destination->getXcoordinate(), destination->getYcoordinate());

	for (int i = 0; i < board.getSize(); i++)
	{
		delete fieldsColors[i];
	}
	delete[] fieldsColors;

	return canMoveCurrentFigure;
}

bool ChessGame::isGameEnd(int sourceX, int sourceY, int destinationX, int destinationY)
{
	if (board.hasFigureOnField(destinationX, destinationY) &&
		board.hasKingOnField(destinationX, destinationY))
	{
		if (board.getField(sourceX, sourceY)->getColor() == WHITE)
		{
			cout << "WHITE WINS" << endl;
			return true;
		}
		else
		{
			cout << "BLACK WINS" << endl;
			return true;
		}
	}

	return false;
}
















