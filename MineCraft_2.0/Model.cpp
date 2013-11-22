// EC 327: Introduction to Software Engineering
// Programming Assignment 3
//
// Carlton Duffett
// November 11, 2013
//
// Model.cpp

#include "Model.h"
#include "Game_Command.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "View.h"
#include "Game_Object.h"
#include "Person.h"
#include "Miner.h"
#include "Soldier.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

using namespace std;

/*****************************************************************/
/* CONSTRUCTORS:                                                  */
/*****************************************************************/

// Model()
//-----------------------------------------	
// default constructor

Model::Model()
{
	// initialize game time
	current_time = 0;

	// initialize objects
	object_ptrs[0] = person_ptrs[0] = new Miner(1,Cart_Point(5,1));
	object_ptrs[1] = person_ptrs[1] = new Miner(2,Cart_Point(10,1));

	object_ptrs[2] = mine_ptrs[0] = new Gold_Mine(1,Cart_Point(1,20));
	object_ptrs[3] = mine_ptrs[1] = new Gold_Mine(2,Cart_Point(10,20));

	object_ptrs[4] = hall_ptrs[0] = new Town_Hall(1,Cart_Point(0,0));

	object_ptrs[5] = person_ptrs[2] = new Soldier(3,Cart_Point(5,15));
	object_ptrs[6] = person_ptrs[3] = new Soldier(4,Cart_Point(10,15));

	num_objects = 7;
	num_persons = 4;
	num_mines = 2;
	num_halls = 1;

	cout << "    Model default constructed." << endl;
}

// ~Model()
//-----------------------------------------	
// destructor

Model::~Model()
{
	// delete all objects
	for (int i = 0; i < num_objects; i++)
	{
		delete object_ptrs[i];
	}
	cout << "    Model destructed." << endl;
}

// Model(&)
//-----------------------------------------	
// copy constructor (NO COPYING PERMITTED)

Model::Model(Model &model){}

/*****************************************************************/
/* PUBLIC MEMBER FUNCTIONS:                                      */
/*****************************************************************/

// Model.update()
//-----------------------------------------	
// update all objects in the Model

bool Model::update()
{
	// increment game time
	current_time++;

	// update each object
	int events = 0;

	for (int i = 0; i < num_objects; i++)
	{
		Game_Object* ptr;
		ptr = object_ptrs[i];
		bool query_event;; 
		query_event = ptr->update(); // check for event

		if (query_event) // at least one event has occured
			events++;

	}
	if (events > 0)
		return true;
	else
		return false;
}

// Model.display()
//-----------------------------------------	
// populate the View with all objects
// and print View

void Model::display(View &view)
{
	// output the current game time:
	printCurrentTime(current_time);

	// clear grid
	view.clear();

	// plot objects to grid
	for (int i = 0; i < num_objects; i++)
	{
		if (object_ptrs[i]->is_alive()) // only plot "living" objects
			view.plot(object_ptrs[i]);
	}

	// print grid
	view.draw(); 
}

// Model.show_status()
//-----------------------------------------	
// print the status of all objects

void Model::show_status()
{
	// display object status
	for (int i = 0; i < num_objects; i++)
	{
		(object_ptrs[i])->show_status();
	}

}

// Model.get_Person_ptr()
//-----------------------------------------	
// return the Person pointer matching ID

Person * Model::get_Person_ptr(int id)
{
	if (id > 0 && id <= num_persons) // check if valid id
		return person_ptrs[id - 1];
	else
		return 0; // return 0 if not found
}

// Model.get_Gold_Mine_ptr()
//-----------------------------------------	
// return the Gold_Mine pointer matching ID

Gold_Mine * Model::get_Gold_Mine_ptr(int id)
{
	if (id > 0 && id <= num_mines) // check if valid id
		return mine_ptrs[id - 1];
	else
		return 0;
}

// Model.get_Town_Hall_ptr()
//-----------------------------------------	
// return the Town_Hall pointer matching ID

Town_Hall * Model::get_Town_Hall_ptr(int id)
{
	if (id > 0 && id <= num_halls) // check if valid id
		return hall_ptrs[id - 1];
	else
		return 0;
}