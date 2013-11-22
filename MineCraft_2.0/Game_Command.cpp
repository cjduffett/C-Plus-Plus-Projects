// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// Game_Command.cpp

#include "Model.h"
#include "View.h"
#include "Game_Command.h"
#include "Cart_Point.h"
#include "Person.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include <iostream>
#include <sstream>
#include <string>

// limit of time steps per run
#define NUM_RUN_STEPS 5 // default is 5 time units

using namespace std;

/*****************************************************************/
/* MODEL COMMANDS:                    	                         */
/*****************************************************************/

// do_move_command()
//-----------------------------------------
// moves a person to location (x, y)

void do_move_command(Model &model, int person_id, double x_coord, double y_coord)
{
	Person *person_ptr = model.get_Person_ptr(person_id);

	if (person_ptr == 0)
		printErrorMsg();

	else
		person_ptr->start_moving(Cart_Point(x_coord,y_coord)); 
}

// do_work_command()
//-----------------------------------------
// starts specified Miner working at specified
// Gold_Mine and Town_Hall

void do_work_command(Model &model, int miner_id, int gold_id, int town_id)
{
	Person *miner_ptr = model.get_Person_ptr(miner_id);
	Gold_Mine *mine_ptr = model.get_Gold_Mine_ptr(gold_id);
	Town_Hall *town_ptr = model.get_Town_Hall_ptr(town_id);

	if (miner_ptr == 0 || mine_ptr == 0 || town_ptr == 0)
		// at least one id is invalid
		printErrorMsg();
	else
		// valid command
		miner_ptr->start_mining(mine_ptr, town_ptr); // start mining
}

// do_stop_command()
//-----------------------------------------
// stops a moving person

void do_stop_command(Model &model, int person_id)
{
	Person *person_ptr = model.get_Person_ptr(person_id);
	if (person_ptr == 0)
		// person does not exist
		printErrorMsg();
	else
		person_ptr->stop(); // stop valid person
}

void do_attack_command(Model &model, int attacker_id, int target_id)
{
	Person *attacker_ptr = model.get_Person_ptr(attacker_id);
	if (attacker_ptr == 0)
	{
		// attacker does not exist
		printErrorMsg();
	}
	else
	{
		Person *target_ptr = model.get_Person_ptr(target_id);

		if (target_ptr == 0)
		{
			// target does not exist
			printErrorMsg();
		}
		else
		{
			// initiate attack
			attacker_ptr->start_attack(target_ptr);
		}
	}
}

// do_go_command()
//-----------------------------------------
// advances time by one tick, updates objects

void do_go_command(Model &model, View &view)
{	
	// update objects
	model.update();
	
	// show status
	model.show_status();

	// display game grid
	model.display(view);
}

// do_run_command()
//-----------------------------------------
// advances time until next event or
// NUM_RUN_STEPS ticks, updates objects

void do_run_command(Model &model, View &view)
{
	// advance one time step
	cout << "Advancing to next event." << endl;
	
	// update objects
	bool event = model.update();

	// initialize runtime counter
	int runtime = 2;
	
	// advance additional (NUM_RUN_STEPS - 1) steps
	while(runtime <= NUM_RUN_STEPS && !event)
	{
		// advance one time step
		runtime++;
		event = model.update();
	}
	
	// show status
	model.show_status();

	// refresh view
	model.display(view);
}

// do_list_command()
//-----------------------------------------	
// lists the status of all objects

void do_list_command(Model &model)
{
	// list the status of all game object
	model.show_status();
}

// do_quit_command()
//-----------------------------------------
// quits the program, terminates the main loop

void do_quit_command(bool &progRunning)
{
	cout << "Terminating Program." << endl;
	progRunning = false;
}

// initialize()
//-----------------------------------------	
// prints the program header

void initialize()
{
	cout << "MineCraft 2.0" << endl;
	cout << "EC 327: Introduction to Software Engineering" << endl;
	cout << "Carlton Duffett" << endl;
	cout << "24 November, 2013"<< endl << endl;
}

/*****************************************************************/
/* MAIN PROGRAM FUNCTIONS:                                       */
/*****************************************************************/

// printErrorMsg()
//-----------------------------------------
// prints the default command error message

void printErrorMsg()
{
	cout << "ERROR: Please enter a valid command!" << endl;
}

// printCurrentTime()
//-----------------------------------------
// prints the current time unit

void printCurrentTime(int currentTime)
{
	cout << "Time: " << currentTime << endl;
}

/*****************************************************************/
/* COMMAND PARSER:                                               */
/*****************************************************************/

