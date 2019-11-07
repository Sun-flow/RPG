#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

class Character {
    private:
        std::string playerName;
        std::string charName;

        int stats[5];
        std::vector<std::string> beliefs;
        
        Injuries injuries;

    public:
        Character();
        Character(std::string inName, int &statArray, std::vector<std::string> inBeliefs);

        void setPlayerName(char inName);
        void setCharName(char inName);
        void setStats(int stats[]);
        void setBelief(int beliefNum, std::string belief);
        void setInjuries(std::vector< std::vector< bool > > inInjuries);
        void addBelief(std::string inBelief);
        void changeStat(int statNum, int newStat);
        void addInjury(int severity, std::string description )

        
        //void endSession(text.file);
};


class Injuries {
    private:
        std::vector< std::vector< std::string > > injuries;

    public:
        Injuries();
        Injuries(std::vector< std::vector <std::string > > inInjuries);
        ~Injuries();

        void setInjuries();
        void addInjury(int severity, std::string description);

}
