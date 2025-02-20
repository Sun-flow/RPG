#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Injuries.h"
#include "Moves.h"


class Character {
    private:
        std::string playerName;
        std::string charName;
        std::string pronouns;
        int stats[6]; //1Grit, 2Focus, 3Survival, 4Empathy, 5Brains, 6Influence
        //


        struct nature{
            std::string name;
            int value;
        };

        struct pairs{
            nature first;
            nature second;
        };

        pairs nature[7]; //(Goofy -- Serious), (Impulsive - Measured), (Violent - Peaceful), (Introvert - Extrovert), (Composed - Lost) (Creative, Analytical)
        //1Seriousness, 2Impulsiveness, 3Violence, 4Extroversion, 5Composure, 6Creativity, 
        //Paranoid - Realistic, Optimistic -- Pessimistic, Emotional -- reserved, 
        
        
        
        
        Moves charMoves;
        
        
        std::vector<std::string> beliefs;

        std::vector<std::string> items;
        
        Injuries injuries;
    public:
        Character();
        Character(std::string inPlayerName, std::string inCharName, std::string inPronouns, std::vector< int >inStatArray);
        Character(std::string inputFile);


        void CharToString();
       
        int RollStat(int whichStat);
        void ChangeInfo();

        
       
        void printInjuries();

        void printStats();
        void printNatures();

        void printFullMoves();
        void printSingleMove(int whichMove);
        
        void constructPairs();
        void constructPair(int which, std::string first, std::string second);

        void createMove();
        void changeMove();
        
        void setPlayerName(std::string inName);
        void setCharName(std::string inName);
        
        void setStats(std::vector< int > inStats);
        void statManip(int answer, std::vector< std::vector< int > > whichStat, std::vector< std::vector< int > > modifyStat, std::vector< std::vector< int > > whichNature, std::vector< std::vector< int > > modifyNature);
        void changeStat(std::vector< int > which, std::vector< int > modify);
        void changeStat(int which, int modify);
        void changeAlignment(std::vector< int > which, std::vector< int > modify);
        
        void getItem(std::string);
        
        void setBelief(int beliefNum, std::string belief);
        void setInjuries(std::vector< std::vector< bool > > inInjuries);
        void addBelief(std::string inBelief);
        //void changeStat(int statNum, int newStat);
        void addInjury(int severity, std::string description);
        
        int DMovesSize();


        void addMove(int inWhichMod, std::string inName, std::string inDesc);
        int rollMove(int whichMove);


        void editMove(int inWhichMove, int whichPart);

        //void endSession(text.file);
};

#endif

//EXP earned through hitting natures, when enough pips are earned roll "remember", which can be used to save one'sself from a failed roll and recall something about the character or the world outside the dome. 

/*Game where characters are generated, then the one shot is them regaining lost memories in the form of a story that plays out with flashbacks while something is happening in real time, maybe like a survival game type thing? Where players have all intentionally lost their memories, then been placed in a world they dont understand or recognize and forced to fight/compete live in a place with a weird outside threat (oh shit, im making a mazerunner game)

In this game, you will be playing as a character who has lost their memories. Tell me about yourself, before I you lose it all.

Ask them questions about their life, things that are general enough to be applicable to many people. 

End with the question "were you the first group, or the last" and then have some characters have lived experience in the world that they will expidite themselves. 

Give exp when they act in line with their natures. As players play their nature, they are able to grow closer to "escaping"

"When in danger, are you more likely to fight, flee, or freeze?" 

"What is the best quality in a friend?"

"What is something you struggle with?"

"What sort of person is least trustworthy?"




"What career were you in?"

"Were you part of the first group, or the last?"


*/