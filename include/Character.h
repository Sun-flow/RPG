#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Injuries.h"


class Character {
    private:
        std::string playerName;
        std::string charName;
        int stats[5];
        std::vector<std::string> beliefs;
        
        Injuries injuries;
    public:
        Character();
        Character(std::string inPlayerName, std::string inCharName, int inStatArray[], std::vector<std::string> inBeliefs);
        void setPlayerName(std::string inName);
        void setCharName(std::string inName);
        void setStats(int stats[]);
        void setBelief(int beliefNum, std::string belief);
        void setInjuries(std::vector< std::vector< bool > > inInjuries);
        void addBelief(std::string inBelief);
        void changeStat(int statNum, int newStat);
        void addInjury(int severity, std::string description);
        
        //void endSession(text.file);
};

#endif