#include "Character.h"
#include <vector>

Character::Character(){
    setPlayerName("");
    setCharName("");
    int inStats[5] = {0,0,0,0,0};
    setStats(inStats);
    //beliefs = new std::vector< std::vector < std::string > >;
    //instincts = null;
}

//Character::~Character(){

//}

Character::Character(std::string inPlayerName, std::string inCharName, int inStatsArray[5], std::vector<std::string> inBeliefs){
    setPlayerName(inPlayerName);
    setCharName(inCharName);
    setStats(inStatsArray);
    //setBeliefs(inBeliefs);
}

void Character::setPlayerName(std::string inName){
    playerName = inName;
}

void Character::setCharName(std::string inName){
    charName = inName;
}

void Character::setStats(int inStats[]){
    for(int i = 0; i < 5; i++){ //use array size later
        stats[i] = inStats[i];
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