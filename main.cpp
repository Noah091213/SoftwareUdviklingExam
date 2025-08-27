#include "Hero.hpp"
#include "Enemy.hpp"
#include "Functions.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "Welcome to the gladiator ring" << std::endl;
    bool gameRun = true;
    bool enableDebug = true;
    std::string choiceString;
    int choiceInt = 0;
    enum gameStates {startMenu, gameMenu, inFight, loadChar, newChar};
    gameStates gameState = startMenu;
    Hero activeHero;
    std::vector<Hero> storedHeros;
    

    while (gameRun == true) {
        switch(gameState) {
            
            case startMenu:
                if(enableDebug == true) {std::cout << "startMenu state" << std::endl;}
                
                std::cout << "\nWhat would you like to do?\n\n 1. Create a new character \n 2. Load a previous character" << std::endl;
                choiceInt = 0;
                std::cin >> choiceInt;

                switch (choiceInt) {
                    case 1:
                        gameState = newChar;
                    break;

                    case 2:
                        gameState = loadChar;
                    break;

                    case 0:
                        std::cout << "Please select a valid option" << std::endl;
                    break;
                }

                break;



            case loadChar:
                if(enableDebug == true) {std::cout << "loadChar state" << std::endl;}
                //std::cout << "not yet implemented" << std::endl;
                
                if (storedHeros.size() != 0) {
                    std::cout << "\nCurrently stored fighters:" << std::endl;
                    for(int i = 0; i < storedHeros.size(); i++) {
                        std::cout << i+1 << ". " << storedHeros[i].getName() << std::endl;
                    }
                    std::cout << "\nPlease select a fighter!" << std::endl;
                    choiceInt = 0;
                    std::cin >> choiceInt;

                    activeHero = storedHeros[choiceInt-1];
                    std::cout << activeHero.getName() << "is your fighter!" << std::endl;

                    gameState = gameMenu;
                    break;

                } else {
                    std::cout << "There is currently no stored heroes" << std::endl;
                    gameState = startMenu;
                    break;
                }
                
                break;



            case newChar:
                if(enableDebug == true) {std::cout << "newChar state" << std::endl;}
                
                std::cout << "\nWhat is the name of your fighter?" << std::endl;
                
                std::cin >> choiceString;

                activeHero.setName(choiceString);
                std::cout << activeHero.getName() << " is ready to begin a new adventure" << std::endl;
                storedHeros.push_back(activeHero);

                gameState = gameMenu;
                
                break;



            case gameMenu:
                if(enableDebug == true) {std::cout << "gameMenu state" << std::endl;}

                std::cout <<"\n\n"<<  activeHero.getName() << " is your fighter! What would you like to do?" << std::endl;

                std::cout << " 1. Show fighter stats \n 2. Train \n 3. Fight in the ring \n 4. Fight Caesar \n 5. Rest \n 6. Go to main menu" << std::endl;
                choiceInt = 0;
                std::cin >> choiceInt;
                if (choiceInt >= 0 && choiceInt <= 6) {
                    switch(choiceInt) {
                        case 1:
                            activeHero.getCurrentStats();
                        break;

                        case 2:

                        break;

                        case 3:

                        break;

                        case 4:

                        break;

                        case 5:
                            activeHero.healHero();
                            std::cout << activeHero.getName() << " is resting for night and is healed to " << activeHero.getCurrentHP() << std::endl;
                        break;

                        case 6:
                            gameState = startMenu;
                        break;
                    }
                }

                break;



            case inFight:
                if(enableDebug == true) {std::cout << "inFight state" << std::endl;}

                break;



        }
       
    }
    
}