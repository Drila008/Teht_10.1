#pragma once
#include "Equipment.h"

class Armor : public Equipment
{
public:
	int armorClass;

	virtual int GetStat() 
	{
		return armorClass;
	};
	Armor(string _name, float _weight, int _AC)
	{
		name = _name;
		weight = _weight;
		armorClass = _AC;
		itemType = Type::ARMOR;
	};
	Armor() {};
};