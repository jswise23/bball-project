///////////////////////////////////////////////////////////////////////////////////////////////////////////
//FILE NAME:         final.cpp
//TITLE:             Final Project
//PROGRAMMER:        Jacob Wise
//COURSE:            CS 2020
//DUE DATE:          4/13/15
//
//ALL CODE IS MINE UNLESS OTHERWISE NOTED
//
//PURPOSE:           Use Linked list of Classes to run a program designed to manage basketball statistics during a game.
//
//FILES:			 team.h
//                   player.h
//   				 team.cpp
//                   player.cpp
//                   finalDataFile.txt*
//                       *contains Cleveland Cavaliers Roster.
//                   
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include "team.h"
using namespace std;

int fillList(Team&, Team&);
int chooseRoster();
int menu();
int editActionMenu();
void addPlayer(Team&);
void removePlayer(Team&);
void removePlayer(Team&);
int checkStarters(Team&);
int statChangeMenu();
void makeStatChange(Team&, int);
void makeSubstitution(Team&);
int saveLists(Team&, Team&);
void makeSummary(Team&, Team&);


int main()
{
	//Variables
	bool success;
	int menuChoice = -1;
	int teamChoice = -1;
	int editChoice = -1;
	int statChangeChoice = -1;
	int numStarters = 0;
	
	//create new Linked List
	Team home;
	Team away;
	
	while(menuChoice !=0)
	{
		menuChoice = menu();
	
		if(menuChoice == 1)
		{
			cout << "Loading teams..." << endl;
			success = fillList(home, away);
			if(!success)
			{
				cout << "Teams Loaded!" << endl;
				
				numStarters = home.countStarters();
				if(numStarters < 5)
				{
					cout << "Warning - There are less than 5 starters on the home team." << endl;
				}
				else if(numStarters > 5)
				{
					cout << "Warning - There are more than 5 starters on the home team." << endl;
				}
				
				numStarters = away.countStarters();
				if(numStarters < 5)
				{
					cout << "Warning - There are less than 5 starters on the away team." << endl;
				}
				else if(numStarters > 5)
				{
					cout << "Warning - There are more than 5 starters on the away team." << endl;
				}
				cout << endl;
			}
			else
				cout << "ERROR - PLEASE TRY AGAIN" << endl << endl;
				
			
		}
		else if(menuChoice == 2)
		{
			cout << "HOME TEAM CONTENTS:" << endl;
			home.displayTeam();
			cout << endl;
			cout << "AWAY TEAM CONTENTS:" << endl;
			away.displayTeam();
			cout << endl;
		}
		else if(menuChoice == 3)
		{
			while(teamChoice != 0)
			{
				teamChoice = chooseRoster();
				
				if(teamChoice!= 0)
				{	
					while(editChoice != 0)
					{
						editChoice = editActionMenu();
					
						if(editChoice == 1)
						{
							if(teamChoice == 1)
							{
								addPlayer(home);
							}
							else if(teamChoice == 2)
							{
								addPlayer(away);
							}
						}
						else if(editChoice == 2)
						{
							if(teamChoice == 1)
							{
								removePlayer(home);
							}
							else if(teamChoice == 2)
							{
								removePlayer(away);
							}
						}
						
						numStarters = home.countStarters();
						if(numStarters < 5)
						{
							cout << "Warning - There are less than 5 starters on the home team." << endl;
						}
						else if(numStarters > 5)
						{
							cout << "Warning - There are more than 5 starters on the home team." << endl;
						}
			
						numStarters = away.countStarters();
						if(numStarters < 5)
						{
							cout << "Warning - There are less than 5 starters on the away team." << endl << endl;
						}
						else if(numStarters > 5)
						{
							cout << "Warning - There are more than 5 starters on the away team." << endl << endl;
						}
					}
					//reset variable
					editChoice = -1;
				}
				
			}
			//reset variable
			teamChoice = -1;
			
		}
		else if(menuChoice == 4)
		{
			while(teamChoice != 0)
			{
				teamChoice = chooseRoster();
				
				if(teamChoice != 0)
				{
					while(statChangeChoice != 0)
					{
						statChangeChoice = statChangeMenu();
						
						if(statChangeChoice != 0)
						{
							if(teamChoice == 1)
							{
								makeStatChange(home, statChangeChoice);
							}
							else if(teamChoice == 2)
							{
								makeStatChange(away, statChangeChoice);
							}
						}
					}
					//reset
					statChangeChoice = -1;
				}
			}
			//reset choice
			teamChoice = -1;
		}
			
		else if(menuChoice == 5)
		{
			while(teamChoice!=0)
			{
				teamChoice = chooseRoster();
				
				if(teamChoice!=0)
				{
					if(teamChoice == 1)
					{
						makeSubstitution(home);
					}
					else if(teamChoice == 2)
					{
						makeSubstitution(away);
					}
				}
			}
			//reset
			teamChoice = -1;
		}
		else if(menuChoice == 6)
		{
			makeSummary(home, away);
		}
		else if(menuChoice == 7)
		{
			cout << "Saving Teams..." << endl;
			
			success = saveLists(home, away);
			if(success)
			{
				cout << "ERROR" << endl << endl;
			}
			else
			{
				cout << "Save Complete!" << endl << endl;
			}
		}
		else if(menuChoice ==0)
		{
			cout << "Program ending..." << endl;
		}
		else
		{
			cout << "ERROR - Please try again" << endl;
		}
	}
	
	//To demonstrate the overloaded = operator
	//team2 = team3 = team1;
	//team2.displayTeam();
	//cout << "stuff" << endl;
	//team3.displayTeam();
	//cout << "More Stuff" << endl;
	
	
	return 0;
}

