// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Miner.cpp

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Person.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include <iostream>

using namespace std;

/*****************************************************************/
/* CONSTRUCTORS:                                                 */
/*****************************************************************/

// Miner()
//-----------------------------------------	
// default constructor

Miner::Miner()
	:Person('M') // display_code 'M'
{
	amount = 0;
	mine = NULL;
	home = NULL;
	cout << "    Miner default constructed." << endl;
}

// Miner()
//-----------------------------------------	
// initialize with id_num and location

Miner::Miner(int in_id, Cart_Point in_loc)
	:Person('M', in_id, in_loc)
{
	amount = 0;
	mine = 0;
	home = 0;
	cout << "    Miner constructed." << endl;
}

// Miner()
//-----------------------------------------	
// destructor

Miner::~Miner()
{
	cout << "    Miner destructed." << endl;
}

/*****************************************************************/
/* PUBLIC MEMBER FUNCTIONS:                                      */
/*****************************************************************/

// Miner.update()
//-----------------------------------------	
// update member variables depending on state

bool Miner::update()
{
	switch (state)
	{
		case 's': // stopped, do nothing
			break;
					
		case 'm': // moving to a destination
		
			// Miner has arrived at assigned location
			if (update_location())
			{
				state = 's'; // stop
				return true;
			}
			// Miner has not yet arrived
			break;
					
		case 'o': // outbound to mining
		
			// Miner has arrived at Gold_Mine
			if (update_location()) 
			{
				state = 'g'; // get gold
				return true;
			}
			// Miner has not yet arrived
			break;
					
		case 'g': // getting gold
		
			// dig gold at assigned Gold_Mine
			amount = mine->dig_gold();
			cout << display_code << get_id() << ": Got " << amount << " gold." << endl;

			// set destination to assigned Town_Hall
			setup_destination(home->get_location());

			state = 'i'; // inbound from mine
			return true;
			break;
					
		case 'i': // inbound from mining
		
			// Miner has arrived at Town_Hall
			if (update_location()) 
			{
				state = 'd'; // deposit gold
				return true;
			}
			
			// Miner has not yet arrived
			break;
					
		case 'd': // depositing gold
		
			// deposit gold in assigned Town_Hall
			cout << display_code << get_id() << ": Deposit " << amount << " of gold." << endl;
			home->deposit_gold(amount); 
			
			// assigned Gold_Mine is depleted
			if (mine->is_empty())	
			{
				state = 's';
				cout << display_code << get_id() << ": More work?" << endl;
				return true;
			}
			
			// assigned Gold_Mine is not yet depleted
			else	
			{
				// set destination to assigned Gold_Mine
				setup_destination(mine->get_location()); 
				state = 'o'; // outbound to mine
				cout << display_code << get_id() << ": Going back for more." << endl;
				return true;
			}
			break;
	}
	return false;
}

// Miner.start_mining()
//-----------------------------------------	
// setup destination Gold_Mine and Town_Hall
// and begin working Miner

void Miner::start_mining(Gold_Mine *in_mine, Town_Hall *in_home)
{
	// check for life
	if (is_alive())
	{
		// assign pointers
		mine = in_mine;
		home = in_home;

		// set destination to assigned Gold_Mine
		setup_destination(mine->get_location());
		state = 'o';
		cout << "Miner " << get_id() << " is mining at Gold_Mine " << (mine->get_id()) //...
			 << " and depositing at Town_Hall " << (home->get_id()) << "." << endl;

		cout << display_code << get_id() << ": Yes, my lord." << endl;
	}
	else
	{
		cout << display_code << get_id() << ": I am dead. The dead do not dig for gold." << endl;
	}
}

// Miner.show_status()
//-----------------------------------------	
// print the current status of the Miner

void Miner::show_status()
{
	cout << "Miner status: ";
	Person::show_status();
	cout << "    ";
	
	switch (state)
	{
		case 's': // stopped
			cout << "Stopped." << endl;
			break;
				
		case 'm': // moving to a destination
			cout << "Moving at speed." << endl;
			break;
				
		case 'o': // outbound mining
			cout << "Outbound to a mine." << endl;
			break;
				
		case 'g': // getting gold
			cout << "Getting gold from mine." << endl;
			break;
				
		case 'i': // inbound mining
			cout << "Inbound to home with load: " << amount << endl;
			break;
				
		case 'd': // depositing gold
			cout << "Depositing gold." << endl;
			break;
	}
}