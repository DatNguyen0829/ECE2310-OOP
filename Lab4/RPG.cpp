#include "RPG.h"

// -- Class constructors --
RPG :: RPG(){
    this->name = "NPC";
    this->hits_taken = 0;
    this->luck = 0.1;
    this->exp = 50.0;
    this->level = 1;
}

RPG :: RPG(string name, int hits_taken, float luck, float exp, int level){
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

// -- Accessor Functions --
string RPG :: getName() const{
    return this->name;
}
int RPG :: getHitsTaken() const{
    return this->hits_taken;
}
float RPG :: getLuck() const{
    return this->luck;
}
float RPG :: getExp() const{
    return this->exp;
}
int RPG :: getLevel() const{
    return this->level;
}

// -- Mutator Functions --

/**
 * @brief sets hits taken to new hits
 * 
 */
 void RPG :: setHitsTaken(int new_hits){
    this->hits_taken = new_hits;
 }

 /**
  * @brief returns whether hits_taken is less than MAX_HITS_TAKEN
  * In other words, a player is alive as long as they have not been hit MAX_HITS_TAKEN times
  * @return true : player is alive
  * @return false : player is unalive
  */
 bool RPG :: isAlive() const{
    return this->hits_taken < MAX_HITS_TAKEN;
 }