// Charmander.h
#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "Pokemon.h"
#include <string>
#include <vector>

using namespace std;

class Charmander : public Pokemon{

    private:
        // -- Member Variables --
        vector<string> skills;

    public:
        // -- Constructors -- 
        Charmander();
        Charmander(string name, int hp, int attack, int defense,
                   vector<string> type,
                   vector<string> skills);
        // -- Mutators
        void speak() override;
        void printStats() override;
};

#endif