int fillList(Team &tempTeam1, Team &tempTeam2)
{
	//temp variables
	string dfId;
	int dfNumber;
	string dfFname;
    string dfLname;
	char dfPosition;
	int dfPoints;
	int dfRebounds;
	int dfBlocks;
	int dfSteals;
	bool dfStarter;
	
	
	ifstream indata;
	
	/////////
	//Team 1
	/////////
	indata.open("cavsRoster.txt");
	
	if(!indata)
	{
		return 1;
	}
	
	//seed loop
	indata >> dfId;
	
	while(!indata.eof())
	{
		indata >> dfNumber;
		indata >> dfFname;
		indata >> dfLname;
		indata >> dfPosition;
		indata >> dfPoints;
		indata >> dfRebounds;
		indata >> dfBlocks;
		indata >> dfSteals;
		indata >> dfStarter;
		
		tempTeam1.appendPlayer(dfId, dfNumber, dfFname, dfLname, dfPosition, dfPoints, dfRebounds, dfBlocks, dfSteals, dfStarter);
			
		indata >> dfId;
	}
	
	indata.close();
	
	///////////
	//Team 2
	///////////
	indata.open("bullsRoster.txt");
	
	if(!indata)
	{
		return 1;
	}
	
	//seed loop
	indata >> dfId;
	
	while(!indata.eof())
	{
		indata >> dfNumber;
		indata >> dfFname;
		indata >> dfLname;
		indata >> dfPosition;
		indata >> dfPoints;
		indata >> dfRebounds;
		indata >> dfBlocks;
		indata >> dfSteals;
		indata >> dfStarter;
		
		tempTeam2.appendPlayer(dfId, dfNumber, dfFname, dfLname, dfPosition, dfPoints, dfRebounds, dfBlocks, dfSteals, dfStarter);
			
		indata >> dfId;
	}
	
	indata.close();
	
	return 0;
}

