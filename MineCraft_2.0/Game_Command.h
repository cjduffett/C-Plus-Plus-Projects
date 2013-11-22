// EC 327: Introduction to Software Engineering
// Programming Assignment 3
//
// Carlton Duffett
// November 11, 2013
//
// Game_Command.h

#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "Model.h"
#include "View.h"

using namespace std;

// command functions:
void do_move_command(Model &, int, double, double);
void do_work_command(Model &, int, int, int);
void do_stop_command(Model &, int);
void do_attack_command(Model &, int, int);
void do_go_command(Model &, View &);
void do_run_command(Model &, View &);
void do_list_command(Model &);
void do_quit_command(bool &);

// main program functions:
void initialize();
void printErrorMsg();
void printCurrentTime(int);
bool parseCommand(string, char &, int &, double &, double &);

#endif