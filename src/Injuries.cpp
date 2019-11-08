#include "Injuries.h"

Injuries::Injuries(){

}

Injuries::Injuries(std::vector< std::vector <std::string > > inInjuries){
    setInjuries(inInjuries);
}

Injuries::~Injuries(){

}

void Injuries::setInjuries(){
    
}

void Injuries::setInjuries(std::vector< std::vector< std::string > > inInjuries){
    injuries = inInjuries;
}

void Injuries::addInjury(int severity, std::string description){
    injuries[severity].push_back(description);
}