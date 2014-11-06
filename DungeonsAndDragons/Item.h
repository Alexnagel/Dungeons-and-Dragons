#pragma once
#include <random>
#include <string>
#include "ItemType.h"

class Item
{

protected:
	int seed;
	std::mt19937 rng;
	int RandomNumber(int max);
	int RandomNumber(int min, int max);

	ItemType itemType;
	std::string name;
	std::string level;
	int ItemIncrement;
	virtual void GenerateItem(int itemNumber, int itemLevel);

public:
	Item();
	virtual ~Item();

	// Functions
	std::string GetName();
	std::string GetLevel();
	int GetIncrement();
	ItemType GetItemType();
};

