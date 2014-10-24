#pragma once

#include "Character.h"

class Enemy : public Character
{
private:
	int xp;

public:
	Enemy();
	virtual ~Enemy();

	// Functions
	int GetXp();
	int Attack();
	int Hit(int damage);
};

