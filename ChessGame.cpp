#include "ChessGame.h"

using namespace std;


void ChessGame::playNextTurn()
{
	system("cls");
	printGameBoard();
	moveFigure();
}

void ChessGame::moveFigure()
{
	string coordinatesOfMoving;
	int sourceX, sourceY, destinationX, destinationY;
	bool isFigureMoved = false;
	while (!isFigureMoved)
	{
		coordinatesOfMoving = getUserInput();

		sourceX = coordinatesOfMoving[0];
		sourceY = coordinatesOfMoving[1];
		destinationX = coordinatesOfMoving[2];
		destinationY = coordinatesOfMoving[3];

		if (board.getField(sourceX, sourceY)->getColor() == colorAtTheMoment)
		{
			if (!canMakeMove(sourceX, sourceY, destinationX, destinationY))
			{
				cout << "Invalid move, try again." << endl;
			}
			else
			{
				if (isGameEnd(sourceX, sourceY, destinationX, destinationY))
				{
					isGamePlaying = false;
					return;
				}
				Field* source = getField(sourceX, sourceY);
				Field* destination = getField(destinationX, destinationY);
				destination->setField(source);
				source->setEmptyField();
				isFigureMoved = true;
			}

		}
		else
			cout << "That's not your piece. Try again." << endl;
	}

	switchColorAtTheMoment();
}


string ChessGame::getUserInput()
{
	string coordinatesOfMoving;
	(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
	cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
	cin >> coordinatesOfMoving;
	return coordinatesOfMoving;
}

bool ChessGame::isGameEnd(int sourceX, int sourceY, int destinationX, int destinationY)
{
	if (board.getField(destinationX, destinationY)->getFigure() &&
		board.getField(destinationX, destinationY)->getFigure()->isKing())
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

void ChessGame::switchColorAtTheMoment()
{
	if (colorAtTheMoment == BLACK)
		colorAtTheMoment = WHITE;
	else
		colorAtTheMoment = BLACK;
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

bool ChessGame::canMoveFigure(Field * source, Field * destination)
{
	Colors ** fieldsColors = board.takeCurrentColorsOfBoard();
	source->getFigure()->setColorOfBoardFigures(fieldsColors);

	bool canMoveCurrentFigure = source->getFigure()->canMove(source->getXcoordinate(),
		source->getYcoordinate(), destination->getXcoordinate(), destination->getYcoordinate());

	for (int i = 0; i < board.getSize(); i++)
	{
		delete fieldsColors[i];
	}
	delete[] fieldsColors;

	return canMoveCurrentFigure;
}








