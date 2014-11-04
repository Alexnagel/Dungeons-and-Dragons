#include "stdafx.h"
#include "NormalRoom.h"


NormalRoom::NormalRoom(int level)
	:Room(level)
{
	seed = std::random_device()();
	rng = std::mt19937(seed);

	RandomizeEnemies();
}

void NormalRoom::GenerateChest()
{

}

void NormalRoom::RandomizeEnemies()
{
	int enemyAmount = RandomNumber(MAX_ENEMIES);
	for (int i = 0; i < enemyAmount; i++)
	{
		// add floornumber for difficulty
		enemies.push_back(new Enemy());
	}
}

std::string NormalRoom::PrintEnemies()
{
	std::string output;
	if (!enemies.empty())
	{
		output.append("There are " + std::to_string(enemies.size()) + " enemies in the room: \n");
		for (Enemy* enemy : enemies)
		{
			output.append(enemy->GetName() + ", Level: " + std::to_string(enemy->GetLevel()) + ", HP: " + std::to_string(enemy->GetHp()) + ", XP: " + std::to_string(enemy->GetXp()) + "\n");
		}
	}
	else
		output.append("There are no enemies in the room\n");

	return output;
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

std::string NormalRoom::Print()
{
	std::string output = description + "\n";
	if (directions.empty())
		SetDirections();

	output.append(directions + "\n\n");
	output.append(PrintEnemies());

	return output;
}

NormalRoom::~NormalRoom()
{
	enemies.clear();
	delete chest;
	chest = nullptr;
}
