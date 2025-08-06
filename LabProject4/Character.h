#ifndef Character_h
#define Character_h 
#include <iostream> 
#include <vector> 

using namespace std; 


class Character{
private: 
	string name; 
	int health, attackDamage; 

public: 

	Character(const string& n, int h, int dmg, int res); 

	virtual void attack() = 0; 
	virtual void useAbility() = 0; 
	virtual void displayStats() const; 

	bool isAlive()const; 
	string getName()const; 
	int getHealth()const; 
	void takeDamage(int dmg); 
	int getAttackDamage()const; 







};

#endif