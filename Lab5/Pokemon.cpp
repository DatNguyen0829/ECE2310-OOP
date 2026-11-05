#include "Pokemon.h"
#include <iostream>

/**
 * @brief Constructs a new pokemon object
 * 
 */
// -- Class constructors --
Pokemon :: Pokemon(){
    this->name = "unindentified";
    this->hp = 0;
    this->attack = 0;
    this->hp = 0;
    cout << "Default Constructor (Pokemon)" << endl;
}

/**
 * @brief Constructs a new pokemon object with parameters
 * 
 * @param name 
 * @param hp 
 * @param attack 
 * @param defense 
 * @param type 
 */
Pokemon :: Pokemon(string name, int hp, int attack, int defense, vector<string> type){
    this->name = name;
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
    this->type = type;
    cout << "Overloaded Constructor (Pokemon)" << endl;
}

// -- Mutators --
/**
 * @brief says whatever this pokemon normally says
 * 
 */
void Pokemon :: speak(){
    cout << "...\n";
}

void Pokemon :: printStats(){
    cout << "Name: " << this->name <<
            "\tHP: " << this ->hp <<
            "\tDEF: " << this->defense <<
            "\tATT: " << this->attack << endl;
    cout << "Type: ";
    for (int i = 0; i < this->type.size(); i++){
        cout << this->type[i] << "\t";
    }
    cout << endl;
}