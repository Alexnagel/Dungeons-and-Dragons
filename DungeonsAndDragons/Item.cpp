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

std::string Item::GetItemId()
{
	return std::to_string(ItemId);
}

int Item::GetIncrement()
{
	return ItemIncrement;
}

std::string Item::GetIncrementType()
{
	switch (itemType)
	{
	case ItemType::ArmourItem: return "armour"; break;
	case ItemType::WeaponItem: return "damage"; break;
	case ItemType::HealthItem: return "health"; break;
	}
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
