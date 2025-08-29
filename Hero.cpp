#include "Hero.hpp"
#include <iostream>


Hero::Hero() {  // Default constructor, is supposed to be overwritten
    heroName        = "unnamed";
    isAlive         = true;
    maxHP           = 10;
    currentHP       = maxHP;
    currentXP       = 0;
    currentLevel    = 1;
    currentStrength = 2;
    healthPotions   = 0;
    goldCoins       = 0;
}

Hero::Hero(std::string name) {  // Constructor with a name
    heroName        = name;
    isAlive         = true;
    maxHP           = 10;
    currentHP       = maxHP;
    currentXP       = 0;
    currentLevel    = 1;
    currentStrength = 2;
    healthPotions   = 0;
    goldCoins       = 0;
}

bool Hero::checkLevelUp(){
    if (currentXP >= currentLevel*1000 ) {  // Check if the current xp is more than the current level times 1000. So every level needs more and more xp
        currentXP -= currentLevel*1000; // Remove all XP needed to level up. For level 3 fx, 3000 xp is needed to level up, and so that will be removed
        currentLevel++;     // Increase the level by one
        currentStrength++;  // Increase strength by one per level
        maxHP += 2;         // Increase the max HP of the player
        currentHP = maxHP;  // Reset the heros hp to max due to levelup
        return true;        // Return that a level up was completed
    } else {return false;}  // If it is not time to level up yet, return false
}

std::string Hero::getName() {
    return heroName;
}

bool Hero::getStatus() {
    return isAlive;
}

int Hero::getCurrentHP() {
    return currentHP;
}

int Hero::getStrength() {
    return currentStrength;
}

int Hero::getCurrentXP() {
    return currentXP;
}

int Hero::getCurrentLevel() {
    return currentLevel;
}

int Hero::getGold() {
    return goldCoins;
}

void Hero::setName(std::string name){
    heroName = name;
}

void Hero::setCurrentHP(int newHP){
    currentHP = newHP;
}
void Hero::setCurrentXP(int newXP){
    currentXP = newXP;
}

void Hero::getCurrentStats() {
    std::cout << "\n" << heroName << " is currently at " << currentHP << "/" << maxHP << " HP"<< 
    "\nThey are level " << currentLevel << " with " << currentXP << "/" << currentLevel*1000 << " XP to level up!" << 
    "\nCurrent strength is " << currentStrength << ", and they have " << goldCoins << " gold and " << healthPotions << " health potions." << std::endl;
}

void Hero::takeDamage(int damage) {
    currentHP -= damage;
    if (currentHP <= 0) {
        std::cout << heroName << " took fatal damage!" << std::endl;
        
        isAlive = false;

        return;
    }
    std::cout << heroName << " took " << damage << " damage, and is now at " << currentHP << " health out of " << maxHP << std::endl;
}

void Hero::healHeroFull() {
    currentHP = maxHP;
    std::cout << getName() << " is resting for night and is healed to " << getCurrentHP() << std::endl;
}

void Hero::usePotion() {
    if (healthPotions > 0) {
        healthPotions--;
        if (currentHP+15 >= maxHP) {
            currentHP += 15;
        } 
        else {currentHP = maxHP;}

        std::cout << heroName << " drank a health potion, and is now at " << currentHP << " HP" << std::endl;
    } else {
        std::cout << "No potions available, you stumble while searching and lose your turn" << std::endl;
    }
}

void Hero::givePotion(int amount) {
    healthPotions += amount;
    std::cout << heroName << " has " << healthPotions << " health potions." << std::endl;
}

void Hero::giveXP(int XP) {
    currentXP += XP;
    if (checkLevelUp() == false) {
        std::cout << heroName << " earned " << XP << " xp, and is currently at " << currentXP << ". " << currentLevel*1000-currentXP << " XP is needed to level up!" << std::endl;
    } else {
        std::cout << "\nCongratulations! " << heroName << " leveled up to level " << currentLevel << std::endl; 
    }
}

void Hero::giveGold(int amount) {
    goldCoins += amount;
}

