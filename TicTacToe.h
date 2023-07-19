#include "Player.h"

class TicTacToe
{
	private:
		int turns{ 0 };
		int x{ 0 };
		int y{ 0 };
		std::string board[3][3]{};
		const std::string X { " X " };
		const std::string O { " O " };
	public:
		TicTacToe(Player& p1, Player& p2);
		void TicTacToeRules();
		void Player1Turn(Player& p1);
		void Player2Turn(Player& p2);
		void createGame();
		bool calculatingResult(int turn_count);
		void outputBoard();

};