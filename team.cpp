///////////////////////////////////////////////////////////////////////////////////////////////////////////
//FILE NAME:         team.cpp
//TITLE:             Team implementation file
//PROGRAMMER:        Jacob Wise
//COURSE:            CS 2020
//DUE DATE:          4/13/2015
//
//ALL CODE IS MINE UNLESS OTHERWISE NOTED
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "team.h"

/////////////////////////////
//Default Constructor
/////////////////////////////
Team::Team()
{
	head = NULL;
}

/////////////////////////////
//Desconstructor
/////////////////////////////
Team::~Team()
{
	Player *nodePtr, *nextPtr;
	
	nodePtr = head;
	while(nodePtr != NULL)
	{
		nextPtr = nodePtr->next;
		delete nodePtr;
		nodePtr = nextPtr;
	}
}

///////////////////////////////
//Append Player to end of list
///////////////////////////////
void Team::appendPlayer(string tempId, int tempNumber, string tempFname, string tempLname, char tempPosition, int tempPoints, int tempRebounds, int tempBlocks, int tempSteals, bool tempStarter)
{
	if(head == NULL)
	{
		head = new Player(tempId, tempNumber, tempFname, tempLname, tempPosition, tempPoints, tempRebounds, tempBlocks, tempSteals, tempStarter);
	}
	
	else
	{
		Player *nodePtr;
		
		nodePtr = head;
		
		while(nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		
		nodePtr->next = new Player(tempId, tempNumber, tempFname, tempLname, tempPosition, tempPoints, tempRebounds, tempBlocks, tempSteals, tempStarter);
	}
}

/////////////////////////////
//Display team
/////////////////////////////
void Team::displayTeam() const
{
	Player *nodePtr;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return;
	}
	
	cout << left << setw(8) << "ID" << setw(10) << "Number" << setw(22) << "Name" << setw(6) << "Pos." << setw(8) << "Points" << setw(10) << "Rebounds" << setw(8) << "Blocks" << setw(8) << "Steals" << setw(8) << "Active" << setw(9) << "Starter" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	nodePtr = head;
	while(nodePtr)
	{
		nodePtr->print();
		cout << endl;
		nodePtr = nodePtr->next;
	}
}

///////////////////////////////
//Display ID and Name only
///////////////////////////////
void Team::displayTeamSimple() const
{
	Player* nodePtr;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return;
	}
	
	cout << left << setw(6) << "ID" << "Name" << endl;
	cout << "-------------------------" << endl;
	
	nodePtr = head;
	while(nodePtr)
	{
		cout << setw(6) << nodePtr->id << nodePtr->fName << " " << nodePtr->lName << endl;
		nodePtr = nodePtr->next;
	}
}

///////////////////////////////
//Insert player based on number
///////////////////////////////
void Team::insertPlayer(string tempId, int tempNumber, string tempFname, string tempLname, char tempPosition, int tempPoints, int tempRebounds, int tempBlocks, int tempSteals, bool tempStarter)
{
	Player *nodePtr, *previous;
	
	if(head == NULL || head->number <= tempNumber)
	{
		head = new Player(tempId, tempNumber, tempFname, tempLname, tempPosition, tempPoints, tempRebounds, tempBlocks, tempSteals,tempStarter, head);
	}
	else
	{
		previous = head;
		nodePtr = head->next;
		
		while(nodePtr != NULL && nodePtr->number > tempNumber)
		{
			previous = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		previous->next = new Player(tempId, tempNumber, tempFname, tempLname, tempPosition, tempPoints, tempRebounds, tempBlocks, tempSteals, tempStarter, nodePtr);
	}
}

////////////////////////////////////
//Delete Player
////////////////////////////////////
void Team::deletePlayer(string checkId)
{
	Player *nodePtr, *previousPtr;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return;
	}
	
	if(head->id == checkId)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
		cout << "Player Deleted!" << endl;
	}
	else
	{
		nodePtr = head;
		
		while(nodePtr != NULL && nodePtr->id != checkId)
		{
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if(nodePtr)
		{
			previousPtr->next = nodePtr->next;
			delete nodePtr;
			cout << "Player Deleted!" << endl;
		}
		else
		{
			cout << "Player not found -- Please try again" << endl;
		}
	}
}

