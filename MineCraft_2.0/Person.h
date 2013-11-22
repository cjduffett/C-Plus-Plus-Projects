// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Person.h

#ifndef PERSON_H
#define PERSON_H

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

using namespace std;

class Person:public Game_Object
{
	public:

	// constructors:
	Person();
	Person(char);
	Person(char, int, Cart_Point);
	virtual ~Person();

	// public member functions:
	void start_moving(Cart_Point);
	virtual void start_mining(Gold_Mine *, Town_Hall *);
	void stop();
	void show_status();
	bool is_alive();
	void take_hit(int);
	virtual void start_attack(Person *);

	protected:

	// protected member functions:
	bool update_location();
	void setup_destination(Cart_Point);

	private:

	// private member variables:
	int health;
	double speed;
	Cart_Point destination;
	Cart_Vector delta;
};

#endif