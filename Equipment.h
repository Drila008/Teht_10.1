#pragma once
#include <string>
#include <iostream>


using namespace std;
class Equipment
{
public:
	string name;
	float weight;
	enum class Type {WEAPON, ARMOR};
	Type itemType;

	virtual int GetStat() { return 0; };
	//Equipment() {};
};