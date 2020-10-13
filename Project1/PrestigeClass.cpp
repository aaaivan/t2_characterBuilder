#include "PrestigeClass.h"

//constructor
PrestigeClass::PrestigeClass(std::string _name, int _strengthBonus, int _dexterityBonus, int _intelligenceBonus,
	CharacterClass* _classReq, int _strengthReq, int _dexterityReq, int _intelligenceReq) :
	CharacterClass(_name, _strengthBonus, _dexterityBonus, _intelligenceBonus),
	classReq(_classReq), strengthReq(_strengthReq), dexterityReq(_dexterityReq), intelligenceReq(_intelligenceReq) {}

//getter methods
CharacterClass* PrestigeClass::getRequiredClass() { return classReq; }
int PrestigeClass::getStrengthReq() { return strengthReq; }
int PrestigeClass::getDexterityReq() { return dexterityReq; }
int PrestigeClass::getIntelligenceReq() { return intelligenceReq; }
std::string PrestigeClass::getName() { return CharacterClass::getName().append("(prestige)"); }
