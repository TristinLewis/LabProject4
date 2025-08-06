#include "Assassin.h"



Assassin::Assassin(const string& n) : Player(n, 100, 25, 100) {

    addAbility("Backstab");
    addAbility("Quick strike");
    addAbility("Shadow Step");


}

void Assassin::attack() {
    cout << getName() << " strikes swiftly causing " << getAttackDamage() << " damage." << endl;
}

void Assassin::useAbility() {
    const vector<string>& skills = getAbilities();
    if (getResource() < 20) {
        cout << getName() << " does not have enough energy to use an ability." << endl;
        return;
    }

    int skillIndex = rand() % skills.size();
    cout << getName() << " uses " << skills[skillIndex] << endl;
    reduceResource(20);
}

void Assassin::displayStats() const {
    cout << "--- Assassin Stats ---" << endl;
    Player::displayStats();
}