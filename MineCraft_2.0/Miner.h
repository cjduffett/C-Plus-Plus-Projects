// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Miner.h

#ifndef MINER_H
#define MINER_H

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Person.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include <iostream>

using namespace std;

class Miner:public Person
{
	public:

	// constructors:
	Miner();
	Miner(int, Cart_Point);
	~Miner();

	// public member variables:
	bool update();
	void start_mining(Gold_Mine *, Town_Hall *);
	void show_status();

	private:

	// private member variables:
	double amount;
	Gold_Mine *mine;
	Town_Hall *home;
};

#endif