#include "functions.h"
#include <vector>
#include <iostream>

int main(){
	std::vector<Character*> characters{};
	Character* currentCharacter = nullptr;
	int input=0;
	while (input != 6) {
		if (currentCharacter != nullptr)
			std::cout << "Current character: " << currentCharacter->getName() << "\n";
		std::cout << "What do you want do?\n" <<
			"0- New character class\n" <<
			"1- New prestige class\n" <<
			"2- New character\n" <<
			"3- Select character\n" <<
			"4- Level up character\n" <<
			"5- Print character stats\n" <<
			"6- quit\n" <<
			"Your input: ";
		std::cin >> input;
		std::cin.ignore(1024, '\n');
		std::cout << std::endl;
		switch (input) {
		case 0:
			createCharacaterClass();
			break;
		case 1:
			createPrestigeClass();
			break;
		case 2:
			currentCharacter = createNewCharacter();
			characters.push_back(currentCharacter);
			break;
		case 3:
			currentCharacter = selectCharacter(characters);
			break;
		case 4:
			if (!levelUp(currentCharacter))
				std::cout << "Level up failed!\n" << std::endl;
			break;
		case 5:
			printCharacter(currentCharacter);
			break;
		}
	}
	//release memory allocated for Characters
	for (int i = characters.size() - 1; i >= 0; i--) {
		delete characters.at(i);
	}
	//release memory allocated for Characters Classes
	Character::releaseMemory();
}
