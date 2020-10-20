#include <iostream>
#include <conio.h>
#include "MockExam.h"

struct PlayerStruct
{
	int rows = 1;
	int columns = 1;
	int coins = 0;
};

PlayerStruct PlayerTwo;

char gameGrid[10][10] = {
 {'|','#','#','#','#','#','#','#','#','|'},
 {'|',' ',' ','o','o','o','o','o',' ','|'},
 {'|','#','#',' ','#','#','#','#','#','|'},
 {'|','o',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|','o','|',' ','|','#','#','#','|','|'},
 {'|','o','|',' ','|',' ',' ',' ','|','|'},
 {'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
 {'|','o','o',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ',' ','#','#','#','#','#',' ','|'},
 {'|','_','_','_','_','_','_','_','_','|'},
};

void printGameGrid()
{
	std::cout
		<< "\n       My Little Packman v1.0\n"
		<< "\n\t      Coins: " << PlayerTwo.coins

		<< "\n\n\tWASD to move around\n"
		<< "\t  Press Q to exit\n";

	std::cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\t";
		for (int j = 0; j < 10; j++)
		{
			std::cout << gameGrid[i][j] << " ";
		}
		std::cout << "\n";
	}

}

void updateCoins(PlayerStruct& Player1)
{
	if (gameGrid[Player1.rows][Player1.columns] == 'o')
	{
		Player1.coins = Player1.coins+5;
	}
}

void movePlayer(PlayerStruct& Player1)
{
	char movementInput = _getch();

	switch (movementInput)
	{
	case 'w':
		gameGrid[Player1.rows][Player1.columns] = ' ';
		Player1.rows--;
		if (gameGrid[Player1.rows][Player1.columns] == '|' || gameGrid[Player1.rows][Player1.columns] == '_' || gameGrid[Player1.rows][Player1.columns] == '#')
		{
			Player1.rows++;
		}

		break;

	case 'a':
		gameGrid[Player1.rows][Player1.columns] = ' ';
		Player1.columns--;
		if (gameGrid[Player1.rows][Player1.columns] == '|' || gameGrid[Player1.rows][Player1.columns] == '_' || gameGrid[Player1.rows][Player1.columns] == '#')
		{
			Player1.columns++;
		}

		break;

	case 's':
		gameGrid[Player1.rows][Player1.columns] = ' ';
		Player1.rows++;
		if (gameGrid[Player1.rows][Player1.columns] == '|' || gameGrid[Player1.rows][Player1.columns] == '_' || gameGrid[Player1.rows][Player1.columns] == '#')
		{
			Player1.rows--;
		}

		break;

	case 'd':
		gameGrid[Player1.rows][Player1.columns] = ' ';
		Player1.columns++;
		if (gameGrid[Player1.rows][Player1.columns] == '|' || gameGrid[Player1.rows][Player1.columns] == '_' || gameGrid[Player1.rows][Player1.columns] == '#')
		{
			Player1.columns--;
		}

		break;

	case 'q':
		menu();
	}


}

void updatePlayer(PlayerStruct& Player1)
{
	updateCoins(Player1);
	gameGrid[Player1.rows][Player1.columns] = 'E';

}

void task4()
{
	system("CLS");
	while (true)
	{
		system("CLS");
		updatePlayer(PlayerTwo);
		printGameGrid();
		movePlayer(PlayerTwo);
	}

	char something = _getch();

}