int menu()
{
	int choice = 0;
	bool valid = 0;
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "******       MAIN MENU       ******" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	
	while(!valid)
	{
		cout << "What would you like to do?" << endl;
		cout << "(1) Load Rosters" << endl;
		cout << "(2) Display Rosters" << endl;
		cout << "(3) Edit Player Rosters" << endl;
		cout << "(4) Make Statistical Changes" << endl;
		cout << "(5) Make Substitution" << endl;
		cout << "(6) Create and Display Summary" << endl;
		cout << "(7) Save Changes" << endl;
		cout << "(0) Exit" << endl;
		cout << "---What is your choice:  ";
		cin >> choice;
		
		if(choice < 0 || choice > 7)
		{
			cout << endl;
			cout << "**PLEASE ENTER A VALID CHOICE**" << endl;
			cout << endl;
			valid = 0;
		}
		else
		{
			cout << endl;
			valid = 1;
		}
	}
	
	return choice;
}


int chooseRoster()
{
	int choice = 0;
	int valid = 0;
	
	while(!valid)
	{
		cout << "==================================================" << endl;
		cout << "Which roster would you like to select?" << endl;
		cout << "(1) Home" << endl;
		cout << "(2) Away" << endl;
		cout << "(0) Go Back to Main Menu" << endl;
		cout << "---What is your choice:  ";
		cin >> choice;
		
		if(choice < 0 || choice > 2)
		{
			cout << endl;
			cout << "**PLEASE ENTER A VALID CHOICE**" << endl;
			cout << endl;
			valid = 0;
		}
		else
		{
			cout << endl;
			valid = 1;
		}
	}
	
	return choice;
}


int editActionMenu()
{
	int choice = 0;
	int valid = 0;
	
	while(!valid)
	{
		cout << "==============================================" << endl;
		cout << "Which action would you like to take?" << endl;
		cout << "(1) Add Player" << endl;
		cout << "(2) Remove Player" << endl;
		cout << "(0) Go Back to Choose Roster" << endl;
		cout << "---What is your choice:  ";
		cin >> choice;
		
		if(choice < 0 || choice > 2)
		{
			cout << endl;
			cout << "**PLEASE ENTER A VALID CHOICE**" << endl;
			cout << endl;
			valid = 0;
		}
		else
		{
			cout << endl;
			valid = 1;
		}
	}
	
	return choice;
}


void addPlayer(Team &roster)
{
	//temp variables
	string addId;
	int addNumber;
	string addFname;
    string addLname;
	char addPosition;
	bool addStarter;
	
	cout << "Please enter the info of the player you would like to add--" << endl;
	cout << "ID:  ";
	cin >> addId;
	cout << "Number:  ";
	cin >> addNumber;
	cout << "First Name:  ";
	cin >> addFname;
	cout << "Last Name:  ";
	cin >> addLname;
	cout << "Position(One letter):  ";
	cin >> addPosition;
	cout << "Starter(1 for yes, 0 for no):  ";
	cin >> addStarter;
	
	roster.appendPlayer(addId, addNumber, addFname, addLname, addPosition, 0, 0, 0, 0, addStarter);
	
	cout << endl;
	cout << "Player Added!" << endl;
}

void removePlayer(Team &roster)
{
	string choiceId;
	
	cout << "Which player would you like to delete--" << endl;
	roster.displayTeamSimple();
	cout <<  endl;
	cout << "Please enter ID:  ";
	cin.ignore();
	getline(cin, choiceId);
	
	roster.deletePlayer(choiceId);
	cout << endl;
}
	
