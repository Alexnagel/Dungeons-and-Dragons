#pragma once
#include <unordered_map>
#include "Item.h"

class Chest
{
private:
	typedef std::unordered_map<std::string, Item> chestMap;
	chestMap chestItems;
public:
	Chest();
	virtual ~Chest();

	void ListItems();
	Item GetItem(std::string itemName);
	void AddItem(Item item);
};

