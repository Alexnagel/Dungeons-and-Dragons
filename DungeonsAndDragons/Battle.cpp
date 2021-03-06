#include "stdafx.h"
#include "Battle.h"


Battle::Battle() : enemies(std::vector<std::shared_ptr<Enemy>>()), player(std::shared_ptr<Player>()), finished(false)
{
}

Battle::Battle(std::vector<std::shared_ptr<Enemy>> p_enemies, std::shared_ptr<Player> p_player) : enemies(p_enemies), player(p_player), finished(false)
{
}

Battle::~Battle()
{
}

// Functions
std::string Battle::Flee()
{
	std::string result;

	finished = true;

	return result;
}

std::string Battle::Attack()
{
	std::string result;

	// Player attacks enemies
	bool won = true;
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies.at(i)->GetHp() > 0)
		{
			int damage = player->Attack();
			int hpLeft = enemies.at(i)->Hit(damage);

			if (damage == 0)
				result.append("You missed the " + enemies.at(i)->GetName() + "\n");
			else
				result.append("You hit the " + enemies.at(i)->GetName() +
				" with " + std::to_string(damage) +
				" it has " + std::to_string(hpLeft) + " hp left.\n");

			if (hpLeft > 0)
				won = false;
		}
	}

	result.append("\n");

	if (!won)
	{
		// Enemies attack player
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies.at(i)->GetHp() > 0)
			{
				int damage = enemies.at(i)->Attack();
				int hpLeft = player->Hit(damage);

				if (damage == 0)
					result.append("The " + enemies.at(i)->GetName() + " missed.\n");
				else
					result.append("The " + enemies.at(i)->GetName() +
					" hit you with " + std::to_string(damage) +
					" You have " + std::to_string(hpLeft) + " hp left.\n");
			}

			if (player->GetHp() == 0)
			{
				result.append("You died in this fearsome battle!");
				finished = true;
				return result;
			}
		}
	}
	else
	{
		finished = true;
	}
	
	return result;
}

std::string Battle::EnemyAttack()
{
	std::string result;
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies.at(i)->GetHp() > 0)
		{
			int damage = enemies.at(i)->Attack();
			int hpLeft = player->Hit(damage);

			if (damage == 0)
				result.append("The " + enemies.at(i)->GetName() + " missed.\n");
			else
				result.append("The " + enemies.at(i)->GetName() +
				" hit you with " + std::to_string(damage) +
				" You have " + std::to_string(hpLeft) + " hp left.\n");
		}

		if (player->GetHp() == 0)
		{
			result.append("You died in this fearsome battle!");
			finished = true;
			return result;
		}
	}
	return result;
}

// TODO!!!
std::string Battle::UsePotion()
{
	return player->UsePotion();
}

std::string Battle::UseItem()
{
	std::string result;

	// Open backpack
	// Let the player choose an item or cancel.
	// Use the item, or do nothing

	return result;
}

std::string Battle::Won()
{
	int xp = 0;
	for (int i = 0; i < enemies.size(); i++)
	{
		xp += enemies.at(i)->GetXp();
	}

	std::string result = "You defeated all enemies! you gained " + std::to_string(xp) + " xp!\n\n";
	result.append(player->GainedXp(xp));
	return result;
}

bool Battle::Finished()
{
	return finished;
}
