// main.cpp
#include <iostream>
#include "RPG.h"

using namespace std;

int main(){
    
    RPG player1 = RPG();
    RPG player2 = RPG("Dat", 0, 0.2, 60, 1);

    // Player 1 info
    cout << player1.getName() << " Current stats: " << endl;
    cout << "Hits taken: " << player1.getHitsTaken() 
            << "\t Luck: " << player1.getLuck()
            << "\t Exp: " << player1.getExp()
            << "\t Level: " << player1.getLevel() << endl;
    
    // Player 2 info
    cout << player2.getName() << " Current stats: " << endl;
    cout << "Hits taken: " << player2.getHitsTaken() 
            << "\t Luck: " << player2.getLuck()
            << "\t Exp: " << player2.getExp()
            << "\t Level: " << player2.getLevel() << endl;
    
    // Sets the hits taken on player2
    player2.setHitsTaken(2);

    // Prints out player's 2 hits taken:
    cout << "Player2's hit taken: " << player2.getHitsTaken() << endl;

    cout << "0 is dead, 1 is alive " << endl;
    if (player2.isAlive()){
        cout << "Player2 is alive" << endl;
    } else {
        cout << "Player2 is dead" << endl;
    }
    return 0;
}
