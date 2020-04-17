class ChessGame
{
	const int BOARD_SIZE = 8;
	Field ** board;
	bool isGamePlaying;
	Color colorAtTheMoment;

	void setEmptyFields();
	void setPawnsOnFields();
	void setFieldCoordinates();
	void printFigure(Figure*, Color);
	void printGameBoard();
	string getUserInput();
	Color** takeCurrentColorsOfBoard();
	void switchColorAtTheMoment();
	bool isCoordinateInBoundsOfBoard(int);
	bool isGameEnd(int, int, int, int);
	bool canMoveFigure(Field*, Field*);
	bool canMakeMove(int, int, int, int);


public:
	ChessGame()
	{
		isGamePlaying = true;
		colorAtTheMoment = WHITE;
		board = new Field*[BOARD_SIZE];
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			board[i] = new Field[BOARD_SIZE];
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
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			delete board[i];
		}
		delete[] board;
	}

	void setGameBoard();
	void moveFigure();
	void playNextTurn();
};

