#include "Hero.hpp"
#include "Enemy.hpp"
#include "Functions.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "Welcome to the gladiator ring" << std::endl;

    // Init variables, cannot be done later as the game runs in a statemachine
    bool gameRun = true;
    bool enableDebug = true;

    std::string choiceString;
    int         choiceInt = 0;
    
    enum gameStates {startMenu, gameMenu, inFight, loadChar, newChar, shopMenu};
    enum fightTurns {playerTurn, enemyTurn};
    gameStates gameState = startMenu;
    fightTurns currentTurn;
    
    Hero activeHero;
    Enemy currentEnemy;
    std::vector<Hero> storedHeros;

    bool isFighting;
    int xpReward;
    

    // Create enemy types
    Enemy trainingDummy("Training dummy", 4, 1, 100, "BoNk");
    Enemy weakFighter("Weak Fighter", 4, 2, 200, "*Punches with fist*");
    Enemy strongFighter("Strong Fighter", 8, 3, 400, "*Stabs with knife*");
    Enemy strongerFighter("Stronger Fighter", 10, 4, 500, "*Swipes with sword*");
    Enemy StrongestFighter("Strongest Fighter", 15, 5, 800, "*Pokes with trident*");
    Enemy Gorilla("Gorilla", 30, 5, 1000, "Oooh Banana");   // I hope you get this reference
    Enemy Lion("Lion", 5, 8, 1500, "RAWR");
    Enemy Caesar("Caesar", 100, 10, 3000, "*Laugs in superiority*");

    

    while (gameRun == true) {
        switch(gameState) {
            
            case startMenu:
                if(enableDebug == true) {std::cout << "startMenu state" << std::endl;}

                std::cout << "\nWhat would you like to do?\n\n 1. Create a new character \n 2. Load a previous character" << std::endl;
                choiceInt = 0;
                inputErrorCheck();
                std::cin >> choiceInt;

                switch (choiceInt) {
                    case 1:
                        gameState = newChar;
                    break;

                    case 2:
                        gameState = loadChar;
                    break;

                    default:
                        invalidInputPrint();
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
                    inputErrorCheck();
                    std::cin >> choiceInt;
                    
                    if (choiceInt != 0) {
                        activeHero = storedHeros[choiceInt-1];
                        std::cout << activeHero.getName() << "is your fighter!" << std::endl;
                        
                        gameState = gameMenu;
                    } else {
                        std::cout << "Please select a valid fighter" << std::endl;
                    }

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
                
                inputErrorCheck();
                std::cin >> choiceString;

                activeHero.setName(choiceString);
                std::cout << activeHero.getName() << " is ready to begin a new adventure" << std::endl;
                storedHeros.push_back(activeHero);

                gameState = gameMenu;
                
                break;



            case gameMenu:
                if(enableDebug == true) {std::cout << "gameMenu state" << std::endl;}

                std::cout <<"\n\n"<<  activeHero.getName() << " is your fighter! What would you like to do?" << std::endl;

                std::cout << " 1. Show fighter stats \n 2. Train \n 3. Fight in the ring \n 4. Fight Caesar \n 5. Rest \n 6. Shop \n 7. Go to main menu" << std::endl;
                choiceInt = 0;
                inputErrorCheck();
                std::cin >> choiceInt;
                
                if (choiceInt >= 0 && choiceInt <= 6) {
                    switch(choiceInt) {
                        case 1: // Get stats
                            if(enableDebug == true) {std::cout << "Stats print" << std::endl;}
                            activeHero.getCurrentStats();
                            
                            break;

                        case 2: // Train
                            if(enableDebug == true) {std::cout << "Training grounds" << std::endl;}
                            currentEnemy = trainingDummy;
                            gameState = inFight;
                            break;

                        case 3: // Arena
                            if(enableDebug == true) {std::cout << "Arena grounds" << std::endl;}

                            break;

                        case 4: // Boss fight
                            if(enableDebug == true) {std::cout << "Boss fight" << std::endl;}

                            break;

                        case 5: // Heal
                            if(enableDebug == true) {std::cout << "Heal print" << std::endl;}
                            activeHero.healHeroFull();
                            
                            break;

                        case 6: // Shop
                            gameState = shopMenu;
                            
                            break;

                        case 7: // Main menu
                            if(enableDebug == true) {std::cout << "Return to main menu" << std::endl;}
                            gameState = startMenu;
                            
                            break;

                        default: 
                            invalidInputPrint();
                            
                            break;
                    }
                }
                break;



            case inFight:
                if(enableDebug == true) {std::cout << "inFight state" << std::endl;}

                isFighting = true;
                xpReward = 0;
                currentTurn = playerTurn;
            

                // Start fight
                
                
                std::cout;
                while(isFighting == true && activeHero.getCurrentHP() >= 0 && currentEnemy.getHP() >= 0) {
                    switch (currentTurn) {
                        case playerTurn:
                            // Player option select
                            std::cout << "\nYour turn turn\n \nWhat do you want to do?\n 1. Attack\n 2. Drink a potion\n 3. Run, you will still take damage once" << std::endl;
                            
                            choiceInt = 0;
                            inputErrorCheck();
                            std::cin >> choiceInt;
                            
                            if (choiceInt >= 0 && choiceInt <= 3) {
                                currentTurn = enemyTurn;
                                switch(choiceInt) {
                                    case 1:
                                        xpReward = currentEnemy.takeDamage(activeHero.getStrength());

                                        if (xpReward == 0) {
                                            std::cout << "HUARH   you deal " << activeHero.getStrength() << " damage to " << currentEnemy.getName() << "\n" << currentEnemy.getName() << " has " << currentEnemy.getHP() << " HP left"<<std::endl;
                                        } else {
                                            //std::cout << "Haha *stabs opponent in the heart* \nYou defeated " << currentEnemy.getName() << " and recieved " << xpReward << " XP" << std::endl;
                                            activeHero.giveXP(xpReward);
                                            isFighting = false;
                            
                                            break;
                                        }
                                    break;

                                    case 2:
                                        activeHero.usePotion();
                                    break;

                                    case 3:
                                        std::cout << "You run like a coward and lose 200 XP" << std::endl;
                                        activeHero.giveXP(-200);
                                        isFighting = false;
                                    break;
                                }
                            }
                            break;
                        
                        case enemyTurn:
                            // Enemy do damage
                            std::cout << "\nEnemys turn\n" << std::endl;
                            isFighting = activeHero.takeDamage(currentEnemy.doDamage());
                            currentTurn = playerTurn;
                            break;

                    }
                    
                }

                gameState = gameMenu;


                break;



            case shopMenu:

                if(enableDebug == true) {std::cout << "Shop menu" << std::endl;}

                std::cout << 
                "\nKhajiit  bids you welcome in his store. What do you require?" << 
                "\n 1. Exit" << 
                "\n 2. health potion (cost 150XP)" 
                << std::endl;

                choiceInt = 0;
                inputErrorCheck();
                std::cin >> choiceInt;
                
                if (choiceInt >= 0 && choiceInt <= 2) {
                    switch(choiceInt) { 
                        case 1: // Exit
                            gameState = gameMenu;
                        break;

                        case 2:
                            if (activeHero.getCurrentXP() >= 150) {
                                activeHero.giveXP(-150);
                                activeHero.givePotion(1);
                            }else {std::cout << "You do not have sufficient funds... This displeases Kahjiit..." << std::endl;}
                        break;

                        default:
                            invalidInputPrint();
                        break;

                    }
                }

                break;



        }
       
    }
    
}