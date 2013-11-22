// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Town_Hall.cpp

#include <iostream>
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Cart_Point.h"

using namespace std;

/*****************************************************************/
/* CONSTRUCTORS:                                                 */
/*****************************************************************/	
	
// Town_Hall()
//-----------------------------------------
// default constructor

Town_Hall::Town_Hall()
	:Game_Object('t')
{
	state = 'o';
	amount = 0;
		
	cout << "    Town_Hall default constructed." << endl;
}

// Town_Hall()
//-----------------------------------------
// initialize at specific location

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc)
	:Game_Object('t', inputId, inputLoc)
{
	state = 'o';
	amount = 0;
		
	cout << "    Town_Hall constructed." << endl;
}

// ~Town_Hall()
//-----------------------------------------	
// destructor

Town_Hall::~Town_Hall()
{
	cout << "    Town_Hall destructed." << endl;
}
	
/*****************************************************************/
/* PUBLIC MEMBER FUNCTIONS:                                      */
/*****************************************************************/	

// Town_Hall.deposit_gold()
//-----------------------------------------	
// increment amount by deposit_amount

void Town_Hall::deposit_gold(double deposit_amount)
{
	amount += deposit_amount;
}

// Town_Hall.update()
//-----------------------------------------	
// updates the status of Town_Hall

bool Town_Hall::update()
{
	// Town_Hall is ready to upgrade
	if (state == 'o' && amount >= 50)
	{
		state = 'u'; // "upgraded level"
		display_code = 'T';
			
		// cout << " Upgraded.\n" << endl;
		return true;
	}
	
	// Town_Hall not ready to upgrade
	else
		return false;
}

// Town_Hall.show_status()
//-----------------------------------------	
// print status of Town_Hall

void Town_Hall::show_status()
{
	cout << "Town_Hall status: ";
	Game_Object::show_status();

	cout << " Contains " << amount << " of gold.";

	if (state == 'o')
		cout << " Not yet upgraded." << endl;
	else
		cout << " Upgraded." << endl;
}

