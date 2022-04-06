#pragma once
#include "Equipment.h"

class Weapon : public Equipment
{
public:
	int damage;

	virtual int GetStat()
	{
		return damage;
	};

	Weapon(string _name, float _weight, int _damage)
	{
		name = _name;
		weight = _weight;
		damage = _damage;
		itemType = Type::WEAPON;
	};
	Weapon() {};

};