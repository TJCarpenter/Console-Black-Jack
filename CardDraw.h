#pragma once
#ifndef Card_h
#define Card_h

#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class card
{
public:
	void createDeck();
	void shuffleDeck();
	void pushBack(string s, string v)
	{
		deck.push_back(s + v);
	}
	string getCard()
	{
		return deck[numCardInDeck++];
	}
	int randomNumber()
	{
		return rand() % 1000;
	}
protected:
	vector<string> deck;
	int numCardInDeck = 0;
};



#endif // Card_h
