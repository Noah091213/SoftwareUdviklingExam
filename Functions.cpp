#include <string>
#include "Functions.hpp"
#include "Enemy.hpp"
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

bool stringIsEqual (std::string input1, std::string input2) {
    std::transform(input1.cbegin(), input1.cend(), input1.begin(), toupper);
    std::transform(input2.cbegin(), input2.cend(), input2.begin(), toupper);
    
    if (input1.compare(input2) == 0){
        return (true);
    } else {
        return (false);
    }

}

void createEnemies() {
    Enemy horse("Horse", 4, 1, 100);
    Enemy weakGoblin("Weak Goblin", 4, 2, 200);
    Enemy strongGoblin("Strong Goblin", 8, 3, 400);
    Enemy strongerGoblin("Stronger Goblin", 10, 4, 500);
    Enemy StrongestGoblin("Strongest Goblin", 15, 5, 800);
    Enemy apeKing("Ape king", 30, 5, 1000);
    Enemy unicorn("Unicorn", 5, 8, 1500);
    Enemy Caesar("Caesar", 100, 10, 3000);
}

void inputErrorCheck() {
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void invalidInputPrint() {
    std::cout << "Please select a valid input" << std::endl;
}