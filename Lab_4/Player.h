#pragma once
#include <vector>
#include "Card.h"
#include "Hand.h"

class Player : public Hand
{
	int account_;
public:
	void setAccount(int bet);
	int getAccount();
	void showCards() override;
};