void makeStatChange(Team &roster, int statChange)
{
	int choiceId;
	string passId;
	int numActivePlayers;
	string* activePlayersId;
	string* activePlayersFname;
	string* activePlayersLname;
	int valid = 0;
	
	numActivePlayers = roster.countActive();
	
	activePlayersId = new string [numActivePlayers];
	activePlayersFname = new string [numActivePlayers];
	activePlayersLname = new string [numActivePlayers];
	
	roster.loadActiveArray(activePlayersId, activePlayersFname, activePlayersLname);
	
	
	while(!valid)
	{
		cout << "==========================================" << endl;
		cout << "Which player made the play--" << endl;
		for(int i = 0; i < numActivePlayers; i++)
		{
		cout << "(" << i+1 << ") " << activePlayersId[i] << "  " << activePlayersFname[i] << "  " << activePlayersLname[i] << endl;
		}
		cout << "(0) Return to Choose Stat Change Menu" << endl;
		cout << "--Which choice:  ";
		cin >> choiceId;
	
		if(choiceId < 0 || choiceId > numActivePlayers)
		{
			cout << endl;
			cout << "**PLEASE ENTER A VALID CHOICE**" << endl;
			cout << endl;
			valid = 0;
		}
		else
		{
			cout << endl;
			valid = 1;
		}
	}
	
	if(choiceId != 0)
	{
		passId = activePlayersId[choiceId-1];
	
		if(statChange == 1)
		{
			roster.incrementPoints(passId);
			roster.incrementPoints(passId);
		}
		else if(statChange == 2)
		{
			roster.incrementPoints(passId);
			roster.incrementPoints(passId);
			roster.incrementPoints(passId);
		}
		else if(statChange == 3)
		{
			roster.incrementPoints(passId);
		}
		else if(statChange == 4)
		{
			roster.incrementRebounds(passId);
		}
		else if(statChange == 5)
		{
			roster.incrementBlocks(passId);
		}
		else if(statChange == 6)
		{
			roster.incrementSteals(passId);
		}
	}
}

int statChangeMenu()
{
	int choice = 0;
	int valid = 0;
	
	while(!valid)
	{
		cout << "====================================" << endl;
		cout << "Which play was made?" << endl;
		cout << "(1) Two point shot" << endl;
		cout << "(2) Three point shot" << endl;
		cout << "(3) Free throw" << endl;
		cout << "(4) Rebound" << endl;
		cout << "(5) Block" << endl;
		cout << "(6) Steal" << endl;
		cout << "(0) Go Back to Choose Roster" << endl;
		cout << "---What is your choice:  ";
		cin >> choice;
		
		if(choice < 0 || choice > 6)
		{
			cout << endl;
			cout << "**PLEASE ENTER A VALID CHOICE**" << endl;
			cout << endl;
			valid = 0;
		}
		else
		{
			cout << endl;
			valid = 1;
		}
	}
	
	return choice;
}

