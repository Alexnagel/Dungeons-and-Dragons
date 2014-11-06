#pragma once
#include "Room.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Chest.h"

class NormalRoom : public Room
{
public:
	NormalRoom(int level);
	NormalRoom(int level, bool isStart);
	virtual ~NormalRoom();
	std::string PrintEnemies();
	std::string RoomCharacter();
	std::string Print() override;
	std::vector<std::shared_ptr<Enemy>> GetEnemies() override;
	void DefeatedEnemies() override;

private:
	// Variables
	const int MAX_ENEMIES = 3;
	const int CHANCE_CHEST = 40;
	int seed;
	std::mt19937 rng;

	std::vector<std::shared_ptr<Enemy>> enemies;
	Chest chest;

	std::string GetOptions();
	void GenerateChest();
	void RandomizeEnemies();
	int RandomNumber(int max);
};

