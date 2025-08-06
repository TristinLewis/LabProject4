#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include <vector>

using namespace std;

class Player : public Character {

private:
    vector<string> abilities;
    int resource; 

public:
    Player(const string& n, int h, int dmg, int res);

    void addAbility(const string& ability);

    void attack() override;
    void useAbility() override;
    void displayStats() const override;



    const vector<string>& getAbilities() const; 
    int getResource()const; 
    void reduceResource(int amount); 

};

#endif