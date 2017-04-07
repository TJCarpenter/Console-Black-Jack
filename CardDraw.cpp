#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>   
#include <time.h>
#include "Card.h"

#define TestPrintDeck

using namespace std;

void card::createDeck()
{
	string cardSuits[4] = { "S", "C", "H", "D" };
	string cardValue[13] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	for (int s = 0; s < 4; s++)
	{
		for (int v = 0; v < 13; v++)
		{
			deck.push_back(cardSuits[s] + cardValue[v]);
		}
	}
#ifdef TestPrintDeck
	for (int i = 0; i < 52; i++)
	{
		cout << deck[i] << " ";
	}
#endif // TestPrintDeck

}

void card::shuffleDeck()
{
	mt19937 g(static_cast<uint32_t>(time(0)));
	shuffle(deck.begin(), deck.end(), g);

#ifdef TestPrintDeck
	cout << endl;
	for (int i = 0; i < 52; i++)
	{
		cout << deck[i] << " ";
	}
#endif // TestPrintDeck
}
