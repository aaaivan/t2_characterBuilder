#include "Character.h"
#include "PrestigeClass.h"
#include "Corrupted.h"
#include <iostream>

//list of all available classes
std::vector<CharacterClass*> Character::allClasses = {};

//constructor
Character::Character(std::string _name) : name(_name) {};

//getter methods
std::string Character::getName() { return name; }
int Character::getStrength() { return strength; }
int Character::getDexterity() { return dexterity; }
int Character::getIntelligence() { return intelligence; }
int Character::getLevel() { return level; }

//level up: add 1 to level up to a max of 99, make user choose a CharacterClass
//and apply the respective bonuses to the plsyer abilities.
bool Character::levelUp() {
	if (level < 99)
		level++;
	else
		return false;
	CharacterClass* chosenClass = askClassToAssign();
	if (!isAlreadyAssigned(chosenClass)) {
		assignedClasses.push_back(chosenClass);
	}
	applyBonuses(chosenClass);
	return true;
}

//print a summary for the character
void Character::printStats() {
	std::cout << "This is " << getName() << " - Level " << level <<
		"\nStrength: " << strength <<
		"\nDexterity: " << dexterity <<
		"\nIntelligence: " << intelligence <<
		"\nType of character:";
	for (CharacterClass* cl : assignedClasses) {
		std::cout << " " << cl->getName() << ",";
	}
	std::cout << "\n" << std::endl;
}

//add a newly created classes to the list allClasses
void Character::addNewClass(CharacterClass* cl) {
	allClasses.push_back(cl);
}

//ask user to pick one among all the existing character classes
CharacterClass* Character::askClass() {
	std::cout << "Select:\n";
	for (int i = 0; i < allClasses.size(); i++) {
		std::cout << i << "- " << allClasses.at(i)->getName() << "\n";
	}
	std::cout << "Your input: ";
	int input;
	std::cin >> input;
	std::cin.ignore(1024, '\n');
	return allClasses.at(input);
}


//apply bonuses to the character's abilities
void Character::applyBonuses(CharacterClass* classType) {
	strength += classType->getStrengthBonus();
	dexterity += classType->getDexterityBonus();
	intelligence += classType->getIntelligenceBonus();
}

//ask the user to choose a class to assign to the character
CharacterClass* Character::askClassToAssign() {
	std::vector<CharacterClass*> availableClasses = getAvailableClasses();
	std::cout << "Select a character class to apply to the player:\n";
	for (int i = 0; i < availableClasses.size(); i++) {
		std::cout << i << "- " << availableClasses.at(i)->getName() << "\n";
	}
	std::cout << "Your input: ";
	int input;
	std::cin >> input;
	std::cin.ignore(1024, '\n');
	std::cout << std::endl;
	return availableClasses.at(input);
}

//get a list of all classes that can be assigned to the character
std::vector<CharacterClass*> Character::getAvailableClasses() {
	std::vector<CharacterClass*> v;
	for (CharacterClass* ch : allClasses) {
		PrestigeClass* p = dynamic_cast<PrestigeClass*>(ch);
		if (p != nullptr){
			if (strength >= p->getStrengthReq() &&
				dexterity >= p->getDexterityReq() &&
				intelligence >= p->getIntelligenceReq() &&
				isAlreadyAssigned(p->getRequiredClass()))
				v.push_back(ch);
		}
		else
			v.push_back(ch);
		
	}
	return v;
}

//check whether a class is already assigned to the character
bool Character::isAlreadyAssigned(CharacterClass* cl) {
	for (CharacterClass* chCl : assignedClasses) {
		if (cl == chCl)
			return true;
	}
	return false;
}

//release memory allocated for the character classes
void Character::releaseMemory() {
	for (int i = allClasses.size() - 1; i >= 0; i--) {
		delete allClasses.at(i);
	}
}
