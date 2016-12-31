///////////////////////////////////////////////////////////////////////////////////////////////////////////
//FILE NAME:         team.h
//TITLE:             Team class header file
//PROGRAMMER:        Jacob Wise
//COURSE:            CS 2020
//DUE DATE:          4/13/2015
//
//ALL CODE IS MINE UNLESS OTHERWISE NOTED
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LISTNODE_H
#define LISTNODE_H

#include "player.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Team
{
	private:
		Player *head;
		
	public:
		Team();                  //default constructor
		~Team();				//destructor
		void displayTeam() const;      //display function
		void displayTeamSimple() const; //display only name and id
		void appendPlayer(string, int, string, string, char, int, int, int, int, bool);
		void insertPlayer(string, int, string, string, char, int, int, int, int, bool);
		void deletePlayer(string);
		const Team operator=(const Team&);
		int countStarters() const;
		int countActive() const;
		void loadActiveArray(string*, string*, string*);
		int countInactive() const;
		void loadInactiveArray(string*, string*, string*);
		void incrementPoints(string);
		void incrementRebounds(string);
		void incrementBlocks(string);
		void incrementSteals(string);
		void makeActive(string);
		void makeInactive(string);
		Player* getTeamHead();
		int countPlayers();
		
		int sumPoints();
		int sumRebounds();
		int sumBlocks();
		int sumSteals();
		double avgPoints();
		double avgRebounds();
		double avgBlocks();
		double avgSteals();
};

#endif
