#pragma once
#include <random>
#include "DungeonGenerator.h"
#include "Dungeon.h"
#include "Player.h"
#include "Battle.h"
#include "Utils.h"

class GameManager
{
private:
	// Variables
	bool isRunning;
	std::unique_ptr<Dungeon> dungeon;
	std::shared_ptr<Player> player;
	std::shared_ptr<Room> currentRoom;
	Battle battle;
	int level;
	bool canRest;

	// Functions
	void PrintFloor();
	void PrintRoom(int x, int y);
	void PrintChest();
	void TakeItem();
	void Move();
	void Attack();
	void Flee();
	void StartGame();
	void QuitGame();
	void Help();
	void PlayerStats();
	void Rest();
	void ListBackpack();
	void EquipItem();
	void RoomInfo();
	void HandleInput(std::string input);

public:
	static std::default_random_engine random;
	static const int NUMBER_OF_ROOMS_X = 10;
	static const int NUMBER_OF_ROOMS_Y = 10;

	GameManager();
	~GameManager();
};

