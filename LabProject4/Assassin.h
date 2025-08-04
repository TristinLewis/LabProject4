#ifndef ASSASSIN_H
#define ASSASSIN_H
#include "Player.h"
#include <iostream>
#include <ctime> 
#include <cstdlib> 


using namespace std;

class Assassin : public Player {
public:
    Assassin(string n);

    void attack() override;
    void useAbility() override;
    void displayStats() const override;
};

#endif
