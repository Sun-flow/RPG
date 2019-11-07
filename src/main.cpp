#include "Character.h"
#include <iostream>
int main(int argc, char *argv[]){
    std::string playerName;
    std::string charName;

    int stats[5];
    std::vector<std::string> beliefs;

    std::cout << "Lets make a character!" << std::endl;

    std::cout << "First, what's YOUR name?" << std::endl;

    bool correct = false;
    char in;

    do{
        std::cin >> playerName;

        std::cout << "Your name is: " << playerName << std::endl;
        std::cout << "Is this correct? Y/N" << std::endl;

        do{
        std::cin >> in;
            if(in == 'N' || in == 'n'){
                break;
            }
            else if(in == 'Y' || in == 'y'){
                correct = true;
                break;
            }
            else{
                std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
                std::cout << "Please input 'Y' if your name is correct, and 'N' if you would like to input a different name" << std::endl;
            }
        }while(!correct);
    }while(!correct);

    std::cout << "Lovely! Welcome, " << playerName << std::endl;

    std::cout << "Now, lets get started on your character." << std::endl;

    std::cout << "Do you have a name in mind for your character?" << std::endl;
    do{
        std::cin >> in;

        if(in == 'N' || in == 'n'){
        }
        else if(in == 'Y' || in == 'y'){
            correct = true;
            break;
        }
        else{
            std::cout << "buh" << std::endl;
        }
    }while(1 == 1);

}
