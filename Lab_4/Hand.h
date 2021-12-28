#pragma once
#include <vector>
#include "Card.h"

class Hand
{
protected:
	std::vector<Card*> hand_;
public:
	void takeCard(Card* card);
	Card* showCard(int i);
	virtual void showCards()=0;
	int getCards();
	int getScore();
};

