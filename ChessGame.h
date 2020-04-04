class ChessGame
{
	Field ** board;
	bool isGamePlaying;
	Color colorAtTheMoment;

	void printFigure(Figure*, Color);
	void printGameBoard();
	string getUserInput();
	void switchColorAtTheMoment();
	bool isCoordinateInBoundsOfBoard(int);
	bool isGameEnd(int, int, int, int);
	bool canMoveKing(Field*, Field*);
	bool canMoveQueen(Field*, Field*);
	bool canMoveRook(Field*, Field*);
	bool canMoveBishop(Field*, Field*);
	bool canMoveKnight(Field*, Field*);
	bool canMovePawn(Field*, Field*);
	bool canMakeMove(int, int, int, int);


public:
	ChessGame()
	{
		isGamePlaying = true;
		colorAtTheMoment = WHITE;
		board = new Field*[8];
		for (int i = 0; i < 8; i++)
		{
			board[i] = new Field[8];
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
		for (int i = 0; i < 8; i++)
		{
			delete board[i];
		}
		delete[] board;
	}

	void setGameBoard();
	void moveFigure();
	void playNextTurn();
};

