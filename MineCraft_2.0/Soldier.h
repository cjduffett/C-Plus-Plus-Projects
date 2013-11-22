// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Soldier.h

#ifndef SOLDIER_H
#define SOLDIER_H

#include "Cart_Point.h"
#include "Person.h"

using namespace std;

class Soldier:public Person
{
	public:

	// constructors:
	Soldier();
	Soldier(int, Cart_Point);
	~Soldier();

	// public member functions:
	void start_attack(Person *);
	bool update();
	void show_status();

	private:

	// private member variables:
	int attack_strength;
	double range;
	Person *target;
};

#endif