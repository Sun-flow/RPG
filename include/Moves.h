#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <random>
#include <ctime>
#include <vector>

class Moves { 
    private:

        struct Move {
            int WhichMod;
            std::string Name;
            std::string Desc;
        };

        std::uniform_int_distribution<int> D6_dist;
        std::default_random_engine DiceRoller;
        
        std::vector< Move > DMoves;
        

    public:

        Moves();
        //~Moves();

        void addMove(int inWhichMod, std::string inName, std::string inDesc);

        int rollMove(int moveMod);

        void printFullMoves();
        void printSingleMove(int whichMove);

        int whichMod(int whichMove);

        int DMovesSize();

        void editMove(int inWhichMove, int whichPart);
};

#endif