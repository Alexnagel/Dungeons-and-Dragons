#include "stdafx.h"
#include "Floor.h"

Room* Rooms[GameManager::NUMBER_OF_ROOMS_X][GameManager::NUMBER_OF_ROOMS_Y];


Floor::Floor()
{
}

Floor::Floor(Room* rooms[GameManager::NUMBER_OF_ROOMS_X][GameManager::NUMBER_OF_ROOMS_Y])
{
	int rows = GameManager::NUMBER_OF_ROOMS_X;
	int cols = GameManager::NUMBER_OF_ROOMS_Y;
	for (int row = 0; row < rows; row++)
	{
		std::vector<Room*> vRow;
		for (int col = 0; col < cols; col++)
		{
			vRow.push_back(rooms[row][col]);
		}
		vRooms.push_back(vRow);
	}
}

void Floor::PrintFloor()
{
	for (int y = 0; y < vRooms.size(); y++)
	{
		std::string rowTopstring = "";
		std::string rowstring = "";
		std::vector<Room*> vRow = vRooms.at(y);
		for (int x = 0; x < vRow.size(); x++)
		{
			Room* currentRoom = vRow.at(x);
			std::array<bool, 2>connections = currentRoom->GetConnections();

			if (!currentRoom->IsVisited())
			{
				if (connections[0])
					rowTopstring.append("  |");
				else
					rowTopstring.append("   ");

				if (connections[1])
					rowstring.append("--");
				else
					rowstring.append("  ");

				rowstring.append(currentRoom->RoomCharacter());
			}
			else
			{
				rowTopstring.append("   ");
				rowstring.append(".");
			}
		}
		std::cout << rowTopstring << std::endl;
		std::cout << rowstring << std::endl;
	}
}

Room* Floor::GetRoom(int x, int y)
{
	std::vector<Room*> row = vRooms.at(y);
	return row.at(x);
}

Room* Floor::GetStartRoom()
{
	for (int y = 0; y < vRooms.size(); y++)
	{
		std::vector<Room*> vRow = vRooms.at(y);
		for (int x = 0; x < vRow.size(); x++)
		{
			if (vRow.at(x)->RoomCharacter() == "S")
				return vRow.at(x);
		}
	}
}

Floor::~Floor()
{
}
