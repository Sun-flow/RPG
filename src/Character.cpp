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

Character::Character(std::string inPlayerName, std::string inCharName, std::vector< int >inStatsArray){
    setPlayerName(inPlayerName);
    setCharName(inCharName);
    setStats(inStatsArray);
    constructPairs();
}

void Character::constructPairs(){
    constructPair(0, "Chaotic", "Lawful");
    constructPair(1, "Impulsive", "Stoic");
    constructPair(2, "Violent", "Peaceful");
    constructPair(3, "Introver", "Extrovert");
    constructPair(4, "Spiritual", "Pragmatic");
    constructPair(5, "Creative", "Logical");
    constructPair(6, "Thinking", "Feeling");
}

void Character::constructPair(int which, std::string first, std::string second){
    nature[which].first = {first, 0};
    nature[which].second = {second, 0};
}

void Character::toString(){
    std::cout << "Player: " << playerName << std::endl;
    std::cout << "Character: " << charName << std::endl;
    std::cout << "--------Stats--------" << std::endl;
    printStats();
    std::cout << "---------------------" << std::endl;
}

void Character::printStats(){
    std::cout << "  Authority:      " << stats[0] << std::endl;
    std::cout << "  Focus:          " << stats[1] << std::endl;
    std::cout << "  Sharp:          " << stats[2] << std::endl;
    std::cout << "  Empathy:        " << stats[3] << std::endl;
    std::cout << "  Hunger:         " << stats[4] << std::endl;
    std::cout << "  Lost:           " << stats[5] << std::endl;
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
        if(modify.back() == 0){
            nature[which.back() - 1].first.value += 1;
        }
        else{
            nature[which.back() - 1].second.value += 1;
        }
        which.pop_back();
        modify.pop_back();
    }

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