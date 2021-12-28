#include "Player.h"
#include <iostream>

using namespace std;

void Player::setAccount(int account) {
	account_ = account;
}

int Player::getAccount() {
	return account_;
}

void Player::showCards() {
	cout << "Вы:        ";
	for (size_t i = 0; i < hand_.size(); ++i)
	{
		cout << *(hand_[i]) << "   ";
	}
	cout << endl;
}

