// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Gold_Mine.cpp

#include <iostream>
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Cart_Point.h"

using namespace std;
	
/*****************************************************************/
/* CONSTRUCTORS:                                                 */
/*****************************************************************/

// Gold_Mine()
//-----------------------------------------
// default constructor

Gold_Mine::Gold_Mine()
	:Game_Object('G')
{
	state = 'f'; // Gold_Mine is "full of gold"
	amount = 100;
	
	cout << "    Gold_Mine default constructed." << endl;
}

// Gold_Mine()
//-----------------------------------------
// initialize at specific location

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc)
	:Game_Object('G', inputId, inputLoc)
{
	state = 'f';
	amount = 100;
		
	cout << "    Gold_Mine constructed." << endl;
}

// ~Gold_Mine()
//-----------------------------------------	
// destructor

Gold_Mine::~Gold_Mine()
{
	cout << "    Gold_Mine destructed." << endl;
}

/*****************************************************************/
/* PUBLIC MEMBER FUNCTIONS:                                      */
/*****************************************************************/

// Gold_Mine.is_empty()
//-----------------------------------------	
// returns true if Gold_Mine is empty

bool Gold_Mine::is_empty()
{
	if (amount == 0) // Gold_Mine is not full
		return true;
	else
		return false;
} 

// Gold_Mine.dig_gold()
//-----------------------------------------	
// decrements amount in Gold_Mine by amount_to_dig

double Gold_Mine::dig_gold(double amount_to_dig) // amount_to_dig = 35.0
{
	if (amount >= amount_to_dig)
	{
		amount -= amount_to_dig;
		return amount_to_dig;
	}
	else
	{
		double amount_remaining = amount;
		amount = 0;
		return amount_remaining;
	}
}

// Gold_Mine.update()
//-----------------------------------------	
// updates the state of Gold_Mine

bool Gold_Mine::update()
{
	if (state == 'f' && is_empty())
	{
		state = 'e'; // Gold_Mine is "empty of gold
		display_code = 'g';
			
		cout << "Gold_Mine " << get_id() << " has been depleted." << endl;
		return true;
	}
	else
		return false;	
}

// Gold_Mine.show_status()
//-----------------------------------------	
// prints the status of Gold_Mine

void Gold_Mine::show_status()
{
	cout << "Gold_Mine status: ";
	Game_Object::show_status();
	cout << " Contains " << amount << "." << endl;
}