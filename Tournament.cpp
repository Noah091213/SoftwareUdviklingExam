#include "Tournament.hpp"
#include "Functions.hpp"
#include "main.cpp"

Tournament::Tournament(std::string name, int enemyCount, int difficulty, int goldCount) {
    tournyName = name;
    goldToGive = goldCount;
    std::vector<Enemy> allowedEnemies;
    Enemy enemyToAdd;

    if (difficulty > 15) {
        difficulty = 15;
    }

    for (int i = 0; i < enemyList.size(); i++) {
        if (enemyVector[i].getDifficulty() >= difficulty-3 && enemyVector[i].getDifficulty() <= difficulty+3) {
            allowedEnemies.push_back(enemyVector[i]);
        }
    }

    for (int i = 0; i < enemyCount; i++) {
        enemyToAdd = allowedEnemies[getRandomNum(allowedEnemies.size())-1];
        enemyToAdd.addModifier();
        if (enableDebug == true) {
            std::cout << "Tournament enemy added: " << enemyToAdd.getName() << std::endl;
        }
        enemyList.push_back(enemyToAdd);
    }
}