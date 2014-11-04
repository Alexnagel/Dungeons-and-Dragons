#pragma once

#include <vector>
#include <string>
#include "Enemy.h"
#include "Player.h"

class Battle
{
private:
	bool finished;
	Player* player;
	std::vector<Enemy*> enemies;

public:
	Battle();
	Battle(std::vector<Enemy*> p_enemies, Player* p_player);
	virtual ~Battle();

	// Functions
	std::string Flee();
	std::string Attack();
	std::string UsePotion();
	std::string UseItem();
	std::string Won();
	bool Finished();
};

