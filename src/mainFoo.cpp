#include <string>
#include <iostream>

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
    while(1 == 1){
        if(in >= 1 || in < choices){
            return true;
        }
        else if(in < 1 || in > choices){
            return false;
        }
        else{
            return false;
        }
    }
}


std::string getBool(){
    bool end = false;
    std::string in;
    std::cin >> in;
    
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
    std::cin >> in;

    do{
        std::cout << "You input: " << in << std::endl << "Is that what you desired? Y/N" << std::endl;
        end = validNum(choices, in);
        if(!end){
            std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
            std::cout << "Please input a value between 1 and " << choices << "." << std::endl;
            std::cin >> in;
        }
    }while(!end);
    return in;
}