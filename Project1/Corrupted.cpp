#include "Corrupted.h"

//constructor
Corrupted::Corrupted(std::string _name) :Character(_name) {};

//level up: add 1 to level up to a max of 99, make user choose a CharacterClass
//and decrease each ability by 1.
bool Corrupted::levelUp() {
	if (getLevel() < 99 && !isDead())
		level++;
	else
		return false;
	CharacterClass* chosenClass = askClassToAssign();
	if (!isAlreadyAssigned(chosenClass)) {
		assignedClasses.push_back(chosenClass);
	}
	applyBonuses(chosenClass);
	strength = 0 > strength - 1 ? 0 : strength - 1;
	dexterity = 0 > dexterity - 1 ? 0 : dexterity - 1;
	intelligence = 0 > intelligence - 1 ? 0 : intelligence - 1;
	return true;
}

//get the name of the corrupted character
std::string Corrupted::getName() {
	return Character::getName().append("(corrupted)");
}


//check whether the character is dead
bool Corrupted::isDead() {
	if (strength <= 0 || dexterity <= 0 || intelligence <= 0)
		return true;
	return false;
}
