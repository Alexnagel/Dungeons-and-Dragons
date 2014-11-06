#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager() : isRunning(true), level(0), currentRoom(nullptr), dungeon(nullptr)
{
	DungeonGenerator generator;
	dungeon = std::move(generator.CreateDungeon());

	seed = std::random_device()();
	rng = std::mt19937(seed);

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
		Move("Which direction do you want to travel in?");
	else if (input == "attack")
	{
		system("CLS");
		Attack(Battle(currentRoom->GetEnemies(), std::shared_ptr<Player>(player)));
	}
	else if (input == "flee")
		Flee();
	else if (input == "chest")
		PrintChest();
	else if (input == "take")
		TakeItem();
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

void GameManager::Move(std::string txt)
{
	std::string direction;
	std::cout << txt << std::endl;
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

void GameManager::Attack(Battle battle)
{
	std::cout << "You entered the battle!!" << std::endl << std::endl;
	std::cout << "Options: Flee, Attack, Potion, Item" << std::endl;

	std::string input;
	while (!battle.Finished())
	{
		std::cin >> input;
		system("CLS");
		input = Utils::ToLowerCase(input);

		if (input == "flee")
		{
			if (RandomNumber(100) > 50) 
			{
				std::cout << "You failed to run away!" << std::endl;
				std::cout << battle.EnemyAttack() << std::endl;
			}
			else
				Move("Which direction are you running too?");
		}
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
	if (currentRoom->GetEnemies().size() > 0)
	{
		if (RandomNumber(100) > 50)
		{
			std::cout << "The enemies notice you when you try to run and attack you!" << std::endl;
			Attack(Battle(currentRoom->GetEnemies(), std::shared_ptr<Player>(player)));
		}
		else
		{
			Move("Which direction are you running too?");
		}
	}
}

void GameManager::Rest()
{
	if (currentRoom->GetEnemies().size() == 0)
	{
		if (canRest)
		{
			std::cout << "Your player is resting...." << std::endl;

			if (RandomNumber(100) > 90)
			{
				std::cout << "You get disturbed while resting" << std::endl;
				std::cout << "An agressive enemy appeared and attacks you!" << std::endl;
				std::vector<std::shared_ptr<Enemy>> enemies;
				enemies.push_back(std::make_shared<Enemy>(Enemy(level)));
				Attack(Battle(enemies, std::shared_ptr<Player>(player)));
			}
			else
			{
				player->Rest();
				std::cout << "Your player now has " << player->GetHp() << " HP." << std::endl;
				canRest = false;
			}
		}
		else
			std::cout << "You did already rest this turn." << std::endl;
	}
	else
		std::cout << "You can't rest with enemies in the room." << std::endl;
}

void GameManager::PrintChest()
{
	std::cout << currentRoom->PrintChest();
}

void GameManager::TakeItem()
{
	std::string itemName;
	std::cout << "Which item do you want to put in your backpack?" << std::endl;
	std::cin.ignore(1000, '\n');
	std::getline(std::cin, itemName);

	itemName = Utils::ToLowerCase(itemName);
	Item item = currentRoom->GetChestItem(itemName);

	if (!item.GetName().empty())
	{
		player->AddToBackpack(item);
		std::cout << item.GetName() << " was added to your backpack" << std::endl;
	}
	else
		std::cout << "This item is not in the chest, try again" << std::endl;
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

int GameManager::RandomNumber(int max)
{
	return std::uniform_int_distribution<int>(0, max)(rng);
}