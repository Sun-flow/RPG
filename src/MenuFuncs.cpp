#include "MenuFuncs.h"
#include <limits>

bool validBool(){
    std::string in;
    while(1 == 1){
        std::cin >> in;
        if(in == "N" || in == "n"){
            return false;                    
        }
        else if(in == "Y" || in == "y"){
            return true;
        }
        else{
            std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
            std::cout << "Please input 'Y' if your entry is correct, and 'N' if you would like to input a different entry" << std::endl;
        }
    }
}

bool validBool(std::string in){
    while(1 == 1){
        if(in == "N" || in == "n"){
            return false;                    
        }
        else if(in == "Y" || in == "y"){
            return true;
        }
        else{
            std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
            std::cout << "Please input 'Y' if your entry is correct, and 'N' if you would like to input a different entry" << std::endl;
        }
    }
}

bool validNum(int choices, int in){
    if(in >= 1 && in <= choices){
        return true;
    }
    else if(in < 1 || in > choices){
        return false;
    }
    else{
        return false;
    }
}


std::string getBool(std::string in){
    bool end = false;
    
    do{
        std::cout << "You input: " << in << std::endl << "Is that what you desired? Y/N" << std::endl;
        end = validBool();
        if(!end){
            std::cout << "Please provide the correct entry." << std::endl;
            std::cin >> in;
        }
    }while(!end);

    return in;
}

int getNum(int choices){
    bool end = false;
    int in;
    std::cout << "> ";
    
    //std::cin >> in;

    do{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(std::cin >> in){
            end = validNum(choices, in);
        }
        else if(std::cin.bad()){
            std::cout << "Bad Input" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else{
            std::cout << "Failed Input" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(!end){
            std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
            std::cout << "Please input a value between 1 and " << choices << "." << std::endl;            
        }
    }while(!end);
    return in;
}