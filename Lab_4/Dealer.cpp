#define _CRT_SECURE_NO_WARNINGS
#include "Dealer.h"
#include <ctime>
#include <iostream>

using namespace std;

Dealer::Dealer() {
	decks_ = new Deck[4];
}

Dealer::~Dealer() {
	delete[] decks_;
}

Deck* Dealer::getDeck(int i) {
	return &decks_[i];
}

Card* Dealer::getRandomCard() {
	static int random = 0;
	time_t t = time(0);
	tm* now = localtime(&t);
	srand(now->tm_hour + now->tm_min + now->tm_sec + ++random);
	return decks_[rand() % 4].getCard();
}


void Dealer::shuffleDecks() {
	int pos, pos2;
	static int random = 0;
	time_t t = time(0);
	tm* now = localtime(&t);
	for (size_t i = 0; i < 4; ++i)
	{
		srand(now->tm_hour + now->tm_min + now->tm_sec + ++random);
		for (size_t j = 0; j < 208; ++j)
		{
			pos = rand() % 52;
			pos2 = rand() % 52;
			decks_[i].swapCards(pos, pos2);
		}
	}
}

void Dealer::showDecks() {
	cout << "Колоды:   [" << decks_[0].getSize() << "] ["
		<< decks_[1].getSize() << "] ["
		<< decks_[2].getSize() << "] ["
		<< decks_[3].getSize() << ']' << endl;
}

void Dealer::showCardsWithHidden() {
	cout << "Дилер:     " << *(hand_[0]) << "   ??" << endl;
}

void Dealer::showCards() {
	cout << "Дилер:     " << *(hand_[0]) << "   " << *(hand_[1]) << endl;
}



