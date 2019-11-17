#include "Character.h"
#include "mainFoo.h"
#include <iostream>
int main(int argc, char *argv[]){
    std::string playerName;
    std::string charName;
    std::string pronouns;

    std::vector< int > stats({0,0,0,0,0,0});
    std::vector<std::string> beliefs;

    std::cout << "Lets make a character!" << std::endl;

    std::cout << "First, what's YOUR name?" << std::endl;

    bool correct = false;
    std::string in;

    //do{
        std::cin >> playerName;

        std::cout << "Your name is: " << playerName << std::endl;
        /*std::cout << "Is this correct? Y/N" << std::endl;

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
    }while(!correct);*/

    std::cout << "Lovely! Welcome, " << playerName << "." << std::endl;

    std::cout << "Now, lets get started on your character." << std::endl;

    /*std::cout << "Do you have a name in mind for your character? You may also set a name later. Y/N" << std::endl;
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
    }while(1 == 1);*/

    //if(hasCharName){
        
        std::cout << "Please input your desired Character's name now." << std::endl;
        correct = false;
        //do{
            std::cin >> charName;

            std::cout << "Your Character's name is: " << charName << std::endl;
            /*std::cout << "Is this the name you'd like to go with? Y/N" << std::endl;

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
    }*/

    std::cout << "What pronouns should I use for your character?" << std::endl;
    std::cin >> pronouns;


    Character myChar(playerName, charName, pronouns, stats);
    std::cout << "Now, the story begins." << std::endl << "You are about to awaken to find yourself with no memory, in a location unfamiliar to you." << std::endl << "Your job in this world is to survive long enough to figure out who you are, why you've lost your memories, and how to find your way out of here." << std::endl << "Before you wake, I'm going to ask you 10 questions. These questions will tell us both how you are disposed. Figuring out exactly who you were, of course, will be up to you." << std::endl << "Good luck, you're going to need it." << std::endl;
    
    int answer;

    std::cout << "When in danger, are you more likely to:" << std::endl;
    std::cout << "1. Fight." << 
    std::endl << "2. Flee." << 
    std::endl << "3. Freeze." << std::endl;

    answer = getNum(3);

    std::vector< std::vector < int > > whichStats = {{1, 2, 4}, {1, 3, 5}, {1, 2, 4, 6}};
    std::vector< std::vector < int > > modifyStats = {{1, 1, -1}, {-1, 1, 1}, {-1, -1, 1, 1}};
    std::vector< std::vector < int > > whichNatures = {{2, 3, 5}, {2, 3, 5}, {3, 5, 6}};
    std::vector< std::vector < int > > modifyNatures = {{1, 1, 1}, {2, 2, 1}, {2, 2, 2}};


    myChar.statManip(answer, whichStats, modifyStats, whichNatures, modifyNatures);

    std::cout << "You wake in an unfamiliar location. What is the first thing you search for?"  << std::endl;
    std::cout << "1. A weapon." <<
    std::endl << "2. An ally." <<
    std::endl << "3. Food, water, shelter." << std::endl;


    answer = getNum(3);

    myChar.statManip(answer, 
    {{1, 2, 4}, {1, 3, 4, 6}, {2, 3, 6}}, 
    {{2, 1, -2}, {-2, 1, 1, 1}, {1, 1, -1}}, 
    {{1, 3}, {1, 3, 4}, {3, 5, 6}}, 
    {{1, 1}, {2, 2, 2}, {2, 1, 1}}
    );

    

    myChar.toString();
}
