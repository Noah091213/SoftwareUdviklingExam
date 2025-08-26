#ifndef HERO_HPP
#define HERO_HPP
#include <string>

class Hero {

    public:
        Hero(std::string name); //  Constructor, always requires a name, to differentiate heroes

        bool checkLevelUp();

        int getCurrentHP();
        int getStrength();
        int getCurrentXP();
        int getCurrentLevel();
        
        void setCurrentHP(int newHP);
        void setCurrentXP(int newXP);

        void takeDamage(int damage);
        void giveXP(int XP);
    
    private:
        
        std::string  heroName;
        int maxHP;
        int currentHP;
        int currentXP;
        int currentLevel;
        int strength;
        
};

#endif