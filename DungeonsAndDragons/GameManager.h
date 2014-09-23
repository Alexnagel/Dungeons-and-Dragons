#pragma once
#include <random>

class GameManager
{
public:
	static std::default_random_engine random;

	GameManager();
	~GameManager();
};

