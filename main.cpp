#include <iostream>
#include <string>
#include "ChessGame.h"

using namespace std;

void playGame(ChessGame game)
{
	bool wantNewGame = true;
	string yesNoAnswer;
	while (wantNewGame)
	{
		game.board.setGameBoard();
		while (game.isGamePlaying)
		{
			game.playNextTurn();
		}
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> yesNoAnswer;
		if (yesNoAnswer != "y")
			wantNewGame = false;
	}
}

int main()
{
	ChessGame game;
	string keyFromKeyBoard;
	cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ ____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  |  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  \\_____|_|  |_|______|_____/_____/ \n" << endl;
	cout << "A game by George Harter"<<endl;
	cout << "Enter any key to continue" << endl;
	cin >> keyFromKeyBoard;

	playGame(game);
	
	return 0;
}