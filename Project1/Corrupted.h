#pragma once
#include "Character.h"
#include<string>

class Corrupted :public Character {
public:
	Corrupted(std::string _name);
	bool levelUp();
	std::string getName();
private:
	bool isDead();
};