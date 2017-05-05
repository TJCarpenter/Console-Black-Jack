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
		string card = deck[numCardInDeck];
		++numCardInDeck;
		return card;
	}
	int randomNumber()
	{
		return rand() % 1000;
	}
	int getCardNumValue();
	int getTotalScore() { return score; }
	void addToTotalScore(int s) { s += score; }
	string drawLastCard();
private:
	vector<string> deck;
	int numCardInDeck = 0;
	string cardValue[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	string cardSuits[4] = { "S", "C", "H", "D" };
	int score = 0;
	
};



#endif // Card_h
