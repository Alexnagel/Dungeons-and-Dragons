#include "stdafx.h"
#include "Player.h"


Player::Player()
{

}

Player::Player(std::string p_name)
{
	name = p_name;
	maxHp = 100;
	hp = maxHp;
	xp = 0;
	level = 1;
	attack = 1;
	defence = 1;
	exploring = 1;
	leveled = false;
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
	output = "Backpack contents:\n";
	for (Item item : backpack)
	{
		output.append("- " + item.GetName() + " (Level " + item.GetLevel() +", adds " + std::to_string(item.GetIncrement()) + " " + item.GetIncrementType() + ")\n");
	}
	if (backpack.size() == 0)
		output = "Your backpack is empty \n";
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

std::string Player::EquipItem(std::string itemName)
{
	std::string output;
	output = "There is no item with this name.";
	Item item = Item();

	for (std::vector<Item>::iterator it = backpack.begin(); it != backpack.end(); it++)
	{
		item = *it;
	}

	if (!item.GetName().empty())
	{
		if (item.GetItemType() == ItemType::WeaponItem)
		{
			Weapon weapon = static_cast<Weapon&>(item);
			SetWeapon(weapon);
			output = "Your weapon has been set!";
			output.append("You now have " + std::to_string(attack) + " attack");
		}
		else if (item.GetItemType() == ItemType::ArmourItem)
		{
			Armour armour = static_cast<Armour&>(item);
			SetArmour(armour);
			output = "Your armour has been set! \n";
			output.append("You now have " + std::to_string(defence) + " defence");
		}
		else if (item.GetItemType() == ItemType::HealthItem)
		{
			hp += item.GetIncrement();
			output = "Your health has been increased with " + std::to_string(item.GetIncrement()) + " hp. \n";
			output.append("You now have " + std::to_string(hp) + " hp");
		}
	}

	return output;
}

void Player::SetWeapon(Weapon p_weapon)
{
	if (!weapon.GetName().empty())
	{
		weapon.Equiped(false);
		attack -= weapon.GetIncrement();
	}

	p_weapon.Equiped(true);
	weapon = p_weapon;
	attack += p_weapon.GetIncrement();
}

void Player::SetArmour(Armour p_armour)
{
	if (!armour.GetName().empty())
	{
		armour.Equiped(false);
		defence -= armour.GetIncrement();
	}
	p_armour.Equiped(true);
	armour = p_armour;
	defence += p_armour.GetIncrement();
}

std::string Player::GainedXp(int gained_xp)
{
	xp += gained_xp;
	
	// Check if the player has lvled up!
	std::string result;
	if (xp > pow((level * 50), 2))
	{
		leveled = true;
		result.append("You have leveled up! You are now level: " + std::to_string((level + 1)) + "\n");
	}
	
	result.append("You now have " + std::to_string(xp) + " xp\n");
	if (leveled)
		result.append(std::to_string((int)pow(((level + 1) * 20), 2) - xp) + " xp left till next level.");
	else
		result.append(std::to_string((int)pow((level * 20), 2) - xp) + " xp left till next level.");

	return result;
}

bool Player::IsLeveled()
{
	return leveled;
}

void Player::LevelUp()
{
	std::string result;
	std::cout << "Choose 2 abilities to level up: Attack, Defence, Exploring" << std::endl;
	
	int counter = 0;
	while (counter < 2)
	{
		std::cin >> result;
		result = Utils::ToLowerCase(result);
		if (result == "attack")
		{
			attack++;
			counter++;
			std::cout << "Your attack level is now: " << attack << std::endl;
		}
		else if (result == "defence")
		{
			exploring++;
			counter++;
			std::cout << "Your defence level is now: " << defence << std::endl;
		}
		else if (result == "exploring")
		{
			exploring++;
			counter++;
			std::cout << "Your exploring level is now: " << exploring << std::endl;
		}
	}

	// Raise the player his level and hp
	level++;
	maxHp += 20;
	hp = maxHp;

	// Set leveled up to false
	leveled = false;
}

bool Player::ContainsPotion()
{
	for (int i = 0; i < backpack.size(); i++)
	{
		// Check for instance..
	}
	return false;
}

int Player::GetExploring()
{
	return exploring;
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
		int damage = RandomNumber(1, (attack) * 3);

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

void Player::Rest()
{
	int gainedHp = maxHp / 2;
	if ((hp + gainedHp) > maxHp)
		hp = maxHp;
	else
		hp += gainedHp;
}

std::string Player::Print()
{
	std::string output;
	output.append("Name             :" + name + "\n\n");

	output.append("Level info:\n");
	output.append("Level            :" + std::to_string(level) + "\n");
	output.append("Xp               :" + std::to_string(xp) + "\n");
	output.append("Xp till next lvl :" + std::to_string((int) (pow(((level) * 20), 2)) - xp) + "\n\n");

	output.append("Stats info:\n");
	output.append("Hp               :" + std::to_string(maxHp) + "\n");
	output.append("Current hp       :" + std::to_string(hp) + "\n");
	output.append("Attack           :" + std::to_string(attack) + "\n");
	output.append("Defence          :" + std::to_string(defence) + "\n");
	output.append("Exploring        :" + std::to_string(exploring) + "\n");

	return output;
}