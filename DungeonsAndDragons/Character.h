#pragma once
#include <random>

class Character
{
public:
	Character();
	virtual ~Character();

	// Functions
	std::string GetName();
	int GetLevel();
	int GetMaxHp();
	int GetHp();

protected:
	std::string name;
	int maxHp;
	int hp;
	int level;

	int seed;
	std::mt19937 rng;
	int RandomNumber(int max);
	int RandomNumber(int min, int max);
};

