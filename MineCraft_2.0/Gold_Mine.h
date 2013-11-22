// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Gold_Mine.h

#ifndef GOLD_MINE_H
#define GOLD_MINE_H

#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Gold_Mine:public Game_Object
{
	public:
	
	// constructors:
	Gold_Mine();
	Gold_Mine(int, Cart_Point);
	~Gold_Mine();
	
	// public member functions:
	bool is_empty();
	double dig_gold(double amount_to_dig = 35);
	bool update();
	void show_status();
	
	private:
	
	// private member variables:
	double amount;
};

#endif