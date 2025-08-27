#include "Hero.hpp"
#include <iostream>


Hero::Hero() {  // Default constructor, is supposed to be overwritten
    heroName     = "unnamed";
    maxHP        = 10;
    currentHP    = maxHP;
    currentXP    = 0;
    currentLevel = 1;
    strength     = 2;
}

Hero::Hero(std::string name) {  // Constructor with a name
    heroName     = name;
    maxHP        = 10;
    currentHP    = maxHP;
    currentXP    = 0;
    currentLevel = 1;
    strength     = 2;
}

bool Hero::checkLevelUp(){
    if (currentXP >= currentLevel*1000 ) {  // Check if the current xp is more than the current level times 1000. So every level needs more and more xp
        currentXP -= currentLevel*1000; // Remove all XP needed to level up. For level 3 fx, 3000 xp is needed to level up, and so that will be removed
        currentLevel++;     // Increase the level by one
        strength++;         // Increase strength by one per level
        maxHP += 2;         // Increase the max HP of the player
        currentHP = maxHP;  // Reset the heros hp to max due to levelup
        return true;        // Return that a level up was completed
    } else {return false;}  // If it is not time to level up yet, return false
}

std::string Hero::getName() {
    return heroName;
}

int Hero::getCurrentHP() {
    return currentHP;
}

int Hero::getStrength() {
    return strength;
}

int Hero::getCurrentXP() {
    return currentXP;
}

int Hero::getCurrentLevel() {
    return currentLevel;
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

void Hero::takeDamage(int damage) {
    currentHP -= damage;
    std::cout << heroName << " took " << damage << " damage, and is now at " << currentHP << " health out of " << maxHP << std::endl;
}

void Hero::giveXP(int XP) {
    currentXP += XP;
    std::cout << heroName << " earned " << XP << " xp, and is currently at " << currentXP << ". " << currentLevel*1000-currentXP << " is needed to level up!" << std::endl;
}