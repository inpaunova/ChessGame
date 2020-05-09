#include <iostream>
#include <string>
#include "ChessGame.h"
using namespace std;

int main()
{
	ChessGame game;
	string keyFromKeyBoard;
	cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ ____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  |  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  \\_____|_|  |_|______|_____/_____/ \n" << endl;
	cout << "A game by George Harter" << endl;
	cout << "Enter any key to continue" << endl;
	cin >> keyFromKeyBoard;

	game.play();

	return 0;
}