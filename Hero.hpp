#ifndef HERO_HPP
#define HERO_HPP
#include <string>

class Hero {

    public:
        Hero();
        Hero(std::string name); 

        bool checkLevelUp();

        std::string getName();
        bool getStatus();
        int getCurrentHP();
        int getStrength();
        int getCurrentXP();
        int getCurrentLevel();
        int getGold();
        
        void setName(std::string name);
        void setCurrentHP(int newHP);
        void setCurrentXP(int newXP);
        void getCurrentStats();

        void takeDamage(int damage);
        void healHeroFull();
        void usePotion();
        void givePotion(int amount);
        void giveXP(int XP);
        void giveGold(int amount);
    
    private:
        
        std::string  heroName;
        bool isAlive;
        int maxHP;
        int currentHP;
        int currentXP;
        int currentLevel;
        int currentStrength;
        int healthPotions;
        int goldCoins;
        
};

#endif