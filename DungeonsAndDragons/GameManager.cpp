#include "stdafx.h"
#include "GameManager.h"

std::default_random_engine GameManager::random;

GameManager::GameManager() : isRunning(true), level(0), currentRoom(nullptr), dungeon(nullptr)
{
	DungeonGenerator generator;
	dungeon = std::move(generator.CreateDungeon());

	// Start handling user input
	std::string input;
	std::cout << "To start the game enter \"Start\", to quit the game enter \"Quit\"." << std::endl;
	std::cout << "You can find all the commands by entering \"Help\"." << std::endl;
	while (isRunning)
	{
		std::cin >> input;
		HandleInput(input);
	}
}

GameManager::~GameManager()
{
}

#pragma region Print functions
void GameManager::PrintFloor()
{
	// Print the floor map
	std::cout << "Floor map:" << std::endl;
	std::shared_ptr<Floor> floor = dungeon->GetFloor(level);
	std::cout << floor->PrintFloor();
	
	// Print the legend
	std::cout << std::endl << std::endl;
	std::cout << "Legend:" << std::endl;
	std::cout << "|-- : Gangen" << std::endl;
	std::cout << "S   : Start" << std::endl;
	std::cout << "B   : Boss room" << std::endl;
	std::cout << "R   : Normal room" << std::endl;
	std::cout << "U   : Staircase up" << std::endl;
	std::cout << "D   : Staircase down" << std::endl;
	std::cout << ".   : Undiscovered room" << std::endl;
	std::cout << std::endl;
}

void GameManager::PrintRoom(int x, int y)
{
	std::shared_ptr<Room> room = dungeon->GetRoom(level, x, y);
	room->Print();
	room.reset();
}
#pragma endregion

#pragma region User input
void GameManager::HandleInput(std::string input)
{
	input = Utils::ToLowerCase(input);

	if (input == "move")
		Move();
	else if (input == "attack")
		Attack();
	else if (input == "flee")
		Flee();
	else if (input == "start")
		StartGame();
	else if (input == "quit")
		QuitGame();
	else if (input == "map")
		PrintFloor();
	else if (input == "help")
		Help();
	else if (input == "player_info")
		PlayerStats();
	else if (input == "rest")
		Rest();
}

void GameManager::PlayerStats()
{
	std::cout << std::endl << "------ Player Info ------" << std::endl << std::endl;
	std::cout << player->Print() << std::endl;
}

void GameManager::Move()
{
	std::string direction;
	std::cout << "Which direction do you want to travel in?" << std::endl;
	std::cout << currentRoom->GetDirections() << std::endl << std::endl;
	std::cin >> direction;

	direction = Utils::ToLowerCase(direction);
	if (direction == "north" && currentRoom->ContainsRoom(Direction::NORTH))
	{
		std::shared_ptr<Room> nextRoom = std::shared_ptr<Room>(currentRoom->GoInDirection(Direction::NORTH));
		currentRoom.reset();
		currentRoom = nextRoom;
	}
	else if (direction == "east" && currentRoom->ContainsRoom(Direction::EAST))
	{
		std::shared_ptr<Room> nextRoom = std::shared_ptr<Room>(currentRoom->GoInDirection(Direction::EAST));
		currentRoom.reset();
		currentRoom = nextRoom;
	}
	else if (direction == "south" && currentRoom->ContainsRoom(Direction::SOUTH))
	{
		std::shared_ptr<Room> nextRoom = std::shared_ptr<Room>(currentRoom->GoInDirection(Direction::SOUTH));
		currentRoom.reset();
		currentRoom = nextRoom;
	}
	else if (direction == "west" && currentRoom->ContainsRoom(Direction::WEST))
	{
		std::shared_ptr<Room> nextRoom = std::shared_ptr<Room>(currentRoom->GoInDirection(Direction::WEST));
		currentRoom.reset();
		currentRoom = nextRoom;
	}
	else if (direction == "up")
	{
		std::shared_ptr<Room> nextRoom = dungeon->GetStaircaseUp(level++);
		currentRoom.reset();
		currentRoom = nextRoom;
	}
	else if (direction == "down")
	{
		std::shared_ptr<Room> nextRoom = dungeon->GetStaircaseDown(level--);
		currentRoom.reset();
		currentRoom = nextRoom;
	}
	else
	{
		std::cout << "You can't move in this direction" << std::endl << std::endl;
		return;
	}
	// set the room as visited
	system("CLS");
	currentRoom->SetVisited();
	canRest = true;

	// Print the new room if the player has moved
	std::cout << std::endl;
	std::cout << currentRoom->Print() << std::endl;
}

