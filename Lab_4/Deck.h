#pragma once
#include "Card.h"
#include <vector>

class Deck
{
	std::vector<Card*> deck_;
public:
	Deck();
	int getSize();
	void swapCards(int first, int second);
	Card* getCard();
};

