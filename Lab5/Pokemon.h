// Pokemon.h
#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

using namespace std;

class Pokemon{

    protected:
        // -- Member Variables --
        string name;
        int hp;
        int attack;
        int defense;
        vector<string> type;

    public:
        // -- Constructors -- 
        Pokemon();
        Pokemon(string name, int hp, int attack, int defense, vector<string> type);
        // -- Mutators
        virtual void speak();
        virtual void printStats();
};

#endif