#include "chess.h"

using namespace std;

void Board::printFigure(Figure* figure, Color fieldColor)
{
	if (!figure)
	{
		cout << " " << "\21" << " ";
	}
	else
	{
		figure->printFigureAsLetter(fieldColor);
	}
}

void Board::printGameBoard() {
	
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

string Board::getUserInput()
{
	string coordinatesOfMoving;
	(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
	cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
	cin >> coordinatesOfMoving;
	return coordinatesOfMoving;
}

void Board::switchColorAtTheMoment()
{
	if (colorAtTheMoment == BLACK)
		colorAtTheMoment = WHITE;
	else
		colorAtTheMoment = BLACK;
}

bool Board::isCoordinateInBoundsOfBoard(int coordinate)
{
	if (coordinate < 0 || coordinate > 7)
		return false;

	return true;
}

bool Board::isGameEnd(int sourceX, int sourceY, int destinationX, int destinationY)
{
	King * castToKing = dynamic_cast<King*>(getField(destinationX, destinationY)->getFigure());

	if (castToKing != nullptr)
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
	return false;
}

bool Board::canMoveKing(Field *source, Field * destination)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if (abs(destination->getX() - source->getX()) == 1)
	{
		if (abs(destination->getY() - source->getY()) == 1)
		{
			return true;
		}
		else return false;
	}
	return false;
}

bool Board::canMoveQueen(Field * source, Field * destination)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int yIncrement;
	int xIncrement;
	if (source->getX() != destination->getX() || source->getY() != destination->getY())
	{
		if (source->getX() == destination->getX())
		{
			yIncrement = (destination->getY() - source->getY()) / (abs(destination->getY() - source->getY()));
			for (int i = source->getY() + yIncrement; i != destination->getY(); i += yIncrement)
			{
				if (board[destination->getX()][i].getColor() != NONE)
					return false;
			}
		}
		else if (source->getY() == destination->getY())
		{
			xIncrement = (destination->getX() - source->getX()) / (abs(destination->getX() - source->getX()));
			for (int i = source->getX() + xIncrement; i != destination->getX(); i += xIncrement)
			{
				if (board[i][destination->getY()].getColor() != NONE)
					return false;
			}
		}
		else if (abs(source->getX() - destination->getX()) == abs(source->getY() - destination->getY()))
		{
			xIncrement = (destination->getX() - source->getX()) / (abs(destination->getX() - source->getX()));
			yIncrement = (destination->getY() - source->getY()) / (abs(destination->getY() - source->getY()));
			for (int i = 1; i < abs(source->getX() - destination->getX()); i++)
			{
				cout << "It got here somehow";
				if (board[source->getX() + xIncrement * i][source->getY() + yIncrement * i].getColor() != NONE)
					return false;
			}
		}
		else
			return false;
	}
	return true;
}

bool Board::canMoveRook(Field * source, Field * destination)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if (source->getX() != destination->getX() || source->getY() != destination->getY())
	{
		if (source->getX() == destination->getX())
		{
			int yIncrement = (destination->getY() - source->getY()) / (abs(destination->getY() - source->getY()));
			for (int i = source->getY() + yIncrement; i != destination->getY(); i += yIncrement)
			{

				if (board[destination->getX()][i].getColor() != NONE)
					return false;
			}
		}
		else if (source->getY() == destination->getY())
		{
			int xIncrement = (destination->getX() - source->getX()) / (abs(destination->getX() - source->getX()));
			for (int i = source->getX() + xIncrement; i != destination->getX(); i += xIncrement)
			{
				if (board[i][destination->getY()].getColor() != NONE)
					return false;
			}
		}
		else
			return false;
	}
	return true;
}

bool Board::canMoveBishop(Field* source, Field* destination)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if (abs(source->getX() - destination->getX()) == abs(source->getY() - destination->getY()))
	{
		int xIncrement = (destination->getX() - source->getX()) / (abs(destination->getX() - source->getX()));
		int yIncrement = (destination->getY() - source->getY()) / (abs(destination->getY() - source->getY()));

		for (int i = 1; i < abs(source->getX() - destination->getX()); i++)
		{
			cout << "It got here somehow!";
			if (board[source->getX() + xIncrement * i][source->getY() + yIncrement * i].getColor() != NONE)
				return false;
		}
	}
	else return false;

	return true;
}

bool Board::canMoveKnight(Field *source, Field * destination)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if ((abs(source->getX() - destination->getX()) == 2 && abs(source->getY() - destination->getY()) == 1) ||
		(abs(source->getX() - destination->getX()) == 1 && abs(source->getY() - destination->getY()) == 2))
	{
		return true;
	}
	else
		return false;
}

bool Board::canMovePawn(Field *source, Field * destination)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if (source->getColor() == WHITE)
	{
		if (source->getX() == destination->getX() && destination->getY() == source->getY() + 1 && destination->getColor() == NONE)
		{
			return true;
		}
		else if ((source->getX() + 1 == destination->getX() || source->getX() - 1 == destination->getX()) &&
			source->getY() + 1 == destination->getY() && destination->getColor() == BLACK)
		{
			return true;
		}
		else
			return false;
	}
	else if (source->getColor() == BLACK)
	{
		if (source->getX() == destination->getX() && destination->getY() == source->getY() - 1 && destination->getColor() == NONE)
		{
			return true;
		}
		else if ((source->getX() + 1 == destination->getX() || source->getX() - 1 == destination->getX()) &&
			source->getY() - 1 == destination->getY() && destination->getColor() == WHITE)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Board::canMakeMove(int sourceX, int sourceY, int destinationX, int destinationY) 
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

	King * castToKing = dynamic_cast<King*>(source->getFigure());
	Queen * castToQueen = dynamic_cast<Queen*>(source->getFigure());
	Knight * castToKnight = dynamic_cast<Knight*>(source->getFigure());
	Rook * castToRook = dynamic_cast<Rook*>(source->getFigure());
	Bishop * castToBishop = dynamic_cast<Bishop*>(source->getFigure());
	Pawn * castToPawn = dynamic_cast<Pawn*>(source->getFigure());

	if (castToKing != nullptr)
		return canMoveKing(source, destination);
	if (castToQueen != nullptr)
		return canMoveQueen(source, destination);
	if (castToKnight != nullptr)
		return canMoveKnight(source, destination);
	if (castToRook != nullptr)
		return canMoveRook(source, destination);
	if (castToBishop != nullptr)
		return canMoveKing(source, destination);
	if (castToPawn != nullptr)
		return canMoveQueen(source, destination);
}

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

void Board::moveFigure()
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

void Board::playNextTurn()
{
	system("cls");
	printGameBoard();
	moveFigure();
}
