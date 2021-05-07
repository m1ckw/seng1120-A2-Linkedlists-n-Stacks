//Course: SENG1120
//Coded by: Alex Mendes 

//Utilised by Mick Wiedermann | c3315267 | Seng1120 Assignment2 | 2021-05-01.
//Intergrated this Class with my templated GameplayStack Class built on my LStack Class.

#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class GamePiece 
{
public:
	
	// Constructors
	GamePiece();
	GamePiece(const string); // the piece will be initialized either as "X" or "O"

	// Destructor
    ~GamePiece();

	// Setters
    void set_value(const string);

	// Getters
	string get_value() const;

//Private member variables
private:
	string value; // "X" or "O"
};
ostream& operator <<(ostream&, const GamePiece&);

bool operator == (const GamePiece& s1, const GamePiece& s2);

#endif