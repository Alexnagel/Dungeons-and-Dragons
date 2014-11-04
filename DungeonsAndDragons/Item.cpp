#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	seed = std::random_device()();
	rng = std::mt19937(seed);
}


Item::~Item()
{
}

// Functions
std::string Item::GetName()
{
	return name;
}

int Item::RandomNumber(int max)
{
	return std::uniform_int_distribution<int>(0, max)(rng);
}

int Item::RandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}
