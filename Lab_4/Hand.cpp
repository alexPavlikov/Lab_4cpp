#include "Hand.h"


void Hand::takeCard(Card* card) {
	hand_.push_back(card);
}

Card* Hand::showCard(int i) {
	return hand_[i];
}

int Hand::getCards() {
	return hand_.size();
}

int Hand::getScore(){
	int score = 0;
	bool wasAce = false;
	for (size_t i = 0; i < hand_.size(); ++i)
	{
		int value = hand_[i]->getValue();
		if (value == 11) {
			if (wasAce || score > 10) {
				value = 1;
			}
			wasAce = true;
		}
		score += value;
	}
	return score;
}
