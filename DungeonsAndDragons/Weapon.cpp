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
	switch (itemNumber)
	{
	case 1: Item::name = "Dagger"; break;
	case 2: Item::name = "Hatchet"; break;
	case 3: Item::name = "Mace"; break;
	case 4: Item::name = "Sword"; break;
	case 5: Item::name = "Longsword"; break;
	case 6: Item::name = "Scimitar"; break;
	case 7: Item::name = "Warhammer"; break;
	case 8: Item::name = "Halberd"; break;
	case 9: Item::name = "Rapier"; break;
	case 10: Item::name = "Spear"; break;
	}

	// Base attack increase
	Item::ItemIncrement = 2;
	if (itemLevel > 0)
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
