#pragma once

#include <vector>

#include "Character.h"
#include "Item.h"
#include "Armour.h"
#include "Weapon.h"

class Player : public Character
{
private:
	int xp;
	int attack;
	int defence;
	std::vector<Item> backpack;
	Weapon weapon;
	Armour armour;

public:
	Player();
	Player(std::string name);
	virtual ~Player();

	// Functions
	std::vector<Item> GetBackpack();
	Weapon GetEquipedWeapon();
	Armour GetEquipedArmour();
	void SetWeapon(Weapon weapon);
	void SetArmour(Armour armour);
	bool ContainsPotion();

	int Attack();
	int Hit(int damage);
};

