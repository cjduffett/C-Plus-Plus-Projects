// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Soldier.cpp

#include "Cart_Point.h"
#include "Person.h"
#include "Soldier.h"
#include <cmath>
#include <iostream>

using namespace std;

/*****************************************************************/
/* CONSTRUCTORS:                                                 */
/*****************************************************************/	

// Soldier()
//-----------------------------------------	
// default constructor, initialize only with display_code

Soldier::Soldier()
	:Person('S')
{
	attack_strength = 2;
	range = 2.0;
	target = NULL;
	cout << "   Soldier default constructed." << endl;
}

// Soldier()
//-----------------------------------------	
// initialize with display_code, id_num, and location

Soldier::Soldier(int in_id, Cart_Point in_loc)
	:Person('S', in_id, in_loc)
{
	attack_strength = 2;
	range = 2.0;
	target = 0;
	cout << "    Soldier constructed." << endl;
}

// ~Soldier()
//-----------------------------------------	
// destructor

Soldier::~Soldier()
{
	cout << "    Soldier destructed." << endl;
}

/*****************************************************************/
/* PUBLIC MEMBER FUNCTIONS:                                      */
/*****************************************************************/	

// Soldier.start_attack()
//-----------------------------------------	
// begin attacking specified target if
// within range (2 units)

void Soldier::start_attack(Person *in_target)
{
	// check for life
	if (is_alive())
	{	
		if (in_target->get_id() == this->get_id()) // soldier cannot attack itself
		{
			cout << display_code << get_id() << ": I cannot attack myself!" << endl;
			state = 's'; // stopped
		}
		else
		{
			// calculate distance to target
			double dist = cart_distance(in_target->get_location(), location);

			if (dist <= range)
			{
				target = in_target;
				cout << display_code << get_id() << ": Attacking." << endl;
				state = 'a'; // attack
			}
			else
				cout << "Target is out of range." << endl;
		}
	}
	else
	{
		cout << display_code << get_id() << ": I am dead. The dead cannot attack." << endl;
	}
}

// Soldier.update()
//-----------------------------------------	
// update member variables after each
// passing unit of time

bool Soldier::update()
{
	switch (state)
	{
		case 's': // stopped
			break;

		case 'm': // moving 

			// Soldier has arrived at assigned location
			if (update_location())
			{
				state = 's'; // stop
				return true;
			}
			break; // soldier has not yet arrived

		case 'a': // attacking
		{
			// check distance to target
			Cart_Point target_location = target->get_location();
			double dist_to_target = cart_distance(target_location, location);

			if (dist_to_target <= range)
			{
				if (target->is_alive())
				{
					cout << "Take that!" << endl;
					target->take_hit(attack_strength);
					return false;
				}
				else
				{
					cout << "I win!" << endl;
					state = 's';
					return true;
				}
			}
			break;
		}
		case 'x': // dead
			break;
	}
	return false;
}

// Soldier.show_status()
//-----------------------------------------	
// print current status of Soldier object

void Soldier::show_status()
{
	cout << "Soldier status: ";
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
				
		case 'a':
			cout << "Attacking." << endl;
			break;
	}
}