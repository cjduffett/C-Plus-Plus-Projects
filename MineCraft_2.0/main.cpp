// EC 327: Introduction to Software Engineering
// Programming Assignment 4
//
// Carlton Duffett
// November 24, 2013
//
// main.cpp

#include "View.h"
#include "Model.h"
#include "Game_Command.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*****************************************************************/
/* MAIN PROGRAM:                                                 */
/*****************************************************************/

int main()
{
	// initialization header
	initialize();

	// initialize model, view
	Model model;
	View view;

	// show initial game status
	model.show_status();
	model.display(view);

	bool progRunning = true;
	
	// MAIN PROGRAM LOOP:
	while (progRunning)
	{
		// get command from user
		string command;
		
		cout << "Enter Command: ";
		getline(cin,command);
		
		char cmd;
		int par1 = 0;
		double par2 = 0;
		double par3 = 0;
		
		// parse and error check command
		if (!parseCommand(command, cmd, par1, par2, par3)) // !valid command
		{
			// print error message
			printErrorMsg();
		}
		else
		{
			// valid command was entered
			switch (cmd)
			{
				case 'm': // "move", format: m ID x y
						
					do_move_command(model, par1, par2, par3);
					break;
							
				case 'w': // "work", format: w ID1 ID2 ID3
				{	
					int par2int;
					par2int = int(par2); // cast parameters as integers (IDs)
					int par3int;
					par3int = int(par3);
						
					do_work_command(model, par1, par2int, par3int);
					break;
				}			
				case 's': // "stop", format: s ID
							
					do_stop_command(model, par1);
					break;

				case 'a': // "attack", format a ID1 ID2
				{
					int par2int;
					par2int = int(par2); // cast par2 as integer (ID)

					do_attack_command(model, par1, par2);
					break;
				}
				case 'l': // "list" - show status of all game objects

					do_list_command(model);
					break;

				case 'g': // "go" - one time step
							
					do_go_command(model, view);
					break;
								
				case 'r': // "run" - NUM_RUN_STEPS (5) time steps
							
					do_run_command(model, view);
					break;
								
				case 'q': // "quit"
							
					do_quit_command(progRunning);
					break;
			}
		}		
	} // END MAIN PROGRAM LOOP	
	return 0;
}

