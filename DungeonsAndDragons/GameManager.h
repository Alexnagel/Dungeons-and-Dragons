#pragma once
#include <random>
#include "DungeonGenerator.h"
#include "Dungeon.h"
#include "Player.h"

class GameManager
{
private:
	// Variables
	bool isRunning;
	Dungeon* dungeon;
	Player player;
	int level;

	// Functions
	void PrintFloor();
	void PrintRoom(int x, int y);
	void StartGame();
	void QuitGame();
	void Help();
	void HandleInput(std::string input);
	std::string ToLowerCase(std::string string);

public:
	static std::default_random_engine random;
	static const int NUMBER_OF_ROOMS_X = 10;
	static const int NUMBER_OF_ROOMS_Y = 10;

	GameManager();
	~GameManager();
};

