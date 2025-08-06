#ifndef Game_h 
#define Game_h 
#include "Character.h"
#include <iostream> 
using namespace std; 


class Game {
private: 
	Character* player; 
	Character* cpu; 
	string playerClass, playerName; 
public: 
	Game(); 
	~Game(); 

	void start(); 
	void gameLoop(); 

	Character* createPlayerCharacter(const string& choice, string& name);
	Character* createRandomCPU();
};

#endif