///////////////////////////////
//Overloaded = Operator
///////////////////////////////
const Team Team::operator= (const Team &right)
{
	Player *nodePtr, *nextPtr;
	
	nodePtr = head;
	while(nodePtr != NULL)
	{
		nextPtr = nodePtr->next;
		delete nodePtr;
		nodePtr = nextPtr;
	}
	
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
	
	nodePtr = right.head;
	
	tempId = nodePtr->id;
	tempNumber = nodePtr->number;
	tempFname = nodePtr->fName;
	tempLname = nodePtr->lName;
	tempPosition = nodePtr->position;
	tempPoints = nodePtr->points;
	tempRebounds = nodePtr->rebounds;
	tempBlocks = nodePtr->blocks;
	tempSteals = nodePtr->steals;
	tempStarter = nodePtr->starter;
	
	head = new Player(tempId, tempNumber, tempFname, tempLname, tempPosition, tempPoints, tempRebounds, tempBlocks, tempSteals, tempStarter);
	
	while(nodePtr->next != NULL)
	{
		nodePtr = nodePtr->next;
		
		tempId = nodePtr->id;
		tempNumber = nodePtr->number;
		tempFname = nodePtr->fName;
		tempLname = nodePtr->lName;
		tempPosition = nodePtr->position;
		tempPoints = nodePtr->points;
		tempRebounds = nodePtr->rebounds;
		tempBlocks = nodePtr->blocks;
		tempSteals = nodePtr->steals;
		tempStarter = nodePtr->starter;
		
		appendPlayer(tempId, tempNumber, tempFname, tempLname, tempPosition, tempPoints, tempRebounds, tempBlocks, tempSteals, tempStarter);
	}
	
	return *this;
}

////////////////////
//Count Starters
////////////////////
int Team::countStarters() const
{
	Player* nodePtr;
	int starters = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	while(nodePtr)
	{
		if(nodePtr->starter)
		{
			starters++;
		}
		nodePtr = nodePtr->next;
	}

	return starters;
}

////////////////////////
//Count Active Players
////////////////////////
int Team::countActive() const
{
	Player* nodePtr;
	int activePlayers = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	while(nodePtr)
	{
		if(nodePtr->active)
		{
			activePlayers++;
		}
		nodePtr = nodePtr->next;
	}

	return activePlayers;
}

//////////////////////////////
//Load Active Array
//////////////////////////////
void Team::loadActiveArray(string* activeId, string* activeFname, string* activeLname)
{
	Player* nodePtr;
	string* activeIdPtr;
	string* activeFnamePtr;
	string* activeLnamePtr;
	
	activeIdPtr = activeId;
	activeFnamePtr = activeFname;
	activeLnamePtr = activeLname;
	nodePtr = head;
	
	while(nodePtr)
	{
		if(nodePtr->active)
		{
			*activeIdPtr = nodePtr->id;
			*activeFnamePtr = nodePtr->fName;
			*activeLnamePtr = nodePtr->lName;
			activeIdPtr++;
			activeFnamePtr++;
			activeLnamePtr++;
		}
		nodePtr = nodePtr->next;
	}
}

/////////////////////////////////
//Increment Points
/////////////////////////////////
void Team::incrementPoints(string testId)
{
	Player* nodePtr;
	
	nodePtr = head;
	while(nodePtr)
	{
		if(nodePtr->id == testId)
		{
			nodePtr->points++;
		}
		
		nodePtr = nodePtr->next;
	}
}

/////////////////////////////////
//Increment Rebounds
/////////////////////////////////
void Team::incrementRebounds(string testId)
{
	Player* nodePtr;
	
	nodePtr = head;
	while(nodePtr)
	{
		if(nodePtr->id == testId)
		{
			nodePtr->rebounds++;
		}
		
		nodePtr = nodePtr->next;
	}
}

/////////////////////////////////
//Increment Blocks
/////////////////////////////////
void Team::incrementBlocks(string testId)
{
	Player* nodePtr;
	
	nodePtr = head;
	while(nodePtr)
	{
		if(nodePtr->id == testId)
		{
			nodePtr->blocks++;
		}
		
		nodePtr = nodePtr->next;
	}
}

/////////////////////////////////
//Increment Steals
/////////////////////////////////
void Team::incrementSteals(string testId)
{
	Player* nodePtr;
	
	nodePtr = head;
	while(nodePtr)
	{
		if(nodePtr->id == testId)
		{
			nodePtr->steals++;
		}
		
		nodePtr = nodePtr->next;
	}
}

//////////////////////////////
//Count Inactive Players
//////////////////////////////
int Team::countInactive() const
{
	Player* nodePtr;
	int inactivePlayers = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	while(nodePtr)
	{
		if(!nodePtr->active)
		{
			inactivePlayers++;
		}
		nodePtr = nodePtr->next;
	}

	return inactivePlayers;
}

//////////////////////////////
//Load Inactive Array
//////////////////////////////
void Team::loadInactiveArray(string* inactiveId, string* inactiveFname, string* inactiveLname)
{
	Player* nodePtr;
	string* inactiveIdPtr;
	string* inactiveFnamePtr;
	string* inactiveLnamePtr;
	
	inactiveIdPtr = inactiveId;
	inactiveFnamePtr = inactiveFname;
	inactiveLnamePtr = inactiveLname;
	nodePtr = head;
	
	while(nodePtr)
	{
		if(!nodePtr->active)
		{
			*inactiveIdPtr = nodePtr->id;
			*inactiveFnamePtr = nodePtr->fName;
			*inactiveLnamePtr = nodePtr->lName;
			inactiveIdPtr++;
			inactiveFnamePtr++;
			inactiveLnamePtr++;
		}
		nodePtr = nodePtr->next;
	}
}

///////////////////////////////
//Make Active
///////////////////////////////
void Team::makeActive(string searchId)
{
	Player* nodePtr;
	
	nodePtr = head;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return;
	}
	
	while(nodePtr)
	{
		if(nodePtr->id == searchId)
		{
			nodePtr->active = 1;
		}
		
		nodePtr = nodePtr->next;
	}
}


/////////////////////////////
//Make Inactive
/////////////////////////////
void Team::makeInactive(string searchId)
{
	Player* nodePtr;
	
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return;
	}
	
	nodePtr = head;
	
	while(nodePtr)
	{
		if(nodePtr->id == searchId)
		{
			nodePtr->active = 0;
		}
		
		nodePtr = nodePtr->next;
	}
}


//////////////////////////////
//Get Head
//////////////////////////////
Player* Team::getTeamHead()
{
	if(!head)
	{
		cout << "Empty List" << endl;
	}
	return head;
}


//////////////////////////////
//Sum Points
//////////////////////////////
int Team::sumPoints()
{
	Player* nodePtr;
	int sum = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	
	while(nodePtr)
	{
		sum = sum + nodePtr->points;
		
		nodePtr = nodePtr->next;
	}
	
	return sum;
}
		

//////////////////////////////
//Sum Rebounds
//////////////////////////////
int Team::sumRebounds()
{
	Player* nodePtr;
	int sum = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	
	while(nodePtr)
	{
		sum = sum + nodePtr->rebounds;
		
		nodePtr = nodePtr->next;
	}
	
	return sum;
}

//////////////////////////////
//Sum Blocks
//////////////////////////////
int Team::sumBlocks()
{
	Player* nodePtr;
	int sum = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	
	while(nodePtr)
	{
		sum = sum + nodePtr->blocks;
		
		nodePtr = nodePtr->next;
	}
	
	return sum;
}


//////////////////////////////
//Sum Steals
//////////////////////////////
int Team::sumSteals()
{
	Player* nodePtr;
	int sum = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	
	while(nodePtr)
	{
		sum = sum + nodePtr->steals;
		
		nodePtr = nodePtr->next;
	}
	
	return sum;
}


////////////////////////////////
//Average Points
////////////////////////////////
double Team::avgPoints()
{
	double sum;
	double numNodes;
	double avg;
	
	sum = sumPoints();
	numNodes = countPlayers();
	avg = sum / numNodes;
	
	return avg;
}


////////////////////////////////
//Average Rebounds
////////////////////////////////
double Team::avgRebounds()
{
	double sum;
	double numNodes;
	double avg;
	
	sum = sumRebounds();
	numNodes = countPlayers();
	avg = sum / numNodes;
	
	return avg;
}


////////////////////////////////
//Average Blocks
////////////////////////////////
double Team::avgBlocks()
{
	double sum;
	double numNodes;
	double avg;
	
	sum = sumBlocks();
	numNodes = countPlayers();
	avg = sum / numNodes;
	
	return avg;
}


////////////////////////////////
//Average Steals
////////////////////////////////
double Team::avgSteals()
{
	double sum;
	double numNodes;
	double avg;
	
	sum = sumSteals();
	numNodes = countPlayers();
	avg = sum / numNodes;
	
	return avg;
}


/////////////////////////////////
//Count Number of Players in List
/////////////////////////////////
int Team::countPlayers()
{
	Player* nodePtr;
	int numPlayers = 0;
	
	if(!head)
	{
		cout << "Empty List" << endl;
		return 0;
	}
	
	nodePtr = head;
	
	while(nodePtr)
	{
		numPlayers++;
		
		nodePtr = nodePtr->next;
	}
	
	return numPlayers;
}
	

