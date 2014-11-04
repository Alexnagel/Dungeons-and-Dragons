#include "stdafx.h"
#include "Armour.h"


Armour::Armour()
{
}

Armour::Armour(int floor)
{

}

Armour::~Armour()
{
}

// Functions
void Armour::Equiped(bool p_equiped)
{
	equiped = p_equiped;
}

bool Armour::IsEquiped()
{
	return equiped;
}