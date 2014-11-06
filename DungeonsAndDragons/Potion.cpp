#include "stdafx.h"
#include "Potion.h"


Potion::Potion()
{
}

Potion::Potion(int floor)
{
	GenerateItem(Item::RandomNumber(5), floor);
}

Potion::Potion(int itemNumber, int itemLevel)
{
	GenerateItem(itemNumber, itemLevel);
}

Potion::~Potion()
{
}

void Potion::GenerateItem(int itemNumber, int itemLevel)
{
	switch (itemNumber)
	{
	case 1: Item::name = "Health Pot"; break;
	case 2: Item::name = "Saradomin Brew"; break;
	case 3: Item::name = "Juju Power Potion"; break;
	case 4: Item::name = "Guthix Balm"; break;
	case 5: Item::name = "Cadava Serum"; break;
	}

	// base hp increment
	Item::ItemIncrement = 10;
	if (itemLevel > 0)
		Item::ItemIncrement *= (itemLevel / 2);

	// Set the item level and type
	Item::level = std::to_string(itemLevel);
	Item::itemType = ItemType::HealthItem;
}
