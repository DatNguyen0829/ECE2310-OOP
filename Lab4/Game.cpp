#include "Game.h"
#include <random>
#include <iostream>

Game :: Game(){

}

Game :: ~Game(){

}
/**
 * @brief creates up to n RPG pointers and update names
 * with ordering. Populate live_players from 0 to n - 1 
 * as players are alive initially. 
 * 
 * @param n: number of players
 */
void Game :: generatePlayers(int n){
    for (int i = 0; i < n; i++){
        this->players.push_back(new RPG());

        // Rename players
        this->players[i]->setName("NPC" + to_string(i));
        this->live_players.insert(i);
    }
}

/**
 * @brief Randomly selects a player (via index) from the set
 * of live_players
 * 
 * @return: int, index for vector players
 */
int Game :: selectPlayer(){
    random_device rd;
    mt19937 gen(rd()); // seed with random
    uniform_int_distribution<int> dist(0, this->live_players.size()-1);

    // Pick random index
    int randomIndex = dist(gen);

    // Advance iterator to that index
    set<int>::iterator it = this->live_players.begin();
    advance(it, randomIndex);

    int selectedIndex = *it;
    return selectedIndex;

}

/**
 * @brief Resets winner's hits_taken to 0.
 * Removes the loser from the live_players.
 * Calls updateExpLevel() for the winner.
 * print "NPC_X won against NPC_Y"
 * 
 */
void Game :: endRound(RPG* winner, RPG* loser, int loserIndex){
    
    // Reward the winner
    winner->setHitsTaken(0);
    winner->updateExpLevel();

    // Print statement
    cout << winner->getName() << " won against " << loser->getName() << endl;

    // Remove the loser
    this->live_players.erase(loserIndex);
}

/**
 * @brief calls selectPlayers() twice to get to 2 players at random.
 * If the players are redundant make a recursive call to battleRound and return.
 * Run a round of hits across player1 and player2 until 1 is alive.
 * Call endRound to highlight who won and update stats.
 * 
 */
void Game :: battleRound(){

    int firstPlayerIndex = this->selectPlayer();
    int secondPlayerIndex = this->selectPlayer();

    if (firstPlayerIndex == secondPlayerIndex){
        battleRound();
        return;
    }

    RPG* firstPlayer = this->players[firstPlayerIndex];
    RPG* secondPlayer = this->players[secondPlayerIndex];

    while (firstPlayer->isAlive() && secondPlayer->isAlive()){
        firstPlayer->attack(secondPlayer);
        if (secondPlayer->isAlive())//Check wheter the second player is alive after being attacked
        { 
          secondPlayer->attack(firstPlayer);  
        }
    }

    if(firstPlayer->isAlive()){
        this->endRound(firstPlayer, secondPlayer, secondPlayerIndex);
    } else{
        this->endRound(secondPlayer, firstPlayer, firstPlayerIndex);
    }
}

/**
 * @brief Runs batteround() until 1 player is alive
 * 
 */
void Game :: gameLoop(){
    while(this->live_players.size() > 1){
        this->battleRound();
    }
}

/**
 * @brief Call printstats on all players
 * 
 */
void Game :: printFinalResults(){
    for(const auto& player : this->players){
        player->printStats();
    }
}
