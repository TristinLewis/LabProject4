#ifndef MAGE_H
#define MAGE_H
#include "Player.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 


using namespace std;

class Mage : public Player {
public:
    Mage(string n);

    void attack() override;
    void useAbility() override;
    void displayStats() const override;
};

#endif
