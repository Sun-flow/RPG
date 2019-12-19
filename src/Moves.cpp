#include "Moves.h"
#include <random>
#include <string>
#include <iostream>
#include "MenuFuncs.h"
#include <vector>

Moves::Moves(){

    std::random_device randSeed;

    std::default_random_engine Roller(randSeed());
    DiceRoller = Roller;

    std::uniform_int_distribution<int> dist(1, 6);
    D6_dist = dist;
}

void Moves::addMove(int inWhichMod, std::string inName, std::string inDesc){
    Moves::Move newMove;
    newMove.WhichMod = inWhichMod;
    newMove.Name = inName;
    newMove.Desc = inDesc;

    DMoves.push_back(newMove);
}

int Moves::rollMove(int moveMod){
    int roll1 = D6_dist(DiceRoller);
    int roll2 = D6_dist(DiceRoller);

    std::cout << "Roll: " << roll1 << " + " << roll2 << " + " << moveMod << std::endl;
    return roll1 + roll2 + moveMod;
}


void Moves::printFullMoves(){
    int i = 1;
    std::cout << "~~~~~~~ Moves List ~~~~~~~~ " << std::endl;
    for(auto move : DMoves){
        std::cout << i << ": " << move.Name << std::endl;
        i++;
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Moves::printSingleMove(int whichMove){
    std::cout << "Move: " <<DMoves[whichMove - 1].Name << 
    std::endl << "Description: " << DMoves[whichMove - 1].Desc << std::endl;

    //TODO: Show relevant stat (+stat)
}

int Moves::whichMod(int whichMove){
    return DMoves[whichMove].WhichMod;
}

int Moves::DMovesSize(){
    return DMoves.size();
}

void Moves::editMove(int inWhichMove, int whichPart){
    switch(whichPart){
        case 1:
        {
            std::cout << "Please input the desired move name." << std::endl;
            std::string newName;
            getline(std::cin >> std::ws, newName);
            DMoves[inWhichMove - 1].Name = newName;
            break;
        }
        case 2:
        {
            std::cout << "Please input the desired move description." << std::endl;
            std::string newDesc;
            getline(std::cin >> std::ws, newDesc);
            DMoves[inWhichMove - 1].Desc = newDesc;
            break;
        }
        case 3:
        {
            std::cout << "Please input the desired relevant stat." << std::endl;
            int newStat = getNum(6);
            DMoves[inWhichMove - 1].WhichMod = newStat;
            break;
        }
        case 4:
        {
            DMoves.erase(DMoves.begin() + inWhichMove - 1);
            break;
        }
    }

    
}