// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Game_Object.h

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Cart_Point.h"

using namespace std;

class Game_Object
{
	public:

	//constructors:
	Game_Object();
	Game_Object(char);
	Game_Object(char, int, Cart_Point);
	virtual ~Game_Object();

	// public member functions:
	Cart_Point get_location();
	int get_id();
	virtual void show_status();
	virtual bool update() = 0; // pure virtual function
	void drawself(char *);
	virtual bool is_alive();

	protected:

	// protected member variables:
	Cart_Point location;
	char display_code;
	char state;

	private:

	// private member variables:
	int id_num;
};

#endif