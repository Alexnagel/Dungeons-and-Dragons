#pragma once
#include "Room.h"
#include "Enemy.h"
#include "Chest.h"

class NormalRoom : public Room
{
public:
	NormalRoom(int level);
	virtual ~NormalRoom();
	void PrintEnemies();
	std::string RoomCharacter();
	void SetStart();

private:
	// Variables
	const int MAX_ENEMIES = 3;
	const int CHANCE_CHEST = 40;
	int seed;
	bool isStart;
	std::vector<Enemy *> enemies;
	Chest* chest;
	std::mt19937 rng;

	void GenerateChest();
	void RandomizeEnemies();
	int RandomNumber(int max);
};

