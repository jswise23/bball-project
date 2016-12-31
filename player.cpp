///////////////////////////////////////////////////////////////////////////////////////////////////////////
//FILE NAME:         player.cpp
//TITLE:             Player implementation file
//PROGRAMMER:        Jacob Wise
//COURSE:            CS 2020
//DUE DATE:          4/13/2015
//
//ALL CODE IS MINE UNLESS OTHERWISE NOTED
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "player.h"

/////////////////////////////
//Default Constructor
/////////////////////////////
Player::Player()
{
	id = "None";
	number = 000;
	fName = "None";
	lName = "None";
	position = 'N';
	points = 0;
	rebounds = 0;
	blocks = 0;
	steals = 0;
	starter = 0;
	active = 0;
	next = NULL;
}

/////////////////////////////
//Overloaded Constructor
/////////////////////////////
Player::Player(string tempId, int tempNumber, string tempFname, string tempLname, char tempPosition, int tempPoints, int tempRebounds, int tempBlocks, int tempSteals, bool tempStarter, Player* nextIN)
{	
	id = tempId;
	number = tempNumber;
	fName = tempFname;
	lName = tempLname;
	position = tempPosition;
	points = tempPoints;
	rebounds = tempRebounds;
	blocks = tempBlocks;
	steals = tempSteals;
	starter = tempStarter;
	active = tempStarter;
	next = nextIN;
}

////////////////////////////
//Print Function
////////////////////////////
void Player::print() const
{
	cout << left << setw(8) << id << setw(10) << number << setw(9) << fName << setw(13) << lName << setw(6) << position << setw(8) << points << setw(10) << rebounds << setw(8) << blocks << setw(8) << steals;
	if(active)
		cout << setw(8) << "Yes";
	else
		cout << setw(8) << "No";
	if(starter)
		cout << setw(10) << "Yes";
	else
		cout << setw(10) << "No";
}

//////////////////////////////
//Getters
//////////////////////////////
string Player::getId() const
{
	return id;
}

int Player::getNumber() const
{
	return number;
}

string Player::getFname() const
{
	return fName;
}

string Player::getLname() const
{
	return lName;
}

char Player::getPosition() const
{
	return position;
}

int Player::getPoints() const
{
	return points;
}

int Player::getRebounds() const
{
	return rebounds;
}

int Player::getBlocks() const
{
	return blocks;
}

int Player::getSteals() const
{
	return steals;
}

bool Player::getActive() const
{
	return active;
}

bool Player::getStarter() const
{
	return starter;
}

Player* Player::getNext() const
{
	return next;
}

////////////////////////////////
//Setters
////////////////////////////////
void Player::setId(string tempId)
{
	id = tempId;
}

void Player::setNumber(int tempNumber)
{
	number = tempNumber;
}

void Player::setFname(string tempFname)
{
	fName = tempFname;
}

void Player::setLname(string tempLname)
{
	lName = tempLname;
}

void Player::setPosition(int tempPosition)
{
	position = tempPosition;
}

void Player::setPoints(int tempPoints)
{
	points = tempPoints;
}

void Player::setRebounds(int tempRebounds)
{
	rebounds = tempRebounds;
}

void Player::setBlocks(int tempBlocks)
{
	blocks = tempBlocks;
}

void Player::setSteals(int tempSteals)
{
	steals = tempSteals;
}

void Player::setActive(bool tempActive)
{
	active = tempActive;
}

void Player::setStarter(bool tempStarter)
{
	starter = tempStarter;
}
