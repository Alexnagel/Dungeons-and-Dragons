#include "stdafx.h"
#include "Armour.h"


Armour::Armour()
{
}

Armour::Armour(int floor)
{
	GenerateItem(Item::RandomNumber(10), floor);
}

Armour::Armour(int itemNumber, int itemLevel)
{
	GenerateItem(itemNumber, itemLevel);
}

Armour::~Armour()
{
}

// Functions
void Armour::GenerateItem(int itemNumber, int itemLevel)
{
	itemLevel++;
	switch (itemLevel)
	{
	case 1: Item::name = "Scout"; break;
	case 2: Item::name = "Pathfinder"; break;
	case 3: Item::name = "Trickster"; break;
	case 4: Item::name = "Average"; break;
	case 5: Item::name = "Better"; break;
	case 6: Item::name = "Steel"; break;
	case 7: Item::name = "Gold"; break;
	case 8: Item::name = "Pro"; break;
	case 9: Item::name = "Elite"; break;
	case 10: Item::name = "Elite Black"; break;
	}

	switch (itemNumber)
	{
	case 1: Item::name.append(" Orc Shield"); break;
	case 2: Item::name.append(" Necromancer Robe"); break;
	case 3: Item::name.append(" Combat Robe"); break;
	case 4: Item::name.append(" Helm"); break;
	case 5: Item::name.append(" Torva Gloves"); break;
	case 6: Item::name.append(" Sirenic Boots"); break;
	case 7: Item::name.append(" Skeletal Chestplate"); break;
	case 8: Item::name.append(" Bandos Warshield"); break;
	case 9: Item::name.append(" Knight Chainmail"); break;
	case 10: Item::name.append(" Adamant Gloves"); break;
	}

	// set base hp increment
	Item::ItemIncrement = 3;
	switch (itemLevel)
	{
	case 1: Item::ItemIncrement *= 1.2; break;
	case 2: Item::ItemIncrement *= 1.5; break;
	case 3: Item::ItemIncrement *= 1.7; break;
	case 4: Item::ItemIncrement *= 2; break;
	case 5: Item::ItemIncrement *= 2.4; break;
	case 6: Item::ItemIncrement *= 2.9; break;
	case 7: Item::ItemIncrement *= 3; break;
	case 8: Item::ItemIncrement *= 3.3; break;
	case 9: Item::ItemIncrement *= 4; break;
	default: break;
	}

	// Set the item level and type
	Item::level = std::to_string(itemLevel);
	Item::itemType = ItemType::ArmourItem;
	Item::ItemId = itemNumber;
}

void Armour::Equiped(bool p_equiped)
{
	equiped = p_equiped;
}

bool Armour::IsEquiped()
{
	return equiped;
}