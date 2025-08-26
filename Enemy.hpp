#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>

class Enemy {

    public:
        Enemy(std::string name, int hp, int str, int xp);   // To always make a finished enemy, only a constructor with all info is allowed

        int takeDamage(int damage); // Returns XP if enemy dies, else return 0
        
        // Simple getters
        int getXP();        
        int getHP();
        int getStrength();

    private:
        
        std::string  enemyName;
        int currentHP;
        int xpToGive;
        int strength;
        
};

#endif