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

void inputErrorCheck() {
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void invalidInputPrint() {
    std::cout << "Please select a valid input" << std::endl;
}