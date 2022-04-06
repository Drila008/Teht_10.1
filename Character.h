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
	unique_ptr<Weapon> equippedWpn;
	unique_ptr<Armor> equippedArmor;
	vector <unique_ptr<Equipment>> inventory;


	void PrintEquippedItems();
	void EquipItem(int index);
	

	Character(string _name, int _hp, int _str, unique_ptr<Weapon> _wpn, unique_ptr<Armor> _armor);
	~Character()
	{
	
	};
};