#ifndef MODIFIERS_HPP
#define MODIFIERS_HPP
#include <string>

class modifiers{

    public:
        modifiers(std::string name, int hp, int strength, int xp);

        std::string getName();
        int getHP();
        int getStrength();
        int getXP();

    private:
        std::string nameMod;
        int hpMod;
        int strMod;
        int xpMod;


};

#endif