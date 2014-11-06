#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon() : attack(1)
{
}

Weapon::Weapon(int floor)
{
	GenerateItem(Item::RandomNumber(10), floor);
}

Weapon::Weapon(int itemNumber, int itemLevel)
{
	GenerateItem(itemNumber, itemLevel);
}


Weapon::~Weapon()
{
}

// Functions
void Weapon::GenerateItem(int itemNumber, int itemLevel)
{
	itemLevel++;
	switch (itemLevel)
	{
	case 1: Item::name = "Wooden"; break;
	case 2: Item::name = "Stone"; break;
	case 3: Item::name = "Bronze"; break;
	case 4: Item::name = "Iron"; break;
	case 5: Item::name = "Steel"; break;
	case 6: Item::name = "Black"; break;
	case 7: Item::name = "Mithril"; break;
	case 8: Item::name = "Blessed"; break;
	case 9: Item::name = "Adament"; break;
	case 10: Item::name = "Volatile"; break;
	}

	switch (itemNumber)
	{
	case 1: Item::name.append(" Dagger"); break;
	case 2: Item::name.append(" Hatchet"); break;
	case 3: Item::name.append(" Mace"); break;
	case 4: Item::name.append(" Sword"); break;
	case 5: Item::name.append(" Longsword"); break;
	case 6: Item::name.append(" Scimitar"); break;
	case 7: Item::name.append(" Warhammer"); break;
	case 8: Item::name.append(" Halberd"); break;
	case 9: Item::name.append(" Rapier"); break;
	case 10: Item::name.append(" Spear"); break;
	}

	// Base attack increase
	Item::ItemIncrement = 2;
	Item::ItemIncrement *= itemLevel;

	Item::level = std::to_string(itemLevel);
	Item::itemType = ItemType::WeaponItem;
}

void Weapon::Equiped(bool p_equiped)
{
	equiped = p_equiped;
}

bool Weapon::IsEquiped()
{
	return equiped;
}

int Weapon::GetAttack()
{
	return attack;
}