void GameManager::Attack()
{
	system("CLS");
	std::cout << "You entered the battle!!" << std::endl << std::endl;
	std::cout << "Options: Flee, Attack, Potion, Item" << std::endl;

	battle = Battle(currentRoom->GetEnemies(), std::shared_ptr<Player>(player));

	std::string input;
	while (!battle.Finished())
	{
		std::cin >> input;
		system("CLS");
		input = Utils::ToLowerCase(input);

		if (input == "flee")
			std::cout << battle.Flee() << std::endl;
		else if (input == "attack")
			std::cout << battle.Attack() << std::endl;
		else if (input == "potion")
			std::cout << battle.UsePotion() << std::endl;
		else if (input == "item")
			std::cout << battle.UseItem() << std::endl;
	}

	if (player->GetHp() > 0)
	{
		std::cout << battle.Won() << std::endl << std::endl;
		currentRoom->DefeatedEnemies();

		// Check if the player has leveled
		if (player->IsLeveled())
		{
			player->LevelUp();
		}

		// Print the room again
		std::cout << currentRoom->Print() << std::endl;
	}
	else
	{
		isRunning = false;
	}	
}

void GameManager::Flee()
{

}

void GameManager::Rest()
{
	if (canRest)
	{
		std::cout << "Your player is resting...." << std::endl;
		player->Rest();
		std::cout << "Your player now has " << player->GetHp() << " HP." << std::endl;
		canRest = false;
	}
	else
		std::cout << "You did already rest this turn." << std::endl;
}

void GameManager::StartGame()
{
	std::string name;

	system("CLS");
	std::cout << "What is your name hero?" << std::endl;
	std::cin >> name;

	// Create the hero
	player = std::make_shared<Player>(Player(name));
	system("CLS");

	// Start the game
	currentRoom = std::shared_ptr<Room>(dungeon->GetStartRoom());
	std::cout << "Welcome " << player->GetName() << ", your epic journey will start from here!" << std::endl;
	std::cout << std::endl;
	std::cout << currentRoom->Print() << std::endl;
}

void GameManager::QuitGame()
{
	std::string input;
	std::cout << "Are you sure you want to quit this epic game?? (YES / NO)" << std::endl;
	std::cin >> input;

	input = Utils::ToLowerCase(input);

	if (input == "yes")
		isRunning = false;
}

void GameManager::Help()
{
	std::cout << std::endl << "------ Help ------" << std::endl << std::endl;
	std::cout << "Start       : Starts a new game." << std::endl;
	std::cout << "Quit        : Ends the game." << std::endl;
	std::cout << "Move        : You can move to a new room." << std::endl;
	std::cout << "Attack      : You will attack the enemies in the room." << std::endl;
	std::cout << "Flee        : You try to run from the enemies." << std::endl;
	std::cout << "Player_info : Check your hero his current stats." << std::endl;
	std::cout << "Rest        : Your hero can regain 50% of his total health." << std::endl;
	std::cout << "Map         : Prints a map of your current floor and a legend." << std::endl;
	std::cout << "Help        : Shows you all the commands." << std::endl;
	std::cout << std::endl;
}
#pragma endregion
