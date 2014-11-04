#include "stdafx.h"
#include "Floor.h"

Floor::Floor()
{
}

Floor::Floor(std::vector<std::vector<std::shared_ptr<Room>>> floorVector) :vFloor(floorVector)
{
}

Floor& Floor::operator=(const Floor& other)
{
	if (this != &other)
	{
		Floor* cSymbol = new Floor(other);
		return *cSymbol;

	}
	return *this;
}

std::string Floor::PrintFloor()
{
	std::string output;
	for (int y = 0; y < vFloor.size(); y++)
	{
		std::string rowTopstring = "";
		std::string rowstring = "";
		std::vector<std::shared_ptr<Room>> vRow = vFloor.at(y);
		for (int x = 0; x < vRow.size(); x++)
		{
			std::shared_ptr<Room> currentRoom = vRow.at(x);
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

std::shared_ptr<Room> Floor::GetRoom(int x, int y)
{
	std::vector<std::shared_ptr<Room>> row = vFloor.at(y);
	return row.at(x);
}

std::shared_ptr<Room> Floor::GetStartRoom()
{
	for (int y = 0; y < vFloor.size(); y++)
	{
		std::vector<std::shared_ptr<Room>> vRow = vFloor.at(y);
		for (int x = 0; x < vRow.size(); x++)
		{
			std::shared_ptr<Room> room = std::shared_ptr<Room>(vRow.at(x));
			if (room->GetStart())
			{
				room->SetVisited();
				return room;
			}
			room.reset();
		}
	}
}

Floor::~Floor()
{
	vFloor.clear();
}
