#include <string>
#include "Functions.hpp"
#include "Enemy.hpp"
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono>
#include <random>

bool stringIsEqual (std::string input1, std::string input2) {
    std::transform(input1.cbegin(), input1.cend(), input1.begin(), toupper);
    std::transform(input2.cbegin(), input2.cend(), input2.begin(), toupper);
    
    if (input1.compare(input2) == 0){
        return (true);
    } else {
        return (false);
    }

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

int getRandomNum(int limit) {
    int randomNumber;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, limit);
    randomNumber = distrib(gen);
    //std::cout << "Random number is " << randomNumber << std::endl;
    
    return randomNumber;
    
}