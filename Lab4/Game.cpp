#include "Game.h"
#include <random>

Game :: Game(){

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
    uniform_real_distribution<int> dist(0, this->live_players.size()-1);

    // Pick random index
    int randomIndex = dist(gen);

    // Advance iterator to that index
    set<int>::iterator it = this->live_players.begin();
    advance(it, randomIndex);

    int selectedIndex = *it;
    return selectedIndex;

}