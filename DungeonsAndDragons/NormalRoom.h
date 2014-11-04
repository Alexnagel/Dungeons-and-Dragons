#pragma once
#include "Room.h"
#include "Enemy.h"
#include "Chest.h"

class NormalRoom : public Room
{
public:
	NormalRoom(int level);
	virtual ~NormalRoom();
	std::string PrintEnemies();
	std::string RoomCharacter();
	std::string Print() override;

private:
	// Variables
	const int MAX_ENEMIES = 3;
	const int CHANCE_CHEST = 40;
	int seed;
	std::mt19937 rng;

	std::vector<Enemy *> enemies;
	Chest* chest;

	void GenerateChest();
	void RandomizeEnemies();
	int RandomNumber(int max);
};

