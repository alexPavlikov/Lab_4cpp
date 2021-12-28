#include "Game.h"
#include <iostream>
#include <ctime>

using namespace std;

Game::Game() {
	dealer_ = new Dealer();
	dealer_->shuffleDecks();
	player_ = new Player();
	wasDouble_ = false;
	wasTriple_ = false;
	isEnd_ = false;
}

Game::~Game() {
	delete player_;
	delete dealer_;
}

void Game::play() {
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Ваша ставка? ";
	bet_ = getValue();
	for (size_t i = 0; i < 2; ++i)
	{
		player_->takeCard(dealer_->getRandomCard());
		dealer_->takeCard(dealer_->getRandomCard());
	}
	showTable();

	dialog();
}

void Game::showTable() {
	dealer_->showDecks();
	if (!isEnd_)
	{
		dealer_->showCardsWithHidden();
	}
	else
	{
		dealer_->showCards();
	}
	player_->showCards();
}

void Game::dialog() {
	select_ = 0;
	actionMenu();
	select_ = getValue();
	while (select_ != 0)
	{
		switch (select_)
		{
		case 1:
			isEnd_ = true;
			showTable();
			endGame();
			select_ = 0;
			break;
		case 2:
			more();
			showTable();
			if (select_ != 0)
			{
				actionMenu();
				select_ = getValue();
			}
			break;
		case 3:
			if (!wasDouble_) {
				wasDouble_ = true;
				bet_ *= 2;
				more();
			}
			else if (!wasTriple_) {
				wasTriple_ = true;
				bet_ += (bet_ / 2);
				more();
			}
			showTable();
			if (select_ != 0)
			{
				actionMenu();
				select_ = getValue();
			}
			break;
		default:
			showTable();
			cout << "Введите кооректное число!" << endl;
			actionMenu();
			select_ = getValue();
			break;
		}
	}
}

void Game::actionMenu() {
	short actionNo = 0;
	cout << ++actionNo << ". Хватит" << endl;
	cout << ++actionNo << ". Ещё" << endl;
	if (!wasDouble_) {
		cout << ++actionNo << ". Дабл" << endl;
	}
	else if (!wasTriple_) {
		cout << ++actionNo << ". Трипл" << endl;
	}
}

int Game::getValue()
{
	while (true)
	{
		int input;
		cin >> input;

		if (cin.fail() || input <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введите кооректное число!\n";
		}
		else
		{
			cin.ignore(32767, '\n');
			return input;
		}
	}
}

void Game::more() {
	player_->takeCard(dealer_->getRandomCard());
	int playerScore = player_->getScore();
	try {
		if (playerScore > 21)
		{
			throw true;
		}
	}
	catch (...) {
		isEnd_ = true;
		cout << "Перебор! Вы проиграли! Ваш проигрыш : " << bet_ << endl;
		player_->setAccount(player_->getAccount() - bet_);
		cout << "Всего:" << player_->getAccount() << endl;
		select_ = 0;
	}
}

void Game::endGame() {
	select_ = 0;
	int dealerScore = dealer_->getScore();
	int playerScore = player_->getScore();
	int bonus = bet_ - 5;
	int counter = 0;
	for (size_t i = 0; i < player_->getCards(); ++i)
	{
		int value = player_->showCard(i)->getValue();
		if (value == 7) {
			counter++;
		}
	}
	if (counter == 3)
	{
		bonus *= 250;
	}
	else if (counter == 2)
	{
		bonus *= 25;
	}
	else if (counter == 1)
	{
		bonus *= 5;
	}
	else
	{
		bonus = 0;
	}
	if (bonus < 0) {
		bonus = 0;
	}
	if (playerScore == 21 && player_->getCards() == 2)
	{
		if (playerScore == dealerScore) {
			cout << "Ничья, возрвращена ваша ставка:" << bet_ << endl;
			player_->setAccount(player_->getAccount() + bet_);
			cout << "Всего:" << player_->getAccount();
		}
		else
		{
			cout << " Вы выиграли! Сумма вашего выигрыша:" << bet_ * 2 + bonus << endl;
			player_->setAccount(player_->getAccount() + bet_ * 2 + bonus);
			cout << "Всего:" << player_->getAccount();
		}
	}
	else if (playerScore <= dealerScore) {
		cout << "Вы проиграли!  Проиграна ставка:" << bet_ << endl;
		player_->setAccount(player_->getAccount() - bet_);
		cout << "Всего:" << player_->getAccount();
	}
	else if (playerScore >= dealerScore) {
		cout << " Вы выиграли! Сумма вашего выигрыша:" << bet_ * 2 + bonus << endl;
		player_->setAccount(player_->getAccount() + bet_ * 2 + bonus);
		cout << "Всего:" << player_->getAccount();
	}
}

