#include <iostream>
#include <conio.h>

int attemptsLeft = 3;
bool exitProgram = false;
int movesLeft = 4;
int correctMoves = 0;
char empty = ' ';
char board[3][3]
{
	{'*',empty,empty},
	{empty,empty,empty},
	{empty,empty,empty}
	
};

struct Player
{
	int rows = 0;
	int columns = 0;
};

Player LoginPlayer;

void startOver()
{
	attemptsLeft--;
	board[LoginPlayer.rows][LoginPlayer.columns] = ' ';
	LoginPlayer.rows = 0;
	LoginPlayer.columns = 0;
	board[0][0] = '*';
	correctMoves = 0;

	movesLeft = 4;
	system("CLS");
	std::cout << "You failed! Press a key to start over: ";
	char something = _getch();


}

void checkFailed()
{
	 if (movesLeft == 0 && correctMoves < 4)
	{
		startOver();
	}


}

void printBoard()
{
	system("CLS");
	std::cout << "Loginwindow\n\n";

	std::cout << "Number of attempts left: " << attemptsLeft << "\n\n";

	std::cout << "Number of moves left: " << movesLeft << "\n\n";

	std::cout << " -------------------- \n";
	std::cout << "| 1  " << board[0][0] <<" | 2  " << board[0][1] << " | 3  " << board[0][2] << " |\n";
	std::cout << "|--------------------|\n";
	std::cout << "| 4  " << board[1][0] << " | 5  " << board[1][1] << " | 6  " << board[1][2] << " |\n";
	std::cout << "|--------------------| \n";
	std::cout << "| 7  " << board[2][0] << " | 8  " << board[2][1] << " | 9  " << board[2][2] << " |\n";
	std::cout << " -------------------- \n";

}

void move()
{

	board[LoginPlayer.rows][LoginPlayer.columns] = '*';

		char movementInput = _getch();

		switch (movementInput)
		{
		case 'w':

			board[LoginPlayer.rows][LoginPlayer.columns] = ' ';
			LoginPlayer.rows--;
			if (LoginPlayer.rows == -1)
			{
				LoginPlayer.rows = 2;
			}
			board[LoginPlayer.rows][LoginPlayer.columns] = '*';


			break;

		case 'a':
			board[LoginPlayer.rows][LoginPlayer.columns] = ' ';
			LoginPlayer.columns--;
			if (LoginPlayer.columns == -1)
			{
				LoginPlayer.columns = 2;
			}
			board[LoginPlayer.rows][LoginPlayer.columns] = '*';

			break;

		case 's':
			board[LoginPlayer.rows][LoginPlayer.columns] = ' ';
			LoginPlayer.rows++;
			if (LoginPlayer.rows == 3)
			{
				LoginPlayer.rows = 0;
			}
			board[LoginPlayer.rows][LoginPlayer.columns] = '*';

			break;

		case 'd':
			board[LoginPlayer.rows][LoginPlayer.columns] = ' ';
			LoginPlayer.columns++;
			if (LoginPlayer.columns == 3)
			{
				LoginPlayer.columns = 0;
			}
			board[LoginPlayer.rows][LoginPlayer.columns] = '*';
			break;

		}
		movesLeft--;
	
}

void checkCorrectMove()
{
	if (board[1][0] == '*' && movesLeft == 3)
	{
		correctMoves++;
	}
	else if (board[1][1] == '*' && movesLeft == 2)
	{
		correctMoves++;
	}
	else if (board[0][1] == '*' && movesLeft == 1)
	{
		correctMoves++;
	}
	else if (board[0][2] == '*' && movesLeft == 0)
	{
		correctMoves++;
	}
}

int login()
{

	while (true)
	{
		if (attemptsLeft == 0)
		{
			system("CLS");
			std::cout << "Out of retries. Program will terminate when you press a key: ";
			char something = _getch();
			return 0;
		}

		checkFailed();
		printBoard();
		move();
		checkCorrectMove();

		if (correctMoves == 4)
		{
			system("CLS");
			std::cout << "You unlocked the code! Press a key to continue: ";
			char something = _getch();
			return 1;
		}
		
	}
	
	
	
}