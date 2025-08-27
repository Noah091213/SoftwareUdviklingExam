#ifndef HERO_HPP
#define HERO_HPP
#include <string>

class Hero {

    public:
        Hero();
        Hero(std::string name); 

        bool checkLevelUp();

        std::string getName();
        int getCurrentHP();
        int getStrength();
        int getCurrentXP();
        int getCurrentLevel();
        
        void setName(std::string name);
        void setCurrentHP(int newHP);
        void setCurrentXP(int newXP);
        void getCurrentStats();

        bool takeDamage(int damage);
        void healHeroFull();
        void usePotion();
        void givePotion(int amount);
        void giveXP(int XP);
    
    private:
        
        std::string  heroName;
        int maxHP;
        int currentHP;
        int currentXP;
        int currentLevel;
        int currentStrength;
        int healthPotions;
        
};

#endif