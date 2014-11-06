#pragma once
#include <unordered_map>
#include <memory>
#include "Item.h"

class Chest
{
private:
	typedef std::unordered_map<std::string, Item> chestMap;
	chestMap chestItems;
public:
	Chest();
	virtual ~Chest();

	std::string ListItems();
	Item GetItem(std::string itemName);
	void AddItem(Item item);
};

