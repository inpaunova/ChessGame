#pragma once

enum Colors { WHITE, BLACK, NONE };

class Figure
{
public:
	virtual bool canMove(int sourceX, int sourceY, int destinationX, int destinationY) = 0;

	void setColorOfBoardFigures(Colors** fieldColors)
	{
		for (int x = 0; x < PLAYING_BOARD_SIZE; x++)
		{
			for (int y = 0; y < PLAYING_BOARD_SIZE; y++)
			{
				colorsOfBoardFigures[x][y] = fieldColors[x][y];
			}
		}
	}

	virtual void printAsLetter(Colors colorOfTheFigure) = 0;
	virtual bool isKing() = 0;

protected:
	static const int PLAYING_BOARD_SIZE = 8;
	Colors colorsOfBoardFigures[PLAYING_BOARD_SIZE][PLAYING_BOARD_SIZE];
};