#pragma once
#include <ostream>

class Card
{
	enum Value {
		_2 , _3, _4, _5, _6, _7, 
		_8, _9, _10, J, Q, K, A
	};
	enum Suit {
		Hearts = 3,
		Diamonds = 4,
		Clubs = 5,
		Spades = 6
	};
	Value value_;
	Suit suit_;
public:
	Card(int value, int suit);
	int getValue();
	int getSuit();
	friend std::ostream& operator<<(std::ostream& cout, const Card& card);
};

