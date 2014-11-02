#include "stdafx.h"
#include "Player.h"


Player::Player()
{

}

Player::Player(std::string p_name)
{
	name = p_name;
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

int Player::Attack()
{
	// Gebruik een random getal, of de enemy mist of niet?
	if (50 < 80) // <-- onzin getallen atm...
	{
		// De enemy raakt de tegenstander
		// Bereken het aantal damage dat de tegenstander doet op basis van het level en een random.
		int damage = 0;
		return damage;
	}
	else
	{
		return 0;// The enemy missed
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