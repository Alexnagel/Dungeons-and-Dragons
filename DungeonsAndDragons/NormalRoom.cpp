#include "stdafx.h"
#include "NormalRoom.h"


NormalRoom::NormalRoom(int level)
	:Room(level)
{
	seed = std::random_device()();
	rng = std::mt19937(seed);

	hasChest = false;

	RandomizeEnemies();
	GenerateChest();
}

NormalRoom::NormalRoom(int level, bool isStart)
:Room(level, isStart)
{
	seed = std::random_device()();
	rng = std::mt19937(seed);

	RandomizeEnemies();
}

void NormalRoom::GenerateChest()
{
	int chestChance = RandomNumber(100);
	if (chestChance < CHANCE_CHEST)
	{
		hasChest = true;
		description.append("\n The room contains a chest.");
		int itemAmount = RandomNumber(MAX_ITEMS);
		for (int i = 0; i < itemAmount; i++)
		{
			int itemType = RandomNumber(2);
			switch (itemType)
			{
			case 0: chest.AddItem(Weapon(level)); break;
			case 1: chest.AddItem(Potion(level)); break;
			case 2: chest.AddItem(Armour(level)); break;
			default:
				break;
			}
		}
	}
}

void NormalRoom::RandomizeEnemies()
{
	int enemyAmount = RandomNumber(MAX_ENEMIES);
	for (int i = 0; i < enemyAmount; i++)
	{
		// add floornumber for difficulty
		enemies.push_back(std::make_shared<Enemy>(Enemy(level)));
	}
}

std::string NormalRoom::PrintEnemies()
{
	std::string output;
	if (!enemies.empty())
	{
		if (enemies.size() > 1)
			output.append("There are " + std::to_string(enemies.size()) + " enemies in the room: \n");
		else
			output.append("There is " + std::to_string(enemies.size()) + " enemy in the room: \n");

		for (std::shared_ptr<Enemy> enemy : enemies)
		{
			output.append(enemy->GetName() + ", Level: " + std::to_string(enemy->GetLevel()) + ", HP: " + std::to_string(enemy->GetMaxHp()) + ", XP: " + std::to_string(enemy->GetXp()) + "\n");
		}
	}
	else
		output.append("There are no enemies in the room\n");

	return output;
}

std::string NormalRoom::PrintChest()
{
	return chest.ListItems();
}

Item NormalRoom::GetChestItem(std::string itemName)
{
	return chest.GetItem(itemName);
}

std::string NormalRoom::RoomCharacter()
{
	if (Room::roomIsStart)
		return "S";
	else
		return "R";
}

int NormalRoom::RandomNumber(int max)
{
	return std::uniform_int_distribution<int>(0, max)(rng);
}

std::vector<std::shared_ptr<Enemy>> NormalRoom::GetEnemies()
{
	return enemies;
}

void NormalRoom::DefeatedEnemies()
{
	enemies.clear();
}

std::string NormalRoom::GetOptions()
{
	std::string options;

	if (enemies.size() > 0)
		options.append("Attack, Flee, ");
	else
		options.append("Move, Rest, ");

	if (hasChest)
		options.append("Chest");

	return options;
}

std::string NormalRoom::Print()
{
	std::string output = description + "\n";
	if (directions.empty())
		SetDirections();

	output.append(directions + "\n\n");
	output.append(PrintEnemies() + "\n");

	output.append("Options: " + GetOptions() + "\n"); // print options

	return output;
}

NormalRoom::~NormalRoom()
{
}
