#include "Deck.h"

Deck::Deck() {
	for (size_t i = 2; i < 15; ++i)
	{
		for (size_t j = 3; j < 7; ++j)
		{
			deck_.push_back(new Card(i, j));
		}
	}
}

int Deck::getSize() {
	return deck_.size();
}

void Deck::swapCards(int first, int second) {
	Card* buff = deck_[first];
	deck_[first] = deck_[second];
	deck_[second] = buff;
}

Card* Deck::getCard() {
	Card* card = deck_.back();
	deck_.pop_back();
	return card;
}

