#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

const int rollNumber = 2000;
int diceCounter[6]{};

void resetDiceCounter()
{
	for (int i = 0; i < 6; i++)
	{
		diceCounter[i] = 0;
	}
}

int diceRoll()
{
	int randomNumber = rand() % 6 + 1;
	return randomNumber;
}

void rollDices()
{
	for (int i = 0; i < rollNumber; i++)
	{
		int rolledDice = 0;
		rolledDice = diceRoll();
		diceCounter[rolledDice-1]++;
	}
}

void printResults()
{
	std::cout
		<< "You just rolled " << rollNumber << " dice!\n"

		<< "\nYou rolled one " << diceCounter[0] << " times"
		<< "\nYou rolled two " << diceCounter[1] << " times"
		<< "\nYou rolled thre " << diceCounter[2] << " times"
		<< "\nYou rolled four " << diceCounter[3] << " times"
		<< "\nYou rolled five " << diceCounter[4] << " times"
		<< "\nYou rolled six " << diceCounter[5] << " times";

}

void task1()
{
	srand(time(nullptr));
	resetDiceCounter();

	system("CLS");
	std::cout << "Press a key to roll " << rollNumber << " dice: ";
	char something = _getch();
	rollDices();
	system("CLS");
	printResults();
	std::cout << "\n\nPress a key to go back to the main menu: ";
	char goToMenu = _getch();

}