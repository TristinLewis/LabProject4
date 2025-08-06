#include "Game.h"
#include "Assassin.h"
#include "Mage.h"
#include "Player.h"
#include "Warrior.h"



Game::Game() : player(nullptr), cpu(nullptr){
	srand(static_cast<unsigned int>(time(0)));
}
Game::~Game() {
	delete player; 
	delete cpu; 

}

void Game::start() {
	cout << "Choose your class (mage, warrior, assassin): ";
	cin >> playerClass;
	cout << "Enter your character name: ";
	cin >> playerName;


	player = createPlayerCharacter(playerClass, playerName);

	cpu = createRandomCPU();

	cout << endl << "Time to duel" << endl;

	gameLoop(); 

}
void Game::gameLoop() {
	string choice; 
	int action = 0, cpuAction = 0;

	cout << "Current Stats " << endl;
	cout << "Your stats:" << endl;
	player->displayStats();
	cout << "CPU stats:" << endl;
	cpu->displayStats();
	cout << endl;

	while (player->isAlive() && cpu->isAlive()) {

		cout << "Choose action: Attack(1), Ability(2)" << endl; 
	cin >> action;
		


	if (action == 1) {
		player->attack();
		cpu->takeDamage(player->getAttackDamage());
	}
	if (action == 2) {
		player->useAbility();
		cpu->takeDamage(player->getAttackDamage());
	}
	if (!cpu->isAlive())
			break; 

	if (!player->isAlive())
		break;

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
	
	
	cout << " End of Round " << endl;
	cout << player->getName() << " Health: " << player->getHealth() << endl; 
	cout << cpu->getName() << " Health: " << cpu->getHealth() << endl;

	}

	cout << endl << endl << endl;


	cout << "Final Stats" << endl; 
	cout << "Your stats:" << endl;
	player->displayStats();
	cout << "CPU stats:" << endl;
	cpu->displayStats();

	if (player->isAlive()) cout << "You beat the cpu.";
	else cout << "You lost to cpu";

}

Character* Game::createPlayerCharacter(const string& choice, string& name) {
	if (choice == "mage") {
		return new Mage(name);
	}
	else if (choice == "warrior") {
		return new Warrior(name);
	}
	else if (choice == "assassin") {
		return new Assassin(name);
	}
	else {
		cout << "Since you didn't pick I pick for ya, warrior it is." << endl;
		return new Warrior(name);

	};

}
Character* Game::createRandomCPU() {
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
	return nullptr; 

}