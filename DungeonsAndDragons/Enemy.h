#pragma once

#include "Character.h"

class Enemy : public Character
{
protected:
	int xp;

public:
	Enemy();
	Enemy(int floor);
	virtual ~Enemy();

	// Functions
	virtual int GetXp();
	virtual int Attack();
	virtual int Hit(int damage);
};

