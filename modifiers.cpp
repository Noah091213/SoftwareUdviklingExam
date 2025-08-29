#include "modifiers.hpp"

modifiers::modifiers(std::string name, int hp, int strength, int xp) {
    nameMod = name;
    hpMod   = hp;
    strMod  = strength;
    xpMod   = xp;
}

std::string modifiers::getName() {
    return nameMod;
}

int modifiers::getHP() {
    return hpMod;
}

int modifiers::getStrength() {
    return strMod;
}

int modifiers::getXP() {
    return xpMod;
}

