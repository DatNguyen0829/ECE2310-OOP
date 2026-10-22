// main.cpp
#include <iostream>
#include "RPG.h"
#include "Game.h"

using namespace std;

int main(){
    
    Game mainGame = Game();

    const int num_players = 10; // number of players in the game

    mainGame.generatePlayers(num_players); // Generate the number of players

    mainGame.gameLoop(); // Start the game loop

    mainGame.printFinalResults(); // Print out the final results after all the rounds

    return 0;
}
