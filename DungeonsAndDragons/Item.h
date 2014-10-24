#pragma once
class Item
{
private:
	std::string name;

public:
	Item();
	virtual ~Item();

	// Functions
	std::string GetName();
};

