#include "Card.h"



std::ostream& operator<<(std::ostream& out, const Card& card) {
	if (card.value_ < 10) {
		out << (char)(card.value_ + 48) << (char)card.suit_;
	}
	else if (card.value_ == 10) {
		out << "10" << (char)card.suit_;
	}
	else if (card.value_ == 11) {
		out << 'J' << (char)card.suit_;
	}
	else if (card.value_ == 12) {
		out << 'Q' << (char)card.suit_;
	}
	else if (card.value_ == 13) {
		out << 'K' << (char)card.suit_;
	}
	else if (card.value_ == 14) {
		out << 'A' << (char)card.suit_;
	}
	return out;
}

Card::Card(int value, int suit) {
	value_ = (Card::Value)value;
	suit_ = (Card::Suit)suit;
}

int Card::getValue()
{
	if (value_ < 11) {
		return value_;
	}
	else if (value_ == 14) {
		return 11;
	}
	else {
		return 10;
	}
}

int Card::getSuit() {
	return suit_;
}
