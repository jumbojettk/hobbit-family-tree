// Napon Krassner
// CSC 2430, Homework 5
// 2/12/15
// Due: 2/19/15
// Name: Hobbit Family Tree
// Description: This is the client file for Hobbit Family Tree program.
//				It

#include <iostream>
#include <iomanip>
#include <string>
#include "hobbitTree.h"

using namespace std;

// Function prototypes
void printRelation(Hobbit*, Hobbit*);
void printFamilyStick(Hobbit*);

int main()
{
	// Create Hobbit objects
	Hobbit* Samwise = new Hobbit("Samwise Gamgee", 41);
	Hobbit* Gaffer = new Hobbit("Gaffer Gamgee", 95, NULL, Samwise);
	Hobbit* Elanor = new Hobbit("Elanor Gamgee", 0, Samwise);

	cout << "********Welcome to the Hobbit Family Tree by Napon Krassner (Jett)********" << endl << endl;

	// Print using utility functions on client
	printRelation(Samwise, Gaffer);
	printRelation(Samwise, Elanor);
	printRelation(Gaffer, Elanor);

	// Print family stick
	printFamilyStick(Gaffer);

	return 0;
}

// Parameters: two Hobbit objects to find out the relationship
// Returns: nothing
// Description: Prints the relationship between the two Hobbits passed in the parameter.
void printRelation(Hobbit *hobbitOne, Hobbit *hobbitTwo)
{
	string nameOne = hobbitOne->getName();
	string nameTwo = hobbitTwo->getName();

	cout << "======== Printing Relationship for " << nameOne << " and " << nameTwo << ": ========" << endl;
	if (hobbitOne->isParentOf(hobbitTwo))
	{
		cout << nameOne << " is a parent of " << nameTwo << endl << endl;
	}
	else if (hobbitTwo->isParentOf(hobbitOne))
	{
		cout << nameTwo << " is a parent of " << nameOne << endl << endl;
	}
	else
	{
		cout << nameTwo << " is not the parent of " << nameOne << " and vice versa" << endl << endl;
	}
}

// Parameters: Hobbit object
// Returns: nothing
// Description: Prints a family stick for the Hobbit in the parameter (current and children).
//				Print with formatting.
void printFamilyStick(Hobbit *currentHobbit)
{
	// Declare var to increment Hobbit object
	Hobbit *curHobbitNow = new Hobbit;

	curHobbitNow = currentHobbit;  // Init hobbit position
	cout << "======== Printing Family Stick for " << currentHobbit->getName() << ": ========" << endl;
	while (curHobbitNow->getDescendent() != NULL)  // Print from current loop only if child exists
	{
		cout << setw(40) << right << curHobbitNow->getName() << "(" << curHobbitNow->getAge() << ")" << endl;
		curHobbitNow = curHobbitNow->getDescendent();
		cout << setw(35) << right << "|" << endl;
	}
	cout << setw(40) << right << curHobbitNow->getName() << "(" << curHobbitNow->getAge() << ")" << endl;  // Print the last child
}