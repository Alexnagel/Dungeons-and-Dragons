#pragma once

#include "Character.h"

class Enemy : public Character
{
private:
	int xp;

public:
	Enemy();
	Enemy(int floor);
	virtual ~Enemy();

	// Functions
	int GetXp();
	int Attack();
	int Hit(int damage);
};

