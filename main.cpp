// main.cpp

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "Card.h"

using namespace std;

int main()
{
	card c;
	string card;
	
	c.createDeck();
	c.shuffleDeck();

	card = c.getCard();
	cout << "\nIs this your card? " << card << endl;
	card = c.getCard();
	cout << "\nIs this your card? " << card << endl;
	
	return 0;
}
