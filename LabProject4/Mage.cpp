#include "Mage.h"


Mage::Mage(string n) : Player(n, 100, 15, 100, "Mana") {


    addAbility("Fireball");
    addAbility("Ice shard");
    addAbility("Arcane cannon");

    srand(static_cast<unsigned int>(time(0)));  
}

void Mage::attack() {
    cout << getName() << " casts a spell causing " << getAttackDamage() << " damage." << endl;
}

void Mage::useAbility() {
    const vector<string>& spells = getAbilities();
    if (getResource() < 20) {
        cout << getName() << " does not have enough mana to cast an ability." << endl;
        return;
    }

    int spellIndex = rand() % spells.size();
    cout << getName() << " casts " << spells[spellIndex] << endl;
    reduceResource(20);
}

void Mage::displayStats() const {
    cout << "--- Mage Stats --- " << endl;
    Player::displayStats();
}