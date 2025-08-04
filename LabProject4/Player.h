#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include <vector>

using namespace std;

class Player : public Character {

private:
    vector<string> abilities;
    int resource;
    string resourceType;

public:
    Player(string n, int h, int dmg, int resourceAmount, string resType);

    void addAbility(const string& ability);
    void attack() override;
    void useAbility() override;
    void displayStats() const override;

    int getResource() const;
    string getResourceType() const;
    void reduceResource(int amount);


    const vector<string>& getAbilities() const; 

};

#endif