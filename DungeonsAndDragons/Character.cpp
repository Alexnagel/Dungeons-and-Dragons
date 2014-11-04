#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	seed = std::random_device()();
	rng = std::mt19937(seed);
}


Character::~Character()
{
}

// Getters
std::string Character::GetName()
{
	return name;
}

int Character::GetLevel()
{
	return level;
}

int Character::GetMaxHp()
{
	return maxHp;
}

int Character::GetHp()
{
	return hp;
}

int Character::RandomNumber(int max)
{
	return std::uniform_int_distribution<int>(0, max)(rng);
}

int Character::RandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}