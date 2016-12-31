///////////////////////////////////////////////////////////////////////////////////////////////////////////
//FILE NAME:         player.h
//TITLE:             Player class header file
//PROGRAMMER:        Jacob Wise
//COURSE:            CS 2020
//DUE DATE:          4/13/2015
//
//ALL CODE IS MINE UNLESS OTHERWISE NOTED
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Player
{
	friend class Team;
	
	private:
		string id;
		int number;
		string fName;
		string lName;
		char position;
		int points;
		int rebounds;
		int blocks;
		int steals;
		bool starter;
		bool active;
		Player *next;
		
	public:
		Player();                  //default constructor
		Player(string, int, string, string, char, int, int, int, int, bool, Player *nextIN = NULL);  //overloaded constructor
		void print() const;      //print function
		
		//Getters
		string getId() const;
		int getNumber() const;
		string getFname() const;
		string getLname() const;
		char getPosition() const;
		int getPoints() const;
		int getRebounds() const;
		int getBlocks() const;
		int getSteals() const;
		bool getActive() const;
		bool getStarter() const;
		Player* getNext() const;
		
		//Setters
		void setId(string);
		void setNumber(int);
		void setFname(string);
		void setLname(string);
		void setPosition(int);
		void setPoints(int);
		void setRebounds(int);
		void setBlocks(int);
		void setSteals(int);
		void setActive(bool);
		void setStarter(bool);
};

#endif

