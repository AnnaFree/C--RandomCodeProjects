#include "Character.h"

// Default constructor for Character
Character::Character() : name("Unnamed"), health(0), damageDealt(0), level(0) {}

// Parameterized constructor for Character
Character::Character(std::string n, int h, int d, int lvl) : name(n), health(h), damageDealt(d), level(lvl) {}

// Method to handle character death
void Character::characterDeath() {
    std::cout << "You have died" << std::endl;
}

// Method to handle taking damage
void Character::takeDamage(int damageDealt) {
    health -= damageDealt;
    if (health <= 0) {
        characterDeath();
    }
}

// Player constructor
Player::Player(std::string n, int h, int d, int lvl, int xp) : Character(n, h, d, lvl), experience(xp) {}

// Method for gaining experience
void Player::gainExp(int xp) {
    experience += xp;
}