#include "Character.h"
#include <vector>
#include <iostream>

Character::Character(){
    setPlayerName("");
    setCharName("");
    setStats({0,0,0,0,0,0});
    //beliefs = new std::vector< std::vector < std::string > >;
    //instincts = null;
}

//Character::~Character(){

//}

Character::Character(std::string inPlayerName, std::string inCharName, std::string inPronouns, std::vector< int >inStatsArray){
    setPlayerName(inPlayerName);
    setCharName(inCharName);
    pronouns = inPronouns;
    setStats(inStatsArray);
    constructPairs();

}

void Character::constructPairs(){
    constructPair(0, "Goofy", "Serious");
    constructPair(1, "Impulsive", "Measured");
    constructPair(2, "Violent", "Peaceful");
    constructPair(3, "Introvert", "Extrovert");
    constructPair(4, "Composed", "Lost");
    constructPair(5, "Creative", "Analytical");
    constructPair(6, "Thinking", "Feeling");
}

void Character::constructPair(int which, std::string first, std::string second){
    nature[which].first = {first, 0};
    nature[which].second = {second, 0};
}

void Character::CharToString(){
    std::cout << "Player:       " << playerName << std::endl;
    std::cout << "Character:    " << charName << std::endl;
    std::cout << "Pronouns:     " << pronouns << std::endl;
    printStats();
    printNatures();
}

void Character::printStats(){
    std::cout << "--------Stats--------" << std::endl;
    std::cout << "| Grit:           " << stats[0] << " |" << std::endl;
    std::cout << "| Focus:          " << stats[1] << " |" << std::endl;
    std::cout << "| Resourceful:    " << stats[2] << " |" << std::endl;
    std::cout << "| Empathy:        " << stats[3] << " |" << std::endl;
    std::cout << "| Quick:          " << stats[4] << " |" << std::endl;
    std::cout << "| Control:        " << stats[5] << " |" << std::endl;
    std::cout << "---------------------" << std::endl;

}

void Character::printNatures(){
    std::cout << "~~Natures~~" << std::endl << "-- ";
    for(auto pair : nature){
        if(pair.first.value > pair.second.value && pair.first.value != 0){
            std::cout << pair.first.name << " -- ";
        }
        else if(pair.second.value != 0){
            std::cout << pair.second.name << " -- ";
        }
    }
    std::cout << std::endl;

}

void Character::printFullMoves(){
    charMoves.printFullMoves();
}

void Character::printSingleMove(int whichMove){
    charMoves.printSingleMove(whichMove);
}

void Character::setPlayerName(std::string inName){
    playerName = inName;
}

void Character::setCharName(std::string inName){
    charName = inName;
}

void Character::setStats(std::vector< int > inStats){
    int i = 0;
    while(!inStats.empty()){ //use array size later
        stats[i] = inStats.back();
        inStats.pop_back();
        i++;
    }
}

void Character::statManip(int answer, std::vector< std::vector< int > > whichStat, std::vector< std::vector< int > > modifyStat, std::vector< std::vector< int > > whichNature, std::vector< std::vector< int > > modifyNature){
    changeStat(whichStat[answer - 1], modifyStat[answer - 1]);
    changeAlignment(whichNature[answer - 1], modifyNature[answer - 1]);
}


void Character::changeStat(std::vector< int > which, std::vector < int > modify){
    while(!which.empty()){
        stats[which.back() - 1] += modify.back();
        which.pop_back();
        modify.pop_back();
    }
}

void Character::changeAlignment(std::vector< int > which, std::vector < int > modify){
    while(!which.empty()){
        if(modify.back() == 1){
            nature[which.back() - 1].first.value += 1;
        }
        else{
            nature[which.back() - 1].second.value += 1;
        }
        which.pop_back();
        modify.pop_back();
    }

}

void Character::getItem(std::string inItem){
    items.push_back(inItem);
}

void Character::setBelief(int beliefNum, std::string belief){
    beliefs[beliefNum] = belief;
}

void Character::addBelief(std::string inBelief){
    beliefs.push_back(inBelief);
}

void Character::changeStat(int statNum, int newStat){
    stats[statNum] = newStat;
}

void Character::addInjury(int severity, std::string description){
    injuries.addInjury(severity, description);
}

int Character::DMovesSize(){
    return charMoves.DMovesSize();
}

void Character::addMove(int inWhichMod, std::string inName, std::string inDesc){
    charMoves.addMove(inWhichMod, inName, inDesc);
}

int Character::rollMove(int whichMove){

    int moveMod = stats[charMoves.whichMod(whichMove - 1) - 1];
    return charMoves.rollMove(moveMod);
}

void Character::editMove(int inWhichMove, int whichPart){
    charMoves.editMove(inWhichMove, whichPart);
}