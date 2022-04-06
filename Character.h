#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Weapon.h"
#include "Armor.h"

using namespace std;
class Character
{
public:
	string name;
	int hp;
	int strength;
	Weapon equippedWpn;
	Armor equippedArmor;
	vector<Equipment> inventory;


	void PrintEquippedItems();
	void EquipItem(int index);
	

	Character(string _name, int _hp, int _str, Weapon _wpn, Armor _armor);
	~Character()
	{
	
	};
};