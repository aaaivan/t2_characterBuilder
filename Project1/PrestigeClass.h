#pragma once
#include "CharacterClass.h"
#include <string>

class PrestigeClass : public CharacterClass {
	int strengthReq;
	int dexterityReq;
	int intelligenceReq;
	CharacterClass* classReq;
public:
	PrestigeClass(std::string _name, int _strengthBonus, int _dexterityBonus, int _intelligenceBonus,
		CharacterClass* _classReq, int _strengthReq, int _dexterityReq, int _intelligenceReq);
	CharacterClass* getRequiredClass();
	int getStrengthReq();
	int getDexterityReq();
	int getIntelligenceReq();
	std::string getName();
};
