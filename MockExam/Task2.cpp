#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>


struct unit
{
	int index = 0;
	char name = 'A';
	int health = 0;
};

unit array[10]{};

bool sortUnitByHealth(unit lhs, unit rhs) { return lhs.health < rhs.health; }

void writeValues()
{
	for (int i = 0; i < 10; i++)
	{
		array[i].index = i;
		array[i].health = rand() % 20 + 1;
		array[i].name = static_cast<char>(array[i].name + i);
	}

}

void printTable()
{

	std::cout
		<< "\n\tNo \tName \tValue \t Health Bar \n"
		<< "        -------------------------------------------------------------------------------------";

	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n\t" << array[i].index << "\t" << array[i].name << "\t" << array[i].health << "\t";

		for (int j = 0; j < array[i].health; j++)
		{
			std::cout << " * ";
		}

		std::cout << "\n";

	}
}

void task2()
{
	srand(time(nullptr));
	system("CLS");
	writeValues();
	std::cout << "\n\tUnsorted table:\n";
	printTable();
	
	std::sort(array, array + 10, sortUnitByHealth);

	std::cout << "\n\n\tSorted table:\n";

	printTable();

	std::cout << "\n\n\tPess a key to return to the main menu: ";
	char something = _getch();

}