void makeSubstitution(Team &roster)
{
	int choiceId1;
	int choiceId2;
	int numActivePlayers;
	int numInactivePlayers;
	string* activePlayersId;
	string* activePlayersFname;
	string* activePlayersLname;
	string* inactivePlayersId;
	string* inactivePlayersFname;
	string* inactivePlayersLname;
	string passId1;
	string passId2;
	int valid1 = 0;
	int valid2 = 0;
	bool proceed = 0;

	numActivePlayers = roster.countActive();
	
	activePlayersId = new string [numActivePlayers];
	activePlayersFname = new string [numActivePlayers];
	activePlayersLname = new string [numActivePlayers];
	
	roster.loadActiveArray(activePlayersId, activePlayersFname, activePlayersLname);
	
	numInactivePlayers = roster.countInactive();
	
	inactivePlayersId = new string [numInactivePlayers];
	inactivePlayersFname = new string [numInactivePlayers];
	inactivePlayersLname = new string [numInactivePlayers];
	
	roster.loadInactiveArray(inactivePlayersId, inactivePlayersFname, inactivePlayersLname);
	
	while(!proceed)
	{
		while(!valid1)
		{
			cout << "==========================================" << endl;
			cout << "Which player do you want to sub out--" << endl;
			for(int i = 0; i < numActivePlayers; i++)
			{
			cout << "(" << i+1 << ") " << activePlayersId[i] << "  " << activePlayersFname[i] << "  " << activePlayersLname[i] << endl;
			}
			cout << "(0) Return to Choose Roster Menu" << endl;
			cout << "--Which choice:  ";
			cin >> choiceId1;
		
			if(choiceId1 < 0 || choiceId1 > numActivePlayers)
			{
				cout << endl;
				cout << "**PLEASE ENTER A VALID CHOICE**" << endl;
				cout << endl;
				valid1 = 0;
			}
			else
			{
				cout << endl;
				valid1 = 1;
			}
		}
		valid1 = 0;
		
		if(choiceId1 == 0)
		{
			return;
		}
		
		
		
		while(!valid2)
		{
			cout << "==========================================" << endl;
			cout << "Which player do you want to sub in--" << endl;
			for(int i = 0; i < numInactivePlayers; i++)
			{
			cout << "(" << i+1 << ") " << inactivePlayersId[i] << "  " << inactivePlayersFname[i] << "  " << inactivePlayersLname[i] << endl;
			}
			cout << "(0) Return to Choose Sub Out" << endl;
			cout << "--Which choice:  ";
			cin >> choiceId2;
		
			if(choiceId2 < 0 || choiceId2 > numInactivePlayers)
			{
				cout << endl;
				cout << "**PLEASE ENTER A VALID CHOICE**" << endl;
				cout << endl;
				valid2 = 0;
			}
			else
			{
				cout << endl;
				valid2 = 1;
			}
		}
		
		if(choiceId2 != 0)
		{			
			passId1 = activePlayersId[choiceId1 - 1];
			passId2 = inactivePlayersId[choiceId2 - 1];
			
			roster.makeInactive(passId1);			
			roster.makeActive(passId2);
			
			proceed = 1;
		}
	}
}

int saveLists(Team &home, Team &away)
{
	Player* nodePtr;
	
	//temp variables
	string tempId;
	int tempNumber;
	string tempFname;
    string tempLname;
	char tempPosition;
	int tempPoints;
	int tempRebounds;
	int tempBlocks;
	int tempSteals;
	bool tempStarter;
	Player* tempNext;
	
	ofstream outdata;
	
	nodePtr = home.getTeamHead();
	
	if(!nodePtr)
	{
		cout << "Empty Home Team" << endl;
	}
	else
	{
		outdata.open("cavsRoster2.txt");
		
		if(!outdata)
		{
			return 1;
		}
	
		while(nodePtr)
		{
			tempId = nodePtr->getId();
			tempNumber = nodePtr->getNumber();
			tempFname = nodePtr->getFname();
			tempLname = nodePtr->getLname();
			tempPosition = nodePtr->getPosition();
			tempPoints = nodePtr->getPoints();
			tempRebounds = nodePtr->getRebounds();
			tempBlocks = nodePtr->getBlocks();
			tempSteals = nodePtr->getSteals();
			tempStarter = nodePtr->getStarter();
			tempNext = nodePtr->getNext();
			
			outdata << tempId << endl;
			outdata << tempNumber << endl;
			outdata << tempFname << endl;
			outdata << tempLname << endl;
			outdata << tempPosition << endl;
			outdata << tempPoints << endl;
			outdata << tempRebounds << endl;
			outdata << tempBlocks << endl;
			outdata << tempSteals << endl;
			outdata << tempStarter << endl;
			
			nodePtr = tempNext;
		}
	
		outdata.close();
	}
	
	nodePtr = away.getTeamHead();
	
	if(!nodePtr)
	{
		cout << "Empty Away Team" << endl;
	}
	else
	{
		outdata.open("bullsRoster2.txt");
	
		if(!outdata)
		{
			return 1;
		}
	
		while(nodePtr)
		{
			tempId = nodePtr->getId();
			tempNumber = nodePtr->getNumber();
			tempFname = nodePtr->getFname();
			tempLname = nodePtr->getLname();
			tempPosition = nodePtr->getPosition();
			tempPoints = nodePtr->getPoints();
			tempRebounds = nodePtr->getRebounds();
			tempBlocks = nodePtr->getBlocks();
			tempSteals = nodePtr->getSteals();
			tempStarter = nodePtr->getStarter();			
			tempNext = nodePtr->getNext();
			
			outdata << tempId << endl;
			outdata << tempNumber << endl;
			outdata << tempFname << endl;
			outdata << tempLname << endl;
			outdata << tempPosition << endl;
			outdata << tempPoints << endl;
			outdata << tempRebounds << endl;
			outdata << tempBlocks << endl;
			outdata << tempSteals << endl;
			outdata << tempStarter << endl;
		
			nodePtr = tempNext;
		}
	
		outdata.close();
	}
	
	return 0;
}


