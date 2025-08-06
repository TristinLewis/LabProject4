#include "Player.h"
#include <iostream> 



Player::Player(const string& n, int h, int dmg, int res) : Character(n, 100, 20, 20), resource(res) {
   
}
void Player::addAbility(const string& ability) {
    abilities.push_back(ability);
}

void Player::attack() {
    cout << getName() << " attacks for " << getAttackDamage() << " damage" << endl;
}

void Player::useAbility() {
    if (abilities.empty()) {
        cout << getName() << " has no abilities" << endl;
        return;
    }

    cout << getName() << " uses " << abilities[0] << endl;
    reduceResource(10);
}

void Player::displayStats() const {
    Character::displayStats();
    cout << "Resource: " << resource << endl;
    cout << "Abilities: ";
    for (const auto& ability : abilities) {
        cout << ability << endl;
    }
    cout << endl;
}

int Player::getResource() const {
    return resource;
}
void Player::reduceResource(int amount) {
    resource -= amount;
    if (resource < 0) {
        resource = 0;
    }
}
const vector<string>& Player::getAbilities()const{
    return abilities; 

}