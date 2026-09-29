// Person.h
#ifndef RPG_H
#define RPG_H

#include <string>

using namespace std;

class RPG{

    public:
        // -- Class construction and destruction --
        RPG();
        RPG(string name, int hits_taken, float luck, float exp, int level);
        ~RPG();

        // -- Mutators --
        bool isAlive() const;
        void setHitsTaken(int new_hits);

        // -- Accessors --
        string getName() const;
        int getHitsTaken() const;
        float getLuck() const;
        float getExp() const;
        int getLevel() const;
    
    private:
        // -- Class instance variables --
        string name;
        int hits_taken;
        float luck;
        float exp;
        int level;
};


#endif // RPG_H