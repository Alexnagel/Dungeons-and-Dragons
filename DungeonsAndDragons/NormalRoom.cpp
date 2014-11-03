#include "stdafx.h"
#include "NormalRoom.h"


NormalRoom::NormalRoom(int level)
	:Room(level)
{
	seed = std::random_device()();
	rng = std::mt19937(seed);
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

void NormalRoom::PrintEnemies()
{
	if (!enemies.empty())
	{
		std::cout << std::endl << "There are " + std::to_string(enemies.size()) + " enemies in the room: ";
		for (Enemy* enemy : enemies)
		{
			std::cout << std::endl;
			std::cout << enemy->GetName() << ", Level: " << enemy->GetLevel() << ", HP: " << enemy->GetHp() << ", XP: " << enemy->GetXp();
		}
		std::cout << std::endl;
	}
	else
		std::cout << std::endl << "There are no enemies in the room" << std::endl; 
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

NormalRoom::~NormalRoom()
{
}
