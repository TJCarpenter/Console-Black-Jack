#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>   
#include <time.h>
#include "Card.h"
#include "Person.h"

//#define TestPrintDeck

using namespace std;

void card::createDeck()
{
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

int card::getCardNumValue()
{
	string cardVal = drawLastCard();
	int valueCard;
	for (int i = 0; i < 13; i++)
	{
		if (cardVal.substr(1,1) == cardValue[i])
		{
			if ((cardVal.substr(1, 1) == "J") || (cardVal.substr(1, 1) == "Q") || (cardVal.substr(1, 1) == "K"))
			{
				valueCard = 10;
			}//end if
			else if (cardVal.substr(1, 1) == "A")
			{
				addToTotalScore(11);
				if (getTotalScore() > 21)
				{
					valueCard = 1;
					addToTotalScore(-11);
					addToTotalScore(1);
					return 1;
				}//end if
				else if (getTotalScore() <= 21)
				{
					valueCard = 11;
					return 11;
				}//end else if
			}//end else if
			else
			{
				valueCard = i + 2;
			}
		}//end if
	}//end for
	return valueCard;
}

string card::drawLastCard()
{
	numCardInDeck--;
	string card = deck[numCardInDeck++];
	return card;

}
