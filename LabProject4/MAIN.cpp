#include <iostream> 
#include "Mage.h"
#include "Warrior.h"
#include "Assassin.h" 

using namespace std; 



Character* createPlayerCharacter(string& choice, string& name) {
	if (choice == "mage") {
		return new Mage(name);
	}
	else if(choice == "warrior"){
		return new Warrior(name); 
	}
	else if (choice == "assassin") {
		return new Assassin(name); 
	}
	else {
		cout << "Since you didn't pick I pick for ya, warrior it is." << endl; 
		return new Warrior(name); 

	}

}
Character* createRandomCPU() {
	int rando; 
	rando = rand() % 3; 

	if (rando == 0) {
		return new Mage("CPU Mage");
	}
	else if (rando == 1) {
		return new Warrior("CPU Warrior");
	}
	else {
		return new Assassin("CPU Assassin");
	}
	

}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	string choice, playerName;
	int action = 0, cpuAction = 0; 


	cout << "Choose your class (mage, warrior, assassin): ";
	cin >> choice;
	cout << "Enter your character name: ";
	cin >> playerName;


	Character* player = createPlayerCharacter(choice, playerName); 

	Character* cpu = createRandomCPU(); 

	cout << endl << "Time to duel" << endl; 

	while (player->isAlive() && cpu->isAlive()) {
		cout << "Your hp: " << player->getHealth() << endl
			<< "CPU hp: " << cpu->getHealth() << endl << endl;


		cout << "Choose your action : ";
		if (choice == "mage") {
			cout << "Press 2 to cast a spell: ";
		}
		else {
			cout << "Press 1 to attack: ";
		}
		cin >> action;

		if (action == 1 && choice != "mage") {
			player->attack();
			int dmg = player->getAttackDamage();
			cout << player->getName() << " attacks for " << dmg << " damage!" << endl;
			cpu->takeDamage(dmg);
		}
		else if (action == 2 && choice == "mage") {
			player->useAbility();
			int dmg = player->getAttackDamage();
			cout << player->getName() << " casts a spell for " << dmg << " damage!" << endl;
			cpu->takeDamage(dmg);
		}
		else {
			cout << "You don't have that ability buddy. YOur turn has been skipped." << endl;
		}



		cout << "Now its CPU turn" << endl;

		cpuAction = rand() % 2;

		if (cpuAction == 0) {
			cpu->attack();
			player->takeDamage(cpu->getAttackDamage());
		}
		else {
			cpu->useAbility();
			player->takeDamage(cpu->getAttackDamage());
		}
	}

	cout << endl << endl << endl; 


	cout << "Current Health:";
	cout << player->getName() << ": " << player->getHealth() << endl;
	cout << cpu->getName() << ": " << cpu->getHealth() << endl;

	if (player->isAlive()) cout << "You beat a computer, good job I guess";
	else cout << "You suck, and also lost";

	delete player;
	delete cpu;

}