// Game.h
#ifndef GAME_H
#define GAME_H

#include "RPG.h"
#include <set>
#include <vector>
#include <string>

using namespace std;

class Game{

    private:

        vector<RPG*> players;
        set<int> live_players; // Indices of players who are alive

    public:
        // -- Class construction and destruction --
        Game();
        ~Game();

        // Behavioral functions
        void generatePlayers(int n);
        int selectPlayer();
        void endRound(RPG* winner, RPG* loser, int loserIndex);
        void battleRound();
        void gameLoop();
        void printFinalResults();   

};

#endif