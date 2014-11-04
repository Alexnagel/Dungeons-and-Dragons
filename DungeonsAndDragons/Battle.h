#pragma once

#include <memory>
#include <vector>
#include <string>
#include "Enemy.h"
#include "Player.h"

class Battle
{
private:
	bool finished;
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Enemy>> enemies;

public:
	Battle();
	Battle(std::vector<std::shared_ptr<Enemy>> p_enemies, std::shared_ptr<Player> p_player);
	virtual ~Battle();

	// Functions
	std::string Flee();
	std::string Attack();
	std::string UsePotion();
	std::string UseItem();
	std::string Won();
	bool Finished();
};

