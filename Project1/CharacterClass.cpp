#include "CharacterClass.h"

//constructor
CharacterClass::CharacterClass(std::string _name, int _strengthBonus, int _dexterityBonus, int _intelligenceBonus) :
	name(_name), strengthBonus(_strengthBonus), dexterityBonus(_dexterityBonus), intelligenceBonus(_intelligenceBonus) {};

//getter methods
std::string CharacterClass::getName() { return name; }
int CharacterClass::getStrengthBonus() { return strengthBonus; }
int CharacterClass::getDexterityBonus() { return dexterityBonus; }
int CharacterClass::getIntelligenceBonus() { return intelligenceBonus; }
