//Course: SENG1120
//Coded by: Alex Mendes 

//Utilised by Mick Wiedermann | c3315267 | Seng1120 Assignment2 | 2021-05-01.
//Intergrated this Class with my templated GameplayStack Class built on my LStack Class.

#include "GamePiece.h"
#include <cstdlib>

// Constructors
GamePiece::GamePiece()
{
	value = "";
}

GamePiece::GamePiece(string value_)
{
	value = value_;
}

// empty destructor
GamePiece::~GamePiece(){}

// Mutator methods (setters)
void GamePiece::set_value(const string value_) {value = value_;}

// Accessor methods (getters)
string GamePiece::get_value() const {return value;}

// overloaded ostream operator
ostream& operator <<(ostream& out, const GamePiece& p)
{
	out << p.get_value();
    return out;
}

// overloaded == operator
bool operator == (const GamePiece& p1, const GamePiece& p2)
{
    if (p1.get_value() == p2.get_value())
		return true;
	else
		return false;
}
