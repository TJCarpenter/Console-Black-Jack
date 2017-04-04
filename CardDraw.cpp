#include "stdafx.h"
#include "CardDraw.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class card {
public:
	string getSuit();
	string getValue();
	string getFullCard();
	string concatenate(string, string);
	card(string, string);
private:
	string suit;
	string value;
	string fullCard;
};

void printCard(card);
int checkCard(vector <string>, card);

//array of the cards suits and value
string suits[4] = { "S", "C", "H", "D" };
string value[13] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

vector <string> drawnCards;


//draws the card
void CardDraw(int numDraw) 
{
	int j = 1, decks = 1;
	drawnCards.resize(1);
	while (j <= numDraw)
	{
		randomCard:
		card c(suits[rand() % 4], value[rand() % 13]);
		for (int i = 0; i < drawnCards.size(); i++)
		{
			c.concatenate(c.getSuit(), c.getValue());
			int check = checkCard(drawnCards, c);
			if (check == 0)
			{
				goto randomCard;
			}//end if
			else
			{
				drawnCards.push_back(c.getFullCard());
				printCard(c);
				j++;
				break;
			}//end else
		}//end for
	}//end while
}//end CardDraw

//gets suit value
string card::getSuit() {
	return suit;
}//end getSuit

//gets card value
string card::getValue() {
	return value;
}//end getValue

//gets full card value and suit
string card::getFullCard() {
	return fullCard;
}//end getFullCard

//sets card values
card::card(string s, string v) :suit(s), value(v)
{}

//concatenates into a single string
string card::concatenate(string suit, string value) {
	fullCard = value + suit;
	return fullCard;
}//end concatenate

//prints card
void printCard(card c) {
	cout <<c.getFullCard() << endl;
}//end printCard

int checkCard(vector <string> v, card c) {
	for (int i = 0; i < v.size(); i++) {
		if (c.concatenate(c.getSuit(), c.getValue()) == drawnCards[i]) {
			return 0;
			break;
		}
		else {
			continue;
		}
		return 1;
	}
}
