#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Injuries.h"




class Character {
    private:
        std::string playerName;
        std::string charName;
        int stats[5]; //Authority, Focus, Sharp, Empathy, Hunger
        struct nature{
            std::string name;
            int value;
        };
        struct pairs{
            nature first;
            nature second;
        };
        pairs nature[3]; //(Chaotic - Lawful), (Impulsive - Stoic), (Violent - Peaceful), (Introvert - Extrovert), (Spiritual, Pragmatic)
        //Lawfullness, Impulsiveness, Violence, Extroversion, Spirituality
        std::vector<std::string> beliefs;
        
        Injuries injuries;
    public:
        Character();
        Character(std::string inPlayerName, std::string inCharName, int inStatArray[]);
        void toString();
        void printStats();
        void constructPairs();
        void constructPair(int which, std::string first, std::string second);
        void setPlayerName(std::string inName);
        void setCharName(std::string inName);
        void setStats(std::vector< int > inStats);
        void changeStat(std::vector< int > which, std::vector< int > modify);
        void changeStat(int which, int modify);
        void changeAlignment(std::vector< int > which, std::vector< int > modify);
        void setBelief(int beliefNum, std::string belief);
        void setInjuries(std::vector< std::vector< bool > > inInjuries);
        void addBelief(std::string inBelief);
        //void changeStat(int statNum, int newStat);
        void addInjury(int severity, std::string description);
        
        //void endSession(text.file);
};

#endif