#include "stdafx.h"
#include "Floor.h"

Floor::Floor()
{
}

Floor::Floor(std::vector<std::vector<Room*>> floorVector) :vFloor(floorVector)
{
}

std::string Floor::PrintFloor()
{
	std::string output;
	for (int y = 0; y < vFloor.size(); y++)
	{
		std::string rowTopstring = "";
		std::string rowstring = "";
		std::vector<Room*> vRow = vFloor.at(y);
		for (int x = 0; x < vRow.size(); x++)
		{
			Room* currentRoom = vRow.at(x);
			std::array<bool, 2>connections = currentRoom->GetConnections();

			// If the room is visited print room type and connection
			if (currentRoom->IsVisited())
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
				rowstring.append("  .");
			}
		}
		output.append(rowTopstring + "\n");
		output.append(rowstring + "\n");
	}
	return output;
}

Room* Floor::GetRoom(int x, int y)
{
	std::vector<Room*> row = vFloor.at(y);
	return row.at(x);
}

Room* Floor::GetStartRoom()
{
	for (int y = 0; y < vFloor.size(); y++)
	{
		std::vector<Room*> vRow = vFloor.at(y);
		for (int x = 0; x < vRow.size(); x++)
		{
			if (vRow.at(x)->GetStart())
			{
				vRow.at(x)->SetVisited();
				return vRow.at(x);
			}
		}
	}
}

Floor::~Floor()
{
	vFloor.clear();
}
