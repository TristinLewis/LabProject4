#include "Character.h"




Character::Character(string n, int h, int dmg)
    : name(n), health(h), attackDamage(dmg) {
}

void Character::displayStats() const {
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Damage: " << attackDamage << endl;
}

bool Character::isAlive() const {
    return health > 0;
} 

string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getAttackDamage() const {
    return attackDamage;
}

void Character::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) {
        health = 0;
    }
}