#pragma once
#include "Character.h"
#include "Corrupted.h"
#include "CharacterClass.h"
#include "PrestigeClass.h"

void createCharacaterClass();
void createPrestigeClass();
Character* createNewCharacter();
void printCharacter(Character* c);
bool levelUp(Character* c);
Character* selectCharacter(const std::vector<Character*>& c);