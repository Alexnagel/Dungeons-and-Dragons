#pragma once
#include <random>
#include "DungeonGenerator.h"

class GameManager
{
public:
	static std::default_random_engine random;
	static const int NUMBER_OF_ROOMS_X = 10;
	static const int NUMBER_OF_ROOMS_Y = 10;

	GameManager();
	~GameManager();
};

