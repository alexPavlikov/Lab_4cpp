#pragma once
#include "Dealer.h"
#include "Player.h"

class Game
{
	Dealer* dealer_;
	Player* player_;
	bool wasDouble_;
	bool wasTriple_;
	bool isEnd_;
	int bet_;
	int select_;
public:
	Game();
	~Game();

	void play();
	void showTable();
	void dialog();
	void actionMenu();
	int getValue();
	void more();
	void endGame();
};

