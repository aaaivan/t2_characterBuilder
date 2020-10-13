#include "functions.h"
#include <iostream>

//create a new character class and add it to the Character::allClasses vector 
void createCharacaterClass() {
	std::string name;
	int strenghtBonus;
	int dexterityBonus;
	int intelligenceBonus;
	std::cout << "Name of the Class: ";
	std::getline(std::cin, name);
	std::cout << "Strength bonus: ";
	std::cin >> strenghtBonus;
	std::cout << "Dexterity bonus: ";
	std::cin >> dexterityBonus;
	std::cout << "Intelligence bonus: ";
	std::cin >> intelligenceBonus;
	std::cin.ignore(1024, '\n');
	std::cout << std::endl;

	Character::addNewClass(new CharacterClass(name, strenghtBonus, dexterityBonus, intelligenceBonus));
}

//create a new prestige class and add it to the Character::allClasses vector
void createPrestigeClass() {
	std::string name;
	int strenghtBonus;
	int dexterityBonus;
	int intelligenceBonus;
	int strenghtReq;
	int dexterityReq;
	int intelligenceReq;
	CharacterClass* required;

	std::cout << "Name of the Class: ";
	std::getline(std::cin, name);
	std::cout << "Strength bonus: ";
	std::cin >> strenghtBonus;
	std::cout << "Dexterity bonus: ";
	std::cin >> dexterityBonus;
	std::cout << "Intelligence bonus: ";
	std::cin >> intelligenceBonus;
	std::cout << "Strength required: ";
	std::cin >> strenghtReq;
	std::cout << "Dexterity required: ";
	std::cin >> dexterityReq;
	std::cout << "Intelligence required: ";
	std::cin >> intelligenceReq;
	std::cin.ignore(1024, '\n');
	std::cout << "Required character class. ";
	required = Character::askClass();
	std::cout << std::endl;

	Character::addNewClass(new PrestigeClass(name, strenghtBonus, dexterityBonus, intelligenceBonus,
		required, strenghtReq, dexterityReq, intelligenceReq));
}

//create new character and return pointer to it
Character* createNewCharacter() {
	std::string name;
	bool corrupted;
	std::cout << "Character name: ";
	std::getline(std::cin, name);
	std::cout << "Are they corrupted (y/n)? ";
	char c;
	std::cin >> c;
	corrupted = (c == 'y');
	std::cin.ignore(1024, '\n');
	std::cout << std::endl;

	if (corrupted)
		return new Corrupted(name);
	else
		return new Character(name);
}

//print stats of specified character
void printCharacter(Character* c) {
	c->printStats();
}

//level up spesified character
bool levelUp(Character* c) {
	return c->levelUp();
}

//select the character to which apply the changes
Character* selectCharacter(const std::vector<Character*>& c) {
	std::cout << "Choose a character:\n";
	if (c.size() == 0)
		return nullptr;
	for (int i = 0; i < c.size(); i++) {
		std::cout << i << "- " << c.at(i)->getName() << "\n";
	}
	std::cout << "Your input: ";
	int input;
	std::cin >> input;
	std::cin.ignore(1024, '\n');
	std::cout << std::endl;
	return c.at(input);
}