#include "Enemy.hpp"
#include "Functions.hpp"
#include <iostream>

Enemy::Enemy() {}

Enemy::Enemy(std::string name, int hp, int str, int xp, std::string message, int crRating) {
    enemyName       = name;
    currentHP       = hp;
    strength        = str;
    xpToGive        = xp;
    damageMessage   = message;
    challengeRating = crRating;
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

int Enemy::getDifficulty() {
    return challengeRating;
}

void Enemy::addModifier() {
    switch(getRandomNum(5)) {
        case 1:
            enemyName = "Strong " + enemyName;
            strength += 1;
            xpToGive *= 2;
        break;
            
        case 2:
            enemyName = "Weak " + enemyName;
            strength -= 1;
        break;

        case 3:
            enemyName = "Tanky " + enemyName;
            currentHP *= 2;
        break;

        case 4:
            enemyName = "Diciple " + enemyName;
            strength = 0;
            damageMessage = "I can do no harm and will not hurt you";
        break;

        case 5:
            enemyName = "Super strong " + enemyName;
            strength *= 2;
            xpToGive *= 3;
        break;

    }
}