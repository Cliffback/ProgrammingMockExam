#include <iostream>
#include <conio.h>
#include "MockExam.h"

void menu()
{
	while (true)
	{
		system("CLS");
		std::cout << "Welcome to my Mock Exam!\n";
		std::cout << "\nTask 1\n";
		std::cout << "Task 2\n";
		std::cout << "Task 3\n";
		std::cout << "Task 4\n";
		std::cout << "Press 5 to exit\n";


		int choice = 0;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			system("CLS");
			return;
		default:

			while (true)
			{
				system("CLS");
			std::cout << "Wrong input. Do you want to try again: (y/n)\n";
			char answer = _getch();
			
				if (answer == 'Y' || answer == 'y')
				{
					break;
				}
				else if (answer == 'N' || answer == 'n')
				{
					return;
				}
			}
			
			break;
		}
	}
}