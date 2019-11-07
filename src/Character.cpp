#include "Character.h"
#include <vector>

Character::Character(){
    playerName = null;
    charName = null;
    statsArray = 0;
    beliefs = null;
    instincts = null;
}

Character::~Character(){

}

Character::Character(std::string inPlayerName, std::string inCharName, int[] inStatArray, std::vector<std::string> inBeliefs){
    setPlayerName(inPlayerName);
    setCharName(inCharName);
    setStats(inStatsArray);
    setBeliefs(inBeliefs);
}

void Character::setPlayerName(std::string inName){
    playerName = inName;
}

void Character::setCharName(std::string inName){
    charName = inName;
}

void Character::setStats(int inStats[]){
    for(int i = 0; i < inStats.size(); i++){
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

Injuries::Injuries(){

}

Injuries::Injuries(std::vector< std::vector <std::string > > inInjuries){
    setInjuries(inInjuries);
}

Injuries::~Injuries(){

}

void Injuries::setInjuries(std::vector< std::vector< std::string > > inInjuries){
    injuries = inInjuries;
}

void Injuries::addInjury(int severity, std::string description){
    injuries[severity].push_back(description);
}