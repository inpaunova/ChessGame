#include "ChessGame.h"

using namespace std;

void ChessGame::printFigure(Figure* figure, Color fieldColor)
{
	if (!figure)
	{
		cout << " " << "\21" << " ";
	}
	else
	{
		figure->printAsLetter(fieldColor);
	}
}

void ChessGame::printGameBoard() {

	cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
		{
			Figure* figure = fields[i][j].getFigure();
			Color fieldColor = fields[i][j].getColor();
			printFigure(figure, fieldColor);
		}
		cout << endl;
	}

}

string ChessGame::getUserInput()
{
	string coordinatesOfMoving;
	(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
	cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
	cin >> coordinatesOfMoving;
	return coordinatesOfMoving;
}

Color ** ChessGame::takeCurrentColorsOfBoard()
{
	Color **fieldsColors = new Color*[8];
	for (int i = 0; i < 8; i++)
	{
		fieldsColors[i] = new Color[8];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			fieldsColors[i][j] = fields[i][j].getColor();
		}
	}

	return fieldsColors;
}

void ChessGame::switchColorAtTheMoment()
{
	if (colorAtTheMoment == BLACK)
		colorAtTheMoment = WHITE;
	else
		colorAtTheMoment = BLACK;
}


bool ChessGame::isCoordinateInBoundsOfBoard(int coordinate)
{
	if (coordinate < 0 || coordinate > 7)
		return false;

	return true;
}

bool ChessGame::isGameEnd(int sourceX, int sourceY, int destinationX, int destinationY)
{
	if (getField(destinationX, destinationY)->getFigure()->isKing())
	{
		if (getField(sourceX, sourceY)->getColor() == WHITE)
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



bool ChessGame::canMoveFigure(Field * source, Field * destination)
{
	Color ** fieldsColors = takeCurrentColorsOfBoard();
	bool canMoveCurrentFigure = source->getFigure()->canMove(fieldsColors, 
		source->getX(), source->getY(), destination->getX(), destination->getY());
	for (int i = 0; i < 8; i++)
	{
		delete fieldsColors[i];
	}
	delete[] fieldsColors;
	return canMoveCurrentFigure;
}

bool ChessGame::canMakeMove(int sourceX, int sourceY, int destinationX, int destinationY)
{
	//Checking for turns will be done previous to this
	if (!isCoordinateInBoundsOfBoard(sourceX) || !isCoordinateInBoundsOfBoard(sourceY) || !isCoordinateInBoundsOfBoard(destinationX) ||
		!isCoordinateInBoundsOfBoard(destinationY))
	{
		cout << "One of your inputs was our of bounds" << endl;
		return false;
	}
	Field* source = getField(sourceX, sourceY);
	Field* destination = getField(destinationX, destinationY);

	if (source->getColor() == destination->getColor() && destination->getColor() != NONE)
	{
		cout << "Invalid move: cannot land on your own field" << endl;
		return false;
	}

	return source->getFigure()->canMoveFigure(source, destination);
}

void ChessGame::setGameBoard()
{
	fields[0][0].setFigureAndColor(new Rook(), WHITE);
	fields[1][0].setFigureAndColor(new Knight(), WHITE);
	fields[2][0].setFigureAndColor(new Bishop(), WHITE);
	fields[3][0].setFigureAndColor(new Queen(), WHITE);
	fields[4][0].setFigureAndColor(new King(), WHITE);
	fields[5][0].setFigureAndColor(new Bishop(), WHITE);
	fields[6][0].setFigureAndColor(new Knight(), WHITE);
	fields[7][0].setFigureAndColor(new Rook(), WHITE);

	fields[0][7].setFigureAndColor(new Rook(), BLACK);
	fields[1][7].setFigureAndColor(new Knight(), BLACK);
	fields[2][7].setFigureAndColor(new Bishop(), BLACK);
	fields[3][7].setFigureAndColor(new Queen, BLACK);
	fields[4][7].setFigureAndColor(new King(), BLACK);
	fields[5][7].setFigureAndColor(new Bishop(), BLACK);
	fields[6][7].setFigureAndColor(new Knight(), BLACK);
	fields[7][7].setFigureAndColor(new Rook(), BLACK);

	for (int i = 0; i < 8; i++)
	{
		fields[i][1].setFigureAndColor(new Pawn(), WHITE);
		fields[i][6].setFigureAndColor(new Pawn(), BLACK);
	}

	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			fields[j][i].setFigureAndColor(nullptr, NONE);
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			fields[i][j].setX(i);
			fields[i][j].setY(j);
		}
}

void ChessGame::moveFigure()
{
	string coordinatesOfMoving;
	int sourceX, sourceY, destinationX, destinationY;
	bool doesGameStop = false;
	while (!doesGameStop)
	{
		coordinatesOfMoving = getUserInput();

		sourceX = coordinatesOfMoving[0] - 48;
		sourceY = coordinatesOfMoving[1] - 48;
		destinationX = coordinatesOfMoving[2] - 48;
		destinationY = coordinatesOfMoving[3] - 48;

		if (getField(sourceX, sourceY)->getColor() == colorAtTheMoment)
		{
			if (!canMakeMove(sourceX, sourceY, destinationX, destinationY))
			{
				cout << "Invalid move, try again." << endl;
			}
			else
			{
				Field* source = getField(sourceX, sourceY);
				Field* destination = getField(destinationX, destinationY);
				destination->setField(source);
				source->setEmptyField();
				doesGameStop = true;
			}

		}
		else
			cout << "That's not your piece. Try again." << endl;
	}
	if (isGameEnd(sourceX, sourceY, destinationX, destinationY))
	{
		isGamePlaying = false;
		return;
	}
	switchColorAtTheMoment();
}

void ChessGame::playNextTurn()
{
	system("cls");
	printGameBoard();
	moveFigure();
}
