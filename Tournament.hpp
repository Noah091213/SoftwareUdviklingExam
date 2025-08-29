#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP
#include <string>
#include <vector>
#include "Enemy.hpp"

class Tournament {
    public:
        Tournament(std::string name, int enemyCount, int difficulty, int goldCount);
    private:
        std::string tournyName;
        std::vector<Enemy> enemyList;
        int goldToGive;
};


#endif