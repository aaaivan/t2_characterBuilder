#pragma once
#include <string>

class CharacterClass {
	std::string name;
	int strengthBonus;
	int dexterityBonus;
	int intelligenceBonus;
public:
	CharacterClass(std::string _name, int _strengthBonus, int _dexterityBonus, int _intelligenceBonus);
	virtual std::string getName();
	int getStrengthBonus();
	int getDexterityBonus();
	int getIntelligenceBonus();
};
