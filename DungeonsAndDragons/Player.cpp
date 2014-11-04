#include "stdafx.h"
#include "Player.h"


Player::Player()
{

}

Player::Player(std::string p_name)
{
	name = p_name;
	hp = 100;
	level = 1;
	attack = 1;
	defence = 1;
}


Player::~Player()
{
}

// Functions
Weapon Player::GetEquipedWeapon()
{
	return weapon;
}

Armour Player::GetEquipedArmour()
{
	return armour;
}

std::vector<Item> Player::GetBackpack()
{
	return backpack;
}

void Player::SetWeapon(Weapon p_weapon)
{
	weapon.Equiped(false);
	p_weapon.Equiped(true);
	weapon = p_weapon;
}

void Player::SetArmour(Armour p_armour)
{
	armour.Equiped(false);
	p_armour.Equiped(true);
	armour = p_armour;
}

bool Player::ContainsPotion()
{
	for (int i = 0; i < backpack.size(); i++)
	{
		// Check for instance..
	}
	return false;
}

int Player::Attack()
{
	// Gebruik een random getal, of de enemy mist of niet?
	int result = RandomNumber(100);
	if (result < 80)
	{
		// De enemy raakt de tegenstander
		// Bereken het aantal damage dat de tegenstander doet op basis van het level en een random.
		int damage = RandomNumber(1, (attack * 10)) * level;

		return damage;
	}
	else
	{
		return 0;
	}
}

int Player::Hit(int damage)
{
	if (hp > damage)
		hp = hp - damage;
	else
		hp = 0;

	// Return the leftover hp of the enemy
	return hp;
}