void makeSummary(Team &home, Team &away)
{
	int sumPointsHome;
	int sumPointsAway;
	int sumReboundsHome;
	int sumReboundsAway;
	int sumBlocksHome;
	int sumBlocksAway;
	int sumStealsHome;
	int sumStealsAway;
	double avgPointsHome;
	double avgPointsAway;
	double avgReboundsHome;
	double avgReboundsAway;
	double avgBlocksHome;
	double avgBlocksAway;
	double avgStealsHome;
	double avgStealsAway;
	
	sumPointsHome = home.sumPoints();
	sumPointsAway = away.sumPoints();
	sumReboundsHome = home.sumRebounds();
	sumReboundsAway = away.sumRebounds();
	sumBlocksHome = home.sumBlocks();
	sumBlocksAway = away.sumBlocks();
	sumStealsHome = home.sumSteals();
	sumStealsAway = away.sumSteals();
	
	avgPointsHome = home.avgPoints();
	avgPointsAway = away.avgPoints();
	avgReboundsHome = home.avgRebounds();
	avgReboundsAway = away.avgRebounds();
	avgBlocksHome = home.avgBlocks();
	avgBlocksAway = away.avgBlocks();
	avgStealsHome = home.avgSteals();
	avgStealsAway = away.avgSteals();

	cout << "*****HOME*****" << endl;
	cout << left << setw(15) << "Statistic" << setw(8) << "Total" << setw(10) << "Average" << endl;
	cout << "-------------------------" << endl;
	cout << setw(15) << "Points:  " << setw(8) << sumPointsHome << setw(10) << fixed << showpoint << setprecision(2) << avgPointsHome << endl;
	cout << setw(15) << "Rebounds:  " << setw(8) << sumReboundsHome << setw(10) << fixed << showpoint << setprecision(2) << avgReboundsHome << endl;
	cout << setw(15) << "Blocks:  " << setw(8) << sumBlocksHome << setw(10) << fixed << showpoint << setprecision(2) << avgBlocksHome << endl;
	cout << setw(15) << "Steals:  " << setw(8) << sumStealsHome << setw(10) << fixed << showpoint << setprecision(2) << avgStealsHome << endl;
	
	cout << endl;
	
	cout << "*****AWAY*****" << endl;
	cout << left << setw(15) << "Statistic" << setw(8) << "Total" << setw(10) << "Average" << endl;
	cout << "---------------------------------" << endl;
	cout << setw(15) << "Points:  " << setw(8) << sumPointsAway << setw(10) << fixed << showpoint << setprecision(2) << avgPointsAway << endl;
	cout << setw(15) << "Rebounds:  " << setw(8) << sumReboundsAway << setw(10) << fixed << showpoint << setprecision(2) << avgReboundsAway << endl;
	cout << setw(15) << "Blocks:  " << setw(8) << sumBlocksAway << setw(10) << fixed << showpoint << setprecision(2) << avgBlocksAway << endl;
	cout << setw(15) << "Steals:  " << setw(8) << sumStealsAway << setw(10) << fixed << showpoint << setprecision(2) << avgStealsAway << endl;
	
	cout << endl;
}