// parseCommand()
//-----------------------------------------
// parses and error checks user commands
// valid commands are:
//
// "move" ID1 to location (x,y): 
// >> m ID1 x y
//
// "work" ID1 at ID2 and deposit at ID3:
// >> w ID1 ID2 ID3
//
// "stop" ID1:
// >> s ID1
//
// "attack" ID1 attack ID2:
// >> a ID1 ID2
//
// "list" the status of all objects:
// >> l
//
// "go" advance one unit of time:
// >> g
//
// "run" advance 5 units of time:
// >> r
//
// "quit" the program:
// >> q

bool parseCommand(string command, char &cmd, int &par1, double &par2, double &par3)
{	
	// string must be at least 1 character to begin parsing
	if (command.length() > 0)
	{
		// get first character of string
		char first = command.at(0);
		
		// error check command
		switch (first)
		{
			case 'm':
				cmd = first;
				break;
					
			case 'w':
				cmd = first;
				break;
					
			case 's':
				cmd = first;
				break;

			case 'a':
				cmd = first;
				break;
					
			case 'g':
				cmd = first;
				break;
					
			case 'r':
				cmd = first;
				break;

			case 'l':
				cmd = first;
				break;
					
			case 'q':
				cmd = first;
				break;
					
			default:	// invalid command
				return false;
				break;
		}
		
		// evaluate single letter commands
		if (cmd == 'g' || cmd == 'r' || cmd == 'l' || cmd == 'q')
		{
			if (command.length() == 1) // valid single character command (g, r, l, q)
				return true;
			else
			{
				// invalid single character command
				return false;
			}
		}
		if (command.length() == 1) // m,w,s,a was passed with no parameters
			return false;
		else
		{
			// retrieve expected space in command
			char expectedSpace = command.at(1);
			if (expectedSpace != ' ')
			{
				// expected space not present
				return false;
			}
			else // expected space present
			{
				// evaluate remaining parameters:
				int parameter1;
				double parameter2;
				double parameter3;
				
				int nextspace;
			
				// first parameter (applicable to m,w,s,a):
				
					// valid format for "stop" command:
					if (command.length() == 3 && cmd == 's')
					{
						string stopMiner = command.substr(2);
						istringstream convertStop(stopMiner);
						
						if (! (convertStop >> parameter1) ) // attempt to convert parameter for "stop"
						{
							// conversion failed
							return false;
						}
						else
						{
							par1 = parameter1; // valid command for stop, end parsing
							return true;
						}
					}

					if (cmd == 's') // invalid format for stop beyond this point
						return false;

					// continue parsing for other first parameters:

					nextspace = command.find(' ');
					string par1str = command.substr(2,nextspace - 2);
					istringstream convert1(par1str); // convert string to number
					
					if (!(convert1 >> parameter1))
					{
						// conversion failed (parameter not a number)
						return false;
					}
					else
					{
						par1 = parameter1;
					}
				
				// second parameter (applicable only to m, w, a):
				
				if (!(command.find(' ', 4))) // if no space delimiting remaining parameters
				{
					// command is of invalid format
					return false;
				}
				else
				{
					// valid format for "attack":
					if (command.length() == 5 && cmd == 'a')
					{
						string attackstr = command.substr(4);
						istringstream convertAttack(attackstr);
						
						if (! (convertAttack >> parameter2) ) // attempt to convert parameter for "attack"
						{
							// conversion failed
							return false;
						}
						else
						{
							par2 = parameter2; // valid command for attack, end parsing
							return true;
						}
					}

					if (cmd == 'a') // invalid format for attack beyond this point
						return false;

					// continue parsing for other second parameters:

					nextspace = command.find(' ', 4);
					string par2str = command.substr(4,(nextspace - 4));
					istringstream convert2(par2str); // convert string to number
					
					if ( !(convert2 >> parameter2) )
					{
						// conversion failed (parameter not a number)
						return false;
					}
					else
					{
						par2 = parameter2; // assign parameter 2
					}
				}
				
				// third parameter (applicable only to m, w):
				
				string par3str = command.substr((nextspace + 1)); // remaining string
				
				if (par3str.length() == 0) // no parameters remaining
				{
					// command of invalid format
					return false;
				}
				else
				{
					istringstream convert3(par3str); // convert string to a number
					
					if( !(convert3 >> parameter3) )
					{
						// conversion failed (parameter not a number)
						return false;
					}
					else
					{
						par3 = parameter3; // assign parameter 3	
						return true; // parsing complete
					}
				}
			}
		}
	}
	else
	{
		// command cannot be parsed
		return false;
	}
	// catch, parsing should never reach this point
	return false;
}