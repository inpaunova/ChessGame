#include "Board.h"

void Board::setGameBoard()
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

void Board::setPawnsOnFields()
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		fields[x][1].setFigureAndColor(new Pawn(), WHITE);
		fields[x][6].setFigureAndColor(new Pawn(), BLACK);
	}
}

void Board::setEmptyFields()
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 2; y < 6; y++)
		{
			fields[x][y].setFigureAndColor(nullptr, NONE);
		}
	}
}

void Board::setFieldCoordinates()
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			fields[x][y].setXcoordinate(x);
			fields[x][y].setYcoordinate(y);
		}
	}
}

void Board::printGameBoard()
{
	cout << "   y: 0  1  2  3  4  5  6  7 " << "\n" << "x:" << "\n";
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		cout << " " << x << "   ";
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			Figure* figure = fields[x][y].getFigure();
			Colors fieldColor = fields[x][y].getColor();
			printFigure(figure, fieldColor);
		}
		cout << "\n";
	}
}

void Board::printFigure(Figure* figure, Colors fieldColor)
{
	if (figure)
	{
		figure->printAsLetter(fieldColor);
	}
	else
	{
		cout << " " << "\21" << " ";
	}
}

Colors ** Board::takeCurrentColorsOfBoard()
{
	Colors **fieldsColors = new Colors*[BOARD_SIZE];
	for (int i = 0; i < 8; i++)
	{
		fieldsColors[i] = new Colors[8];
	}

	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			fieldsColors[x][y] = fields[x][y].getColor();
		}
	}

	return fieldsColors;
}

bool Board::isCoordinateInBoundsOfBoard(int coordinate)
{
	const int smallestCoordinate = 0;
	const int largestCoordinate = 7;

	if (coordinate < smallestCoordinate || coordinate > largestCoordinate)
	{
		return false;
	}

	return true;
}

Field * Board::getField(int x, int y)
{
	return &fields[x][y];
}

void Board::setField(Field *field, int x, int y)
{
	fields[x][y] = *field;
}

int Board::getSize()
{
	return BOARD_SIZE;
}
