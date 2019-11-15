#include "Character.h"
#include "mainFoo.h"
#include <iostream>
int main(int argc, char *argv[]){
    std::string playerName;
    std::string charName;

    int stats[5] = {0,0,0,0,0};
    std::vector<std::string> beliefs;

    std::cout << "Lets make a character!" << std::endl;

    std::cout << "First, what's YOUR name?" << std::endl;

    bool correct = false;
    std::string in;

    do{
        std::cin >> playerName;

        std::cout << "Your name is: " << playerName << std::endl;
        std::cout << "Is this correct? Y/N" << std::endl;

        do{
        std::cin >> in;
            if(in == "N" || in == "n"){
                std::cout << "Ok! Please input the name you desire." << std::endl;
                break;
            }
            else if(in == "Y" || in == "y"){
                correct = true;
                break;
            }
            else{
                std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
                std::cout << "Please input 'Y' if your name is correct, and 'N' if you would like to input a different name" << std::endl;
            }
        }while(!correct);
    }while(!correct);

    std::cout << "Lovely! Welcome, " << playerName << "." << std::endl;

    std::cout << "Now, lets get started on your character." << std::endl;

    std::cout << "Do you have a name in mind for your character? You may also set a name later. Y/N" << std::endl;
    correct = false;
    bool hasCharName = false;
    do{
        std::cin >> in;

        if(in == "N" || in == "n"){
            hasCharName = false;
            break;
        }
        else if(in == "Y" || in == "y"){
            hasCharName = true;
            break;
        }
        else{
            std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
            std::cout << "Please input 'Y' if you have a name in mind, and 'N' if you would like to input a name later" << std::endl;
        }
    }while(1 == 1);

    if(hasCharName){
        
        std::cout << "Great! Please input your desired Character's name now." << std::endl;
        correct = false;
        do{
            std::cin >> charName;

            std::cout << "Your Character's name is: " << charName << std::endl;
            std::cout << "Is this the name you'd like to go with? Y/N" << std::endl;

            do{
            std::cin >> in;
                if(in == "N" || in == "n"){
                    std::cout << "Please input another name" << std::endl;
                    break;
                }
                else if(in == "Y" || in == "y"){
                    correct = true;
                    break;
                }
                else{
                    std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
                    std::cout << "Please input 'Y' if your name is correct, and 'N' if you would like to input a different name" << std::endl;
                }
            }while(!correct);
        }while(!correct);
    }
    Character Character(playerName, charName, stats);
    std::cout << "Time for the fun part: a quiz!" << std::endl << "Fear not, this quiz isn't graded. It will, however, be used to determine your character's starting stats." << std::endl << "Answer wisely!" << std::endl;
    
    int answer;
    std::cout << "You awaken to find yourself locked in a cell. How do you escape?" << std::endl;
    std::cout << "1. Smash the cell door." << 
    std::endl << "2. Pick the lock." << 
    std::endl << "3. Bribe the Guard." << 
    std::endl << "4. Trick the guard." << 
    std::endl <<"5. Stay in the cell." << std::endl;

    answer = getNum(5);
    if(answer == 1){
        Character.changeStat({}, {2, -1});

    }
    else if(answer == 2){
        Character.changeStat({2, 1}, {2, -1});
    }
    else if(answer == 3){
        Character.changeStat({2, 4, 5}, {1, 1, -1});
    }
    else if (answer == 4){
        Character.changeStat({1, 4}, {-1, 2});
    }
    else if(answer == 5){
        Character.changeStat({3, 4, 5}, {2, -2, 1});
    }

    std::cout << "You've escaped the jail and find yourself in a bustling city." << std::endl;
    std::cout << "What is the first thing you search for?"  << std::endl;
    std::cout << "1. A weapon." <<
    std::endl << "2. An ally." <<
    std::endl << "3. A job." << std::endl;

    answer = getNum(3);

    if(answer == 1){
        Character.changeStat({1, 2, 5}, {2, 1, -2});
    }
    else if(answer == 2){
        Character.changeStat({1, 4, 5}, {-1, 1, 1});
    }
    else if(answer == 3){
        Character.changeStat({2, 3, 5}, {-2, 1, 2});
    }

    std::cout << "From where do you draw strength?" << std::endl;
    std::cout << "1. Community." <<
    std::endl << "2. An unholy amulet." <<
    std::endl << "3. The summation of my struggles." << 
    std::endl << "4. My Mother's love." <<
    std::endl << "5. Food." <<
    std::endl << "6. My own sharp intellect." <<
    std::endl << "7. Luck" << std::endl;

    answer = getNum(3);

    if(answer == 1){
        Character.changeStat({5}, {1});
    }
    else if(answer == 2){
        Character.changeStat({}, {-1, 1, 1});
    }
    else if(answer == 3){
        Character.changeStat({2, 3, 5}, {-2, 1, 2});
    }
    else if(answer == 4){
        Character.changeStat({1, 4, 5,}, {-1, 1, 1});
    }
    else if(answer == 5){
        Character.changeStat({2, 3, 5}, {-2, 1, 2});
    }
    else if(answer == 6){
        Character.changeStat({1, 4, 5,}, {-1, 1, 1});
    }
    else if(answer == 7){
        Character.changeStat({2, 3, 5}, {-2, 1, 2});
    }


    Character.toString();
}
