#include<iostream>
#include<fstream>
/**
 * TO DO: 
 * Add <vector>, <cstdlib>, and <ctime>​
 */
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

/**
 * TO DO: 
 * Create function prototypes for all the functions.
 * Write their function declarations below mai()).
 * 
 * See promptFile(...) and printVec(...), which serve as examples.
 * 
 */


//------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string> & v); 
void printVec(vector<string>);
int ranGen(int size);
bool readFile(string filename, vector<string> & vec);
bool writeFile(const string & filename, const vector<string> & v0, const vector<string> & v1);

//------------------------RANDOMN SEED GENERATION-------------------------------------------
std::random_device rd; //Obtain a random seed from the hardware
std::mt19937 gen(rd()); //  Initialize the standard Mersenne Twister engine with the seed
    
int main()
{    
    vector<string> roster;
    vector<string> qBank;
    readFile("Lab2/2310_F26_Rosters.csv", roster);
    readFile("Lab2/Questions.csv", qBank);
    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;

    writeFile("Lab2/Student_question_bank.csv",roster, qBank);

}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

/**
 * @brief randomly returns a number from 0 to 5.
 * - It is hardcoded to be from 0 to 5.
 * - Uses srand(nullptr) in main()
 * TO DO:
 * Modify it so that randGen() reads in 
 * the size of the questions instead of 6 (e.g. questions.size())
 * 
 * TO DO:
 * Use <random> for modern C++ random generation instead 
 * 
 * @return int: index of question
 */
int ranGen(int size){
    std::uniform_int_distribution<> dis(0, size - 1); // [0, size-1] inclusive range
    return dis(gen); // Generate a random number in the specified range
}

/**
 * @brief reads contents of filename and populates into vec
 * 
 * @param filename :string 
 * @param vec: vector<string> &
 * 
 * TO DO: 
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 */
bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}
/**
 * @brief writes to filename with the first column from v0, second column from v1
 * 
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 * 
 * TO DO: 
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 * 
 * TO DO:
 * ​​Use pass by const reference (const vector<string> & v0, const vector<string> & v1)
 * as opposed to pass by value (vector<string> v0, vector<string> v1). 
 * 
 * What is the differennce between:
 * -  pass by reference (e.g. vector<string> & v0),
 * -  pass by value (e.g. vector<string> v0),
 * -  pass by const reference (e.g. const vector<string> & v0),
 * 
 * Answer:
 * - pass by reference: The function receives a reference to the original object,
 * this allows the function to modify the orignal object. Since it does not make a complete
 * new copy, it is much more efficient and takes less allocation.
 * - pass by value: The function receives a copy of the original object, 
 * so that means the function can't modify the original object, since the copy is local to the function.
 * This can be less efficient for large objects since it involves copying the entire object.
 * -  pass by const reference: he function receives a reference to the original object, however, 
 * since the reference is const, the function cannot modify the original object. This is efficient
 * while also safe if the function does not need to modify the object.
 * 
 */
bool writeFile(const string & filename, const vector<string> & v0, const vector<string> & v1){

    ofstream outputFile(filename);
     if (!outputFile) {
        cout << "Error: Could not create data.csv" << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();
    return true;
}