#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP
#include <string>
#include <vector>
#include "Enemy.hpp"

class Tournament {
    public:
        Tournament();
        Tournament(std::string name, int enemyCount, int difficulty, int goldCount, std::vector<Enemy> enemyVector);

        std::vector<Enemy> getEnemies();
        std::string getName();
        int getGold();

    private:
        std::string tournyName;
        std::vector<Enemy> enemyList;
        int goldToGive;
};


#endif