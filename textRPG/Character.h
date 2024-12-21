#pragma once
#include <string>
#include <iostream>

class Character {
public:
    std::string name;
    int health;
    int damageDealt;
    int level; // Missing semicolon here

    // Default constructor
    Character();

    // Parameterized constructor
    Character(std::string n, int h, int d, int lvl);

    // Methods
    void characterDeath();
    void takeDamage(int damageDealt);
};

class Player : public Character {
public:
    int experience;

    // Constructor
    Player(std::string n, int h, int d, int lvl, int xp = 0);

    // Methods
    void gainExp(int xp);
};

class Warrior : public Character {

    // Methods for Warrior abilities
    void useAbility();
    void unlockAbilities();

    // Buffs and Attacks
    void chargeAttack(); //stun
    void berserkerRage(); //extre damage
    void defensiveStance(); 
    void lightAttack();
};
class Mage : public Character {
   
    void useAbility();
    void unlockAbilities();

    //mage specific
    void iceAttack(); //applies freeze
    void iceShield(); //blocks
    void staffHit(); //light attack
    void fireAttack(); //fire damage
};
class Rogue : public Character {
    //rogue
    void daggerAttack();
    void evade();
    void whirlBlades();
    void bleedingCuts();
    void shadowBuff();
};