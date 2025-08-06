#include "Warrior.h"


Warrior::Warrior(const string& n) : Player(n, 100, 20, 100) {

    addAbility("Sword Slash");
    addAbility("Shield Bash");
    addAbility("Sword Stab");
}
void Warrior::attack() {
    cout << getName() << " swings a sword causing " << getAttackDamage() << " damage." << endl;
}

void Warrior::useAbility() {
    const vector<string>& weapons = getAbilities();
    if (getResource() < 15) {
        cout << getName() << " does not have enough energy to use an ability." << endl;
        return;
    }

    int abilityIndex = rand() % weapons.size();
    cout << getName() << " uses " << weapons[abilityIndex] << endl;
    reduceResource(15);
}

void Warrior::displayStats() const {
    cout << "--- Warrior Stats ---" << endl;
    Player::displayStats();
}

