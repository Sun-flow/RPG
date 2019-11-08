#ifndef INJURIES_H
#define INJURIES_H

#include <vector>
#include <string>

class Injuries {
    private:
        std::vector< std::vector< std::string > > injuries;
    public:
        Injuries();
        Injuries(std::vector< std::vector <std::string > > inInjuries);
        ~Injuries();
        void setInjuries();
        void setInjuries(std::vector< std::vector< std::string > > inInjuries);
        void addInjury(int severity, std::string description);
};

#endif