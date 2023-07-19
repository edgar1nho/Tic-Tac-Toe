#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe(Player& p1, Player& p2)
{
	createGame();
	outputBoard();
	TicTacToeRules();
	while (turns < 4)
	{
		Player1Turn(p1);
		outputBoard();
		++turns;
		Player2Turn(p2);
		outputBoard();
		++turns;
	}
	while (turns < 8)
	{
		Player1Turn(p1);
		outputBoard();
		++turns;
		if (calculatingResult(turns) == true)
		{
			std::cout << p1.getName() << " won.\n";
			exit(0);
		}
		calculatingResult(turns);
		Player2Turn(p2);
		outputBoard();
		++turns;
		if (calculatingResult(turns) == true)
		{
			std::cout << p2.getName() << " won.\n";
			exit(0);
		}
	}
	Player1Turn(p1); // last turn
	outputBoard();
	++turns;
	if (calculatingResult(turns) == true)
	{
		std::cout << p1.getName() << " won.\n";
		exit(0);
	}
	std::cout << "game ended as a draw.\n";
}

void TicTacToe::TicTacToeRules()
{
	std::cout << "In order to place your piece pass 2 arguments horizontally(x) and vertically(y) at the range of 0-2.\n";
	std::cout << "If wrong argument passed the game will ask you to pass new arguments.\n";
	std::cout << "Pass the arguments one by one in order to get messeages to be displayed right way\n";
	std::cout << '\n';
}

void TicTacToe::Player1Turn(Player& p1)
{
	x = 0;
	y = 0;
	std::cout << p1.getName() << "'s turn.\n";
	std::cout << "enter x value.\n";
	std::cin >> x;

	if (x < 0 || x > 2)
	{
		do
		{
			std::cout << "wrong argument passed, try again.\n";
			std::cout << "enter x value.\n";
			std::cin >> x;
		} while (x < 0 || x > 2);
	}
	
	std::cout << "enter y value.\n";
	std::cin >> y;
	if (y < 0 || y > 2)
	{
		do
		{
			std::cout << "wrong argument passed, try again.\n";
			std::cout << "enter y value.\n";
			std::cin >> y;
		} while (y < 0 || y > 2);
	}

	if (board[x][y] != " ' ")
	{
		std::cout << "at x = " << x << " and y = " << y << " place is not empty,give new arguments.\n";
		std::cout << "still ";
		Player1Turn(p1);
	}

	else
	{
		board[x][y] = X;
	}
}

void TicTacToe::Player2Turn(Player& p2)
{
	x = 0;
	y = 0;
	std::cout << p2.getName() << "'s turn.\n";
	std::cout << "enter x value.\n";
	std::cin >> x;

	if (x < 0 || x > 2)
	{
		do
		{
			std::cout << "wrong argument passed, try again.\n";
			std::cout << "enter x value.\n";
			std::cin >> x;
		} while (x < 0 || x > 2);
	}

	std::cout << "enter y value.\n";
	std::cin >> y;
	if (y < 0 || y > 2)
	{
		do
		{
			std::cout << "wrong argument passed, try again.\n";
			std::cout << "enter y value.\n";
			std::cin >> y;
		} while (y < 0 || y > 2);
	}

	if (board[x][y] != " ' ")
	{
		std::cout << "at x = " << x << " and y = " << y << " place is not empty,give new arguments.\n";
		std::cout << "still ";
		Player2Turn(p2);
	}

	else
	{
		board[x][y] = O;
	}
}

void TicTacToe::createGame()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			board[i][j] = " ' ";
		}
	}
}

void TicTacToe::outputBoard()
{
	for (int i = 0; i < 3; ++i)
	{
		std::cout << '\n';
		for (int j = 0; j < 3; ++j)
		{
			std::cout << board[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

bool TicTacToe::calculatingResult(int turn_count)
{
	std::string piece;
	if (turn_count % 2 != 0)
	{
		piece = X;
	}
	else
	{
		piece = O;
	}

	for (int i = 0; i < 3; ++i)  // horizontal win checking
	{
		if (piece == board[i][0] && piece == board[i][1] && piece == board[i][2])
		{
			std::cout << "game over.\n";
			return true;
		}
	}

	for (int i = 0; i < 3; ++i) // vertical win checking
	{
		if (piece == board[0][i] && piece == board[1][i] && piece == board[2][i])
		{
			std::cout << "game over.\n";
			return true;
		}
	}


	//diagonal win checking
	if (piece == board[0][0] && piece == board[1][1] && piece == board[2][2])
	{
		std::cout << "game over.\n";
		return true;
	}
	if (piece == board[0][2] && piece == board[1][1] && piece == board[2][0])
	{
		std::cout << "game over.\n";
		return true;
	}

	return false;
}