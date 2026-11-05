#include "Charmander.h"
#include <iostream>

/**
 * @brief Constructs a new Charmander object
 * 
 */
// -- Class constructors --
Charmander :: Charmander() : Pokemon(){
    this->type.push_back("Fire");
    this->skills.push_back("Growl");
    this->skills.push_back("Scratch");  

    cout << "Default constructor (Charmander)" << endl;
}

/**
 * @brief Constructs a new pokemon object with parameters
 * 
 * @param name 
 * @param hp 
 * @param attack 
 * @param defense 
 * @param type 
 * @param skills
 */
Charmander :: Charmander(string name, int hp, int attack, int defense, 
                         vector<string> type,
                         vector<string> skills) :
            Pokemon(name, hp, attack, defense, type) {
    this->skills = skills;
    cout << "Overloaded Constructor (Charmander)" << endl;
}

// -- Mutators --
/**
 * @brief says whatever this charmander says
 * 
 */
void Pokemon :: speak(){
    cout << "Charmander-char\n";
}

/**
 * @brief Calls printStats from the parent class and append skills
 * 
 */
void Charmander :: printStats(){
    Pokemon :: printStats();
    cout << "Skills: ";
    for (int i = 0; i < this->skills.size(); i++){
        cout << this->skills[i] << "\t";
    }
    cout << endl;
}