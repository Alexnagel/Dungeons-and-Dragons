#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
private:
	int xp;

public:
	Boss();
	virtual ~Boss();

	// Functions
	int GetXp() override;
	int Attack() override;
	int Hit(int damage) override;
};

