#pragma once
#include <random>
#include "DungeonGenerator.h"

class GameManager
{
public:
	static std::default_random_engine random;

	GameManager();
	~GameManager();
};

