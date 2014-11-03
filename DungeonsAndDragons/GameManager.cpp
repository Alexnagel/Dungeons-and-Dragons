#include "stdafx.h"
#include "GameManager.h"

std::default_random_engine GameManager::random;

GameManager::GameManager() : isRunning(true), level(0)
{
	DungeonGenerator generator;
	dungeon = generator.CreateDungeon();

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
	std::cout << "Floor map:" << std::endl;
	Floor* floor = dungeon->GetFloor(level);

	// Print the floor
	floor->PrintFloor();

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
}

void GameManager::PrintRoom(int x, int y)
{
	Room* room = dungeon->GetRoom(level, x, y);
	room->Print();
	// TODO: print the room "room.print();"
}
#pragma endregion

#pragma region User input
void GameManager::HandleInput(std::string input)
{
	input = ToLowerCase(input);

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
}

void GameManager::Move()
{
	std::string direction;
	std::cout << "Which direction do you want to travel to?" << std::endl;
	std::cout << currentRoom->GetDirections() << std::endl;
	std::cin >> direction;

	direction = ToLowerCase(direction);
	if (direction == "north" && currentRoom->ContainsRoom(Direction::NORTH))
		currentRoom = &currentRoom->GoInDirection(Direction::NORTH);
	else if (direction == "east" && currentRoom->ContainsRoom(Direction::EAST))
		currentRoom = &currentRoom->GoInDirection(Direction::EAST);
	else if (direction == "south" && currentRoom->ContainsRoom(Direction::SOUTH))
		currentRoom = &currentRoom->GoInDirection(Direction::SOUTH);
	else if (direction == "west" && currentRoom->ContainsRoom(Direction::WEST))
		currentRoom = &currentRoom->GoInDirection(Direction::WEST);
	else
	{
		std::cout << "You can't move to this direction" << std::endl;
		return;
	}

	// Print the new room if the player has moved
	currentRoom->Print();
}

void GameManager::Attack()
{

}

void GameManager::Flee()
{

}

void GameManager::StartGame()
{
	std::string name;

	system("CLS");
	std::cout << "What is your name hero?" << std::endl;
	std::cin >> name;

	// Create the hero
	player = Player(name);
	system("CLS");

	// Start the game
	currentRoom = dungeon->GetStartRoom();
	std::cout << "Welcome " << player.GetName() << ", your epic journey will start from here!" << std::endl;
}

void GameManager::QuitGame()
{
	std::string input;
	std::cout << "Are you sure you want to quit this epic game?? (YES / NO)" << std::endl;
	std::cin >> input;

	input = ToLowerCase(input);

	if (input == "yes")
		isRunning = false;
}

void GameManager::Help()
{
	std::cout << std::endl << std::endl << "------ Help ------" << std::endl << std::endl;

	std::cout << "Start:       Starts a new game" << std::endl;
	std::cout << "Quit:        Ends the game" << std::endl;
	std::cout << "Map:         Prints a map of your current floor and a legend" << std::endl;
	std::cout << "Help:        Shows you all the commands" << std::endl;
	std::cout << std::endl;
}

std::string GameManager::ToLowerCase(std::string string)
{
	for (int i = 0; i < string.length(); i++)
	{
		string[i] = tolower(string[i]);
	}
	return string;
}
#pragma endregion
