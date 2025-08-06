#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 


using namespace std;

class Warrior : public Player {
public:
    Warrior(const string& n);

    void attack() override;
    void useAbility() override;
    void displayStats() const override;
};

#endif