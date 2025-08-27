#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy() {}

Enemy::Enemy(std::string name, int hp, int str, int xp, std::string message) {
    enemyName       = name;
    currentHP       = hp;
    strength        = str;
    xpToGive        = xp;
    damageMessage   = message;
}

int Enemy::takeDamage(int damage) { // Method to deal damage to this enemy
    currentHP -= damage;            // Deal the specified damage to the enemy's hp
    if (currentHP <= 0) {           // If the enemy's hp is equal or less than 0 it is dead
        std::cout << enemyName << " took " << damage << " damage and is now dead. Player gets " << xpToGive << " XP" << std::endl; // Give player the news
        return xpToGive;    // Return an XP amount
    } else {
        std::cout << enemyName << " took " << damage << " damage, and is now at " << currentHP << " health" << std::endl;   // Give player the news
        return 0;           // Return 0 as the enemy is still alive
    }
}

int Enemy::doDamage() {
    std::cout << damageMessage << std::endl;
    return strength;
}

std::string Enemy::getName() {
    return enemyName;
}

int Enemy::getXP() {
    return xpToGive;
}

int Enemy::getHP() {
    return currentHP;
}

int Enemy::getStrength() {
    return strength;
}