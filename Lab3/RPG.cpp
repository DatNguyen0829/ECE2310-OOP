#include "RPG.h"

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