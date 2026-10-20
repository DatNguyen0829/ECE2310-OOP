#include "RPG.h"
#include <iostream>
#include <random>

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

 /**
  * @brief updates name
  * 
  * @param name
  */
 void RPG :: setName(string name){
    this->name = name;
 }

 /**
  * @brief increase RPG's experience by 50
  *        After updating, if RPG's experience is >= 100.0,
  *        increase RPG's level by 1, reset their experience to 0,
  *        and increase their luck level by 0.1
  * 
  */

 void RPG :: updateExpLevel(){
    this->exp += 50;

    if (this->exp >= 100.0 ){
        this->exp = 0;
        this->level++;
        this->luck += 0.1;
    }
 }

 /**
  * @brief Hits or misses the opponents at random. Luck is a form of defense
  *        The higher the opponent's luck, the more likely that attack will miss.
  *        If the attack is a hit, the opponent's hit taken should increment by 1. 
  * 
  * @param opponnent: RPG *
  */
 void RPG :: attack(RPG* opponent){
    random_device rd;
    mt19937 gen(rd()); // seed with random
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    bool hit = random_num > (HIT_FACTOR*(opponent->getLuck()));
    if(hit){
        opponent->setHitsTaken(opponent->getHitsTaken() + 1); // Increment hits taken of the opponent is hit
    }
 }

 /**
  * @brief Prints in the format:
  *        "NAME: , HITS_TAKEN: , LUCK: , Exp: , Level: , Status: "
  * 
  */
 void RPG :: printStats(){
    cout << "Name: " << this->getName() <<  "\tHits Taken: " << this->getHitsTaken() <<
    "\tLuck: " << this->getLuck() << "\tExp: " << this->getExp() << "\tLevel: " << this->getLevel() <<
    "\t Status: " << this->isAlive() << endl;
 }
