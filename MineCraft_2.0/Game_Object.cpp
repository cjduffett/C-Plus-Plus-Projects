// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Game_Object.cpp

#include "Cart_Point.h"
#include "Game_Object.h"
#include <iostream>
#include <cctype>

using namespace std;

/*****************************************************************/
/* CONSTRUCTORS:                                                 */
/*****************************************************************/


// Game_Object()
//-----------------------------------------	
// default constructor

Game_Object::Game_Object()
{
	display_code = ' ';
	state = 's';
	id_num = 0;
	cout << "    Game_Object default constructed." << endl;
}


// Game_Object()
//-----------------------------------------	
// initialize with only display_code

Game_Object::Game_Object(char in_code)
{
	display_code = in_code;
	state = 's';
	id_num = 0;
	cout << "    Game_Object constructed." << endl;
}

// Game_Object()
//-----------------------------------------	
// initialize with display_code, id_num, and location

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
	display_code = in_code;
	state = 's';
	id_num = in_id;
	location = in_loc;
	cout << "    Game_Object constructed." << endl;
}

// ~Game_Object()
//-----------------------------------------	
// destructor

Game_Object::~Game_Object()
{
	cout << "    Game_Object destructed." << endl;
}

/*****************************************************************/
/* PUBLIC MEMBER FUNCTIONS:                                      */
/*****************************************************************/

// Game_Object.get_location()
//-----------------------------------------	
// return the location of the object

Cart_Point Game_Object::get_location()
{
	return location;
}

// Game_Object.get_id()
//-----------------------------------------	
// return the id_num of the object

int Game_Object::get_id()
{
	return id_num;
}

// Game_Object.show_status()
//-----------------------------------------	
// print the status of the Game_Object

void Game_Object::show_status()
{
	cout << display_code << id_num
		 << " at location " << location << " ";
}

// Game_Object.drawself()
//-----------------------------------------	
// add object display_code and id_num
// to provided location in View char grid

void Game_Object::drawself(char *ptr)
{
	// Assign display code
	*ptr = display_code;

	// convert integer id_num to ASCII character equivalent
	char char_id = (char)(id_num + (int)'0');

	// Assign character id_num
	*(ptr + 1) = char_id;
}

// Game_Object.is_alive()
//-----------------------------------------	
// default, return true

bool Game_Object::is_alive()
{
	return true;
}