// EC 327: Introduction to Software Engineering
// Programming Assignment 3
//
// Carlton Duffett
// November 11, 2013
//
// Model.h

#ifndef MODEL_H
#define MODEL_H

#include "Model.h"
#include "View.h"
#include "Game_Object.h"
#include "Person.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

class Model
{
	public:

	// constructors:
	Model();
	~Model();

	// public member functions:
	bool update();
	void display(View &);
	void show_status();

	// pointer functions:
	Person * get_Person_ptr(int);
	Gold_Mine * get_Gold_Mine_ptr(int);
	Town_Hall * get_Town_Hall_ptr(int);

	private:

	// copy constructor: (no copying permitted)
	Model(Model &);

	// private member variables:
	Game_Object * object_ptrs[10]; // limit 10 objects
	Person * person_ptrs[10];
	Gold_Mine * mine_ptrs[10];
	Town_Hall * hall_ptrs[10];
	int current_time;
	int num_objects;
	int num_persons;
	int num_mines;
	int num_halls;
};

#endif