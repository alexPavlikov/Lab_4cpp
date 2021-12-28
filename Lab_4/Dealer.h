#pragma once
#include "Deck.h"
#include <vector>
#include "Card.h"
#include "Hand.h"

class Dealer : public Hand
{
	Deck* decks_;
public:
	Dealer();
	~Dealer();

	Deck* getDeck(int i);
	Card* getRandomCard();

	void shuffleDecks();
	void showDecks();
	void showCardsWithHidden();
	void showCards()override;
};

