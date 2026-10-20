// main.cpp
#include <iostream>
#include "RPG.h"

using namespace std;

int main(){
    
    RPG player1 = RPG();
    RPG player2 = RPG("Dat", 0, 0.2, 60, 1);

    player2.printStats();
    
    return 0;
}
