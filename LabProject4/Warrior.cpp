#include "Warrior.h"


Warrior::Warrior(string n) : Player(n, 100, 20, 100, "Energy") {

    addAbility("Sword Slash");
    addAbility("Shield Bash");
    addAbility("Sword Stab");

    srand(static_cast<unsigned int>(time(0)));
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

