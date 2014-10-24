#pragma once

#include "Character.h"

class Enemy : public Character
{
private:
	std::string name;
	int level;
	int hp;
	int xp;

public:
	Enemy();
	~Enemy();

	// Functions
	std::string GetName();
	int GetLevel();
	int GetHp();
	int GetXp();
	int Attack();
	int Hit(int damage);
};

