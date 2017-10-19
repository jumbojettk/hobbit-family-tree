// Napon Krassner
// CSC 2430, Homework 5
// 2/12/15
// Due: 2/19/15
// Name: Hobbit Family Tree
// Description: This is the implementation file for Hobbit Family Tree program.
//				It contains the Hobbit class function definitions of the Hobbit object
//				to be implemented by the client.

#include <iostream>
#include <string>
#include "hobbitTree.h"

using namespace std;

// Construct with parameters and defaults
Hobbit::Hobbit(string name, unsigned short age, Hobbit *antecedent, Hobbit *descendent)
{
    hobbitName = name;
    
    if (age < 0)  // Validate that age is >= 0
    {
        age = 0;
    }
    else
    {
        hobbitAge = age;
    }
    
	// Complete linkage
    hobbitAntecedent = antecedent;
	if (antecedent != NULL)  // If not null, set the parent's child to this hobbit
	{
		antecedent->setDescendent(this);
	}
    hobbitDescendent = descendent;
	if (descendent != NULL)  // If not null, set the child's parent to this hobbit
	{
		descendent->setAntecedent(this);
	}
}

// Destruct for garbage collection
Hobbit::~Hobbit()
{
	delete this;
}

// Mutate string name
void Hobbit::setName(string name)
{
    hobbitName = name;
}

// Mutate unsigned short age
void Hobbit::setAge(unsigned short age)
{
    if (age < 0)  // Validate that age is >= 0
    {
        hobbitAge = 0;
    }
    else
    {
        hobbitAge = age;
    }
}

// Mutate Hobbit object pointer antecedent
void Hobbit::setAntecedent(Hobbit *parent)
{
	// Complete linkage
    hobbitAntecedent = parent;
	parent->hobbitDescendent = this;
}

// Mutate hobbit object pointer descendent
void Hobbit::setDescendent(Hobbit *child)
{
	// Complete linkage
    hobbitDescendent = child;
	child->hobbitAntecedent = this;
}

// Access hobbit object name
string Hobbit::getName() const
{
    return hobbitName;
}

// Access hobbit object age
unsigned short Hobbit::getAge() const
{
    return hobbitAge;
}

// Access hobbit object antecedent (parent)
Hobbit* Hobbit::getAntecedent() const
{
		return hobbitAntecedent;
}

// Access hobbit object descendent (child)
Hobbit* Hobbit::getDescendent() const
{
	return hobbitDescendent;
}

// Util to find out if current hobbit is parent to hobbit passed
bool Hobbit::isParentOf(Hobbit *checkHobbit)
{
	if (this->getDescendent() == checkHobbit)
	{
		return true;
	}
	else
	{
		return false;
	}
}