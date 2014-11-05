#pragma once
#include "Item.h"
class Weapon :
	public Item
{
private:
	bool equiped;
	int attack;

public:
	Weapon();
	virtual ~Weapon();

	// Functions
	void Equiped(bool p_equiped);
	bool IsEquiped();
	int GetAttack();
};

