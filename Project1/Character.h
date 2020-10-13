#pragma once

#include "CharacterClass.h"
#include <vector>
#include <string>

class Character {
protected:
	std::string name;
	int strength=10;
	int dexterity=10;
	int intelligence=10;
	int level=0;
	std::vector<CharacterClass*> assignedClasses={};
	static std::vector<CharacterClass*> allClasses;
public:
	Character(std::string _name);
	virtual std::string getName();
	int getStrength();
	int getDexterity();
	int getIntelligence();
	int getLevel();
	virtual bool levelUp();
	void printStats();
	static void addNewClass(CharacterClass* cl);
	static CharacterClass* askClass();
	static void releaseMemory();
protected:
	void applyBonuses(CharacterClass* classType);
	CharacterClass* askClassToAssign();
	std::vector<CharacterClass*> getAvailableClasses();
	bool isAlreadyAssigned(CharacterClass* cl);
};
