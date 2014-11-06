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

std::string Item::GetLevel()
{
	return level;
}

int Item::GetIncrement()
{
	return ItemIncrement;
}

ItemType Item::GetItemType()
{
	return itemType;
}

void Item::GenerateItem(int itemNumber, int itemLevel)
{

}

int Item::RandomNumber(int max)
{
	return std::uniform_int_distribution<int>(0, max)(rng);
}

int Item::RandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}
