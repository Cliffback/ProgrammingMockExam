#include <iostream>
#include <conio.h>
#include "MockExam.h"

struct Players
{
	int rows = 1;
	int columns = 1;
};

Players PlayerOne;

char grid[10][10] = {
 {'|','#','#','#','#','#','#','#','#','|'},
 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|','#','#',' ','#','#','#','#','#','|'},
 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ','|',' ','|','#','#','#','|','|'},
 {'|',' ','|',' ','|',' ',' ',' ','|','|'},
 {'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ',' ','#','#','#','#','#',' ','|'},
 {'|','_','_','_','_','_','_','_','_','|'},
};

void printGrid()
{
	std::cout 
		<< "\n       My Little Packman v0.1\n"

		<< "\n\tWASD to move around\n"
		<< "\t  Press Q to exit\n";

	std::cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\t";
		for (int j = 0; j < 10; j++)
		{
			std::cout << grid[i][j] << " ";
		}
		std::cout << "\n";
	}

}

void movePlayer(Players& Player1)
{
	char movementInput = _getch();

	switch (movementInput)
	{
	case 'w':
		grid[Player1.rows][Player1.columns] = ' ';
		Player1.rows--;
		if (grid[Player1.rows][Player1.columns] == '|' || grid[Player1.rows][Player1.columns] == '_' || grid[Player1.rows][Player1.columns] == '#')
		{
			Player1.rows++;
		}
	
		break;

	case 'a':
		grid[Player1.rows][Player1.columns] = ' ';
		Player1.columns--;
		if (grid[Player1.rows][Player1.columns] == '|' || grid[Player1.rows][Player1.columns] == '_' || grid[Player1.rows][Player1.columns] == '#')
		{
			Player1.columns++;
		}

		break;

	case 's':
		grid[Player1.rows][Player1.columns] = ' ';
		Player1.rows++;
		if (grid[Player1.rows][Player1.columns] == '|' || grid[Player1.rows][Player1.columns] == '_' || grid[Player1.rows][Player1.columns] == '#')
		{
			Player1.rows--;
		}

		break;

	case 'd':
		grid[Player1.rows][Player1.columns] = ' ';
		Player1.columns++;
		if (grid[Player1.rows][Player1.columns] == '|' || grid[Player1.rows][Player1.columns] == '_' || grid[Player1.rows][Player1.columns] == '#')
		{
			Player1.columns--;
		}

		break;

	case 'q':
		menu();
	}


}

void updatePlayer(Players& Player1)
{
	grid[Player1.rows][Player1.columns] = 'E';

}

void task3()
{
	system("CLS");
	while (true)
	{
		system("CLS");
		updatePlayer(PlayerOne);
		printGrid();
		movePlayer(PlayerOne);
	}

	char something = _getch();

}