#include "Character.h"
#include <iostream>

void displayIntro() {
    std::cout << "Welcome to a text RPG. There isn't much of a story, as this is just for testing and building upon. I hope you enjoy it anyway though!" << std::endl;
}

void startGame() {
    // Game logic
    std::string name = "not available";
    std::cout << "What is your character's name: ";
    std::cin >> name;
    std::cout << std::endl;

    // Create a Player object with the name entered by the user
    Player player(name, 100, 15, 1, 0); // Add level and xp as arguments
}

int main() {
    displayIntro();
    startGame();
    return 0;
}