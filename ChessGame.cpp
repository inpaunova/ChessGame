#include "ChessGame.h"

using namespace std;

void ChessGame::setEmptyFields()
{
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			fields[j][i].setFigureAndColor(nullptr, NONE);
		}
	}
}

void ChessGame::setPawnsOnFields()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		fields[i][1].setFigureAndColor(new Pawn(), WHITE);
		fields[i][6].setFigureAndColor(new Pawn(), BLACK);
	}

}

void ChessGame::setFieldCoordinates()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			fields[i][j].setX(i);
			fields[i][j].setY(j);
		}
	}
}

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
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < BOARD_SIZE; j++)
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
	Color **fieldsColors = new Color*[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		fieldsColors[i] = new Color[BOARD_SIZE];
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
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
	const int SMALLEST_COORDINATE = 0;
	const int LARGEST_COORDINATE = 7;
	if (coordinate < SMALLEST_COORDINATE || coordinate > LARGEST_COORDINATE)
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
	Colors ** fieldsColors = takeCurrentColorsOfBoard();
	source->getFigure()->setColorOfBoardFigures(fieldsColors);

	bool canMoveCurrentFigure = source->getFigure()->canMove(source->getXcoordinate(),
		source->getYcoordinate(), destination->getXcoordinate(), destination->getYcoordinate());

	for (int i = 0; i < BOARD_SIZE; i++)
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

	setPawnsOnFields();
	setEmptyFields();
	setFieldCoordinates();
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

		if (getField(sourceX, sourceY)->getColor() == colorAtTheMoment)
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

void ChessGame::playNextTurn()
{
	system("cls");
	printGameBoard();
	moveFigure();
}
