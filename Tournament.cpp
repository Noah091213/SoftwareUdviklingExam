#include "Tournament.hpp"
#include "Functions.hpp"
#include <iostream>


Tournament::Tournament() {}

Tournament::Tournament(std::string name, int enemyCount, int difficulty, int goldCount, std::vector<Enemy> enemyVector) {
    tournyName = name;
    goldToGive = goldCount;
    std::vector<Enemy> allowedEnemies;
    Enemy enemyToAdd;

    //std::cout << "start creating tourny" << std::endl;

    if (difficulty > 15) {
        difficulty = 15;
    } else if (difficulty < 0) {
        difficulty = 0;
    }
    //std::cout << "Difficulty is: " << difficulty << std::endl;

    for (int i = 0; i < enemyVector.size(); i++) {
        //std::cout <<enemyVector[i].getName() << " " << enemyVector[i].getDifficulty() << std::endl;

        if (enemyVector[i].getDifficulty() >= difficulty-3 && enemyVector[i].getDifficulty() <= difficulty+3) {
            allowedEnemies.push_back(enemyVector[i]);
            //std::cout << enemyVector[i].getName() << " was added to the allowlist" << std::endl;
        }
    }
    //std::cout << "finished allowed enemies" << std::endl;

    for (int i = 0; i < enemyCount; i++) {
        enemyToAdd = allowedEnemies[getRandomNum(allowedEnemies.size())-1];
        enemyToAdd.addModifier();
        enemyList.push_back(enemyToAdd);
        //std::cout << enemyToAdd.getName() << std::endl;
    }
    //std::cout << "finished tourny list" << std::endl;
}

std::vector<Enemy> Tournament::getEnemies() {
    return enemyList;
}

std::string Tournament::getName() {
    return tournyName;
}
int Tournament::getGold() {
    return goldToGive;
}