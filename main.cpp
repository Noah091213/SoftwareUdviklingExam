#include "Hero.hpp"
#include "Enemy.hpp"
#include "Functions.hpp"
#include "Tournament.hpp"

#include <iostream>
#include <string>
#include <vector>



int main() {
    std::cout << "Welcome to the gladiator ring" << std::endl;
    
    // Init variables, cannot be done later as the game runs in a statemachine
    bool gameRun = true;
    bool enableDebug = false;

    std::string choiceString;
    int         choiceInt = 0;
    
    enum gameStates {startMenu, gameMenu, inFight, loadChar, newChar, shopMenu};
    enum fightTurns {playerTurn, enemyTurn, enemyDefeated};
    gameStates gameState = startMenu;
    fightTurns currentTurn;
    
    Hero activeHero;
    Enemy currentEnemy;
    Tournament activeTournament;
    std::vector<Enemy> activeCombatEncounter;
    std::vector<Hero> storedHeros;

    bool isTournament = false;
    int xpReward;

    Enemy trainingDummy("Training dummy", 4, 1, 500, "BoNk", 0);
    Enemy weakFighter("Weak Fighter", 4, 2, 200, "*Punches with fist*", 0);
    Enemy strongFighter("Strong Fighter", 8, 3, 400, "*Stabs with knife*", 2);
    Enemy strongerFighter("Stronger Fighter", 10, 4, 500, "*Swipes with sword*", 4);
    Enemy strongestFighter("Strongest Fighter", 15, 5, 800, "*Pokes with trident*", 6);
    Enemy gorilla("Gorilla", 30, 5, 1000, "Oooh Banana",10);
    Enemy lion("Lion", 5, 8, 1500, "RAWR", 10);
    Enemy elephant("Elephant", 40, 6, 2000, "*Stomp stomp*", 15);
    Enemy caesar("Caesar", 100, 10, 3000, "*Laugs in superiority*", 25);
    std::vector<Enemy> enemyVector;
    
    enemyVector.push_back(trainingDummy);
    enemyVector.push_back(weakFighter);
    enemyVector.push_back(strongFighter);
    enemyVector.push_back(strongerFighter);
    enemyVector.push_back(strongestFighter);
    enemyVector.push_back(gorilla);
    enemyVector.push_back(lion);
    enemyVector.push_back(elephant);
    enemyVector.push_back(caesar);



    while (gameRun == true) {
        switch(gameState) {
            
            case startMenu:
                if(enableDebug == true) {std::cout << "startMenu state" << std::endl;}

                std::cout << "\nWhat would you like to do?\n\n 1. Create a new character \n 2. Load a previous character \n 3. Exit game" << std::endl;
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

                    case 3:
                        gameRun = false;
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
                
                activeHero = Hero();
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

                std::cout << " 1. Show fighter stats \n 2. Train \n 3. Fight in the ring (1v1) \n 4. Fight in a tournament \n 5. Fight Caesar \n 6. Rest \n 7. Shop \n 8. Go to main menu" << std::endl;
                choiceInt = 0;
                inputErrorCheck();
                std::cin >> choiceInt;
                
                if (choiceInt > 0 && choiceInt <= 8) {
                    switch(choiceInt) {
                        case 1: // Get stats
                            if(enableDebug == true) {std::cout << "Stats print" << std::endl;}
                            activeHero.getCurrentStats();
                            
                            break;

                        case 2: // Train
                            if(enableDebug == true) {std::cout << "Training grounds" << std::endl;}
                            activeCombatEncounter.push_back(trainingDummy);
                            gameState = inFight;
                            break;

                        case 3: // Arena
                            if(enableDebug == true) {std::cout << "Arena grounds" << std::endl;}
                            std::cout << "Please select an opponent! \n" << 
                            " 1. Weak fighter\n 2. Strong fighter\n 3. Stronger fighter\n 4. Strongest fighter\n 5. Gorilla\n 6. Lion\n 7. Elephant" << std::endl;

                            choiceInt = 0;
                            inputErrorCheck();
                            std::cin >> choiceInt;
                            
                            if (choiceInt > 0 && choiceInt <= 7) {
                                switch(choiceInt) {
                                    case 1:
                                        activeCombatEncounter.push_back(weakFighter);
                                        break;
                                    
                                    case 2:
                                        activeCombatEncounter.push_back(strongFighter);
                                        break;
                                        
                                    case 3:
                                        activeCombatEncounter.push_back(strongerFighter);
                                        break;
                                        
                                    case 4:
                                        activeCombatEncounter.push_back(strongestFighter);
                                        break;
                                        
                                    case 5:
                                        activeCombatEncounter.push_back(gorilla);
                                        break;
                                        
                                    case 6:
                                        activeCombatEncounter.push_back(lion);
                                        break;
                                        
                                    case 7:
                                        activeCombatEncounter.push_back(elephant);
                                        break;
                                }
                            gameState = inFight;
                            }
                                        
                            break;

                        case 4: // Tournament
                            std::cout << "\nWelcome to tournaments! Choose a tournament to compete!" << 
                            "\n 1. Easy tournament - 5 gold reward\n 2. Medium tournament - 10 gold \n 3. Hard tournment - 25 gold \n 4. Exit" <<std::endl;
                            
                            choiceInt = 0;
                            inputErrorCheck();
                            std::cin >> choiceInt;
                            
                            if (choiceInt > 0 && choiceInt <= 4) {
                                switch(choiceInt) {
                                    case 1:
                                        activeTournament = Tournament("Easy tournament", 3, activeHero.getCurrentLevel()-3, 5, enemyVector);
                                        break;


                                    case 2:
                                        activeTournament = Tournament("Medium tournament", 4, activeHero.getCurrentLevel(), 10, enemyVector);
                                        break;

                                    case 3:
                                        activeTournament = Tournament("Hard tournament", 5, activeHero.getCurrentLevel()+3, 25, enemyVector);
                                        break;

                                    case 4:
                                        if (enableDebug == true) {
                                            std::cout << "Leaving tournaments" << std::endl;
                                        }
                                        break;
                                }
                            }
                            if (choiceInt == 4) {
                                break;
                            }
                            activeCombatEncounter = activeTournament.getEnemies();
                            isTournament = true;       
                            gameState = inFight;
                            std::cout << "start fight" << std::endl;
                            
                            break;

                        case 5: // Boss fight
                            if(enableDebug == true) {std::cout << "Boss fight" << std::endl;}
                            activeCombatEncounter.push_back(caesar);
                            gameState = inFight;
                            break;

                        case 6: // Heal
                            if(enableDebug == true) {std::cout << "Heal print" << std::endl;}
                            activeHero.healHeroFull();
                            
                            break;

                        case 7: // Shop
                            gameState = shopMenu;
                            
                            break;

                        case 8: // Main menu
                            if(enableDebug == true) {std::cout << "Return to main menu" << std::endl;}
                            gameState = startMenu;

                            for (int i = 0; i < storedHeros.size(); i++) {
                                if (activeHero.getName() == storedHeros[i].getName()){
                                    storedHeros[i] = activeHero;
                                }
                                activeHero = Hero();
                            }
                            
                            break;

                        default: 
                            invalidInputPrint();
                            
                            break;
                    }
                }
                break;



            case inFight:
                if(enableDebug == true) {std::cout << "inFight state" << std::endl;}

                xpReward = 0;
                currentTurn = playerTurn;
            

                // Start fight
                
                currentEnemy = activeCombatEncounter[0];
                //currentEnemy.addModifier();
                
                std::cout << "\nYou enter the arena, your opponent is " << currentEnemy.getName() << " with " << currentEnemy.getHP() << " HP" << std::endl;;
                while(activeCombatEncounter.size() != 0 && activeHero.getStatus() == true) {
                    switch (currentTurn) {
                        case playerTurn:
                            // Player option select
                            std::cout << "\nYour turn\n \nWhat do you want to do?\n 1. Attack\n 2. Drink a potion\n 3. Run, you will still take damage once" << std::endl;
                            
                            choiceInt = 0;
                            inputErrorCheck();
                            std::cin >> choiceInt;
                            
                            if (choiceInt > 0 && choiceInt <= 3) {
                                currentTurn = enemyTurn;
                                switch(choiceInt) {
                                    case 1:
                                        xpReward = currentEnemy.takeDamage(activeHero.getStrength());

                                        if (xpReward == 0) {
                                            std::cout << "HUARH   you deal " << activeHero.getStrength() << " damage to " << currentEnemy.getName() << "\n" << currentEnemy.getName() << " has " << currentEnemy.getHP() << " HP left"<<std::endl;
                                        } else {
                                            currentTurn = enemyDefeated;
                                            break;
                                        }
                                    break;

                                    case 2:
                                        activeHero.usePotion();
                                    break;

                                    case 3:
                                        std::cout << "You run like a coward and lose 200 XP" << std::endl;
                                        activeHero.giveXP(-200);
                                        activeCombatEncounter.clear();
                                    break;
                                }
                            }
                            break;
                        
                        case enemyTurn:
                            // Enemy do damage
                            std::cout << "\nEnemys turn\n" << std::endl;
                            activeHero.takeDamage(currentEnemy.doDamage());    // Deal damage to the player
                            if (activeHero.getStatus() == false) {                           // If the player reaches 0 hitpoints, game is over
                                
                                for (int i = 0; i < storedHeros.size(); i++) {              // Loop through all saved fighters
                                    if (activeHero.getName() == storedHeros[i].getName()){  // If a fighters name matches the fighter checked
                                        storedHeros.erase(storedHeros.begin()+i);           // Delete that fighter as he is dead
                                    }
                                }
                                //activeHero = Hero();    // Copy the clean hero, this ensures the player actually starts a new char for certain
                                
                                gameState = startMenu;

                            }
                            currentTurn = playerTurn;
                            break;

                        case enemyDefeated:
                            activeHero.giveXP(xpReward);
                            activeCombatEncounter.erase(activeCombatEncounter.begin()); // Removes the first object in the combat encounter, this clears the currently defeated enemy
                            
                            if (activeCombatEncounter.size() != 0) {    // If the combat que still has enemies, take the next enemy in line
                                currentEnemy = activeCombatEncounter[0];// Copy the next enemy to be the current enemy
                                std::cout << "\nYou defeated one opponent, but can you defeat the next? " << currentEnemy.getName() << " has entered the arena\n" << std::endl;
                                currentTurn = playerTurn;               // Go back to fighting
                            } else {                                    // If the combat que no longer has enemies, inform the player, combat will automatically break due to combat que not having elements
                                std::cout << "\nCongratulations, you have defeated all enemies, for now...\n" << std::endl;
                            }

                        break;

                    }
                    
                }

                if (activeHero.getCurrentHP() > 0 && activeHero.getName() != "unnamed") {
                    gameState = gameMenu;

                    if (isTournament == true) {
                        isTournament = false;
                        std::cout << "You won the " << activeTournament.getName() << "! You recieve " << activeTournament.getGold() << " gold." << std::endl;
                        activeHero.giveGold(activeTournament.getGold());
                    }
                }

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