// Console Black Jack.cpp
// Tyler Carpenter 1273574

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <vector>
#include "CardDraw.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER_KEY 13

using namespace std;
void printSelectionScreen(int);
void selectSelection(int);

int main() {
	srand(time(NULL));

	int selection = 1;
	//switch statement for menu selection
	printSelectionScreen(selection);
	while (1)
	{
		char keyPress = _getch();
		switch (keyPress)
		{
		case KEY_UP:
			selection--;
			if (selection > 4)
			{
				selection = 4;
			}
			else if (selection < 1)
			{
				selection = 1;
			}
			printSelectionScreen(selection);

			break;
		case KEY_DOWN:
			selection++;
			if (selection > 4)
			{
				selection = 4;
			}
			else if (selection < 1)
			{
				selection = 1;
			}
			printSelectionScreen(selection);	
			break;
		case ENTER_KEY:
			selectSelection(selection);

		}
	}
	return 0;
}

void printSelectionScreen(int selection)
{
	system("cls");
	switch (selection)
	{
	case 1:
		cout << "\n\n";
		cout << "\t\t-> New Turn\n";
		cout << "\t\t   Hit\n";
		cout << "\t\t   Stand\n";
		cout << "\t\t   Bet\n";
		break;
	case 2:
		cout << "\n\n";
		cout << "\t\t   New Turn\n";
		cout << "\t\t-> Hit\n";
		cout << "\t\t   Stand\n";
		cout << "\t\t   Bet\n";
		break;
	case 3:
		cout << "\n\n";
		cout << "\t\t   New Turn\n";
		cout << "\t\t   Hit\n";
		cout << "\t\t-> Stand\n";
		cout << "\t\t   Bet\n";
		break;
	case 4:
		cout << "\n\n";
		cout << "\t\t   New Turn\n";
		cout << "\t\t   Hit\n";
		cout << "\t\t   Stand\n";
		cout << "\t\t-> Bet\n";
		break;
	}
}

void selectSelection(int selection)
{
	system("cls");
	switch (selection)
	{
	case 1:
		CardDraw(2);
		break;
	case 2:
		CardDraw(1);
		break;
	case 3:
		CardDraw(0);
		break;
	case 4:

		break;
	}
}
