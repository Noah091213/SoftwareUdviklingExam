#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>

class Enemy {

    public:
        Enemy();
        Enemy(std::string name, int hp, int str, int xp, std::string damageMessage);   

        int takeDamage(int damage); // Returns XP if enemy dies, else return 0
        int doDamage();
        
        // Simple getters
        std::string getName();
        int getXP();        
        int getHP();
        int getStrength();

    private:
        
        std::string  enemyName;
        int currentHP;
        int xpToGive;
        int strength;
        std::string damageMessage;
        
};

#endif