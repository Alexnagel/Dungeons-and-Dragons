#include "stdafx.h"
#include "Floor.h"

Floor::Floor()
{
}

Floor::Floor(std::vector<std::vector<Room*>> floorVector) :vFloor(floorVector)
{
}

void Floor::PrintFloor()
{
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

Floor::~Floor()
{
	vFloor.clear();
}
