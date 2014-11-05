#include "stdafx.h"
#include "Player.h"


Player::Player()
{

}

Player::Player(std::string p_name)
{
	name = p_name;
	hp = 100;
	xp = 0;
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

std::string Player::ListBackpackContents()
{
	std::string output;
	for (Item item : backpack)
	{
		output.append(" " + item.GetName() + ",");
	}
	if (output.back() == char(','))
		output.pop_back();

	return output;
}

std::vector<Item> Player::GetBackpack()
{
	return backpack;
}

void Player::AddToBackpack(Item toAdd)
{
	backpack.push_back(toAdd);
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

std::string Player::GainedXp(int gained_xp)
{
	xp += gained_xp;
	
	// Check if the player has lvled up!
	std::string result;
	if (xp > pow((level * 50), 2))
	{
		level++;
		result.append("You have leveled up! You are now level: " + std::to_string(level) + "\n");
	}
	
	result.append("You now have " + std::to_string(xp) + " xp\n");
	result.append(std::to_string((int)pow((level * 20), 2) - xp) + " xp left till next level.");
	
	return result;
}

bool Player::ContainsPotion()
{
	for (int i = 0; i < backpack.size(); i++)
	{
		// Check for instance..
	}
	return false;
}

// De onderstaande link zou mss leuk zijn voor het damage systeem.
// http://gamedev.stackexchange.com/questions/45901/ideas-for-attack-damage-algorithm-language-irrelevant
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