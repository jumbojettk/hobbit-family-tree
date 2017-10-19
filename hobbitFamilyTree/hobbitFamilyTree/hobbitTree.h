// Napon Krassner
// CSC 2430, Homework 5
// 2/12/15
// Due: 2/19/15
// Name: Hobbit Family Tree
// Description: This is the header file for Hobbit Family Tree program.
//				It contains the Hobbit class with the member variables and function prototypes.

#ifndef HOBBIT_TREE
#define HOBBIT_TREE

#include <iostream>
#include <string>

using namespace std;

class Hobbit
{
public:
    // **********CONSTRUCTORS**********
    
    // Parameters: string for name,
    //              unsigned short for age,
    //              Hobbit object pointer for antecedent,
    //              Hobbit object pointer for descendent
    // Returns: nothing
    // Description: Creates hobbit object with given parameters.
    //              If no parameters are given, it will construct to the default values.
    //              Age is always >= 0.
    Hobbit(string = "", unsigned short = 0, Hobbit* = NULL, Hobbit* = NULL);

	// **********Destructor**********
	~Hobbit();
    
    // **********MUTATORS**********
    
    // Parameters: string for name
    // Returns: nothing
    // Description: Sets the name of the hobbit class to the given parameter.
    void setName(string);
    
    // Parameters: unsigned short for age
    // Returns: nothing
    // Description: Sets the age of the hobbit class to the given parameter.
    void setAge(unsigned short);
    
    // Parameters: Hobbit object as pointer for antecedent
    // Returns: nothing
    // Description: Sets the antecedent of the hobbit class to the given parameter.
    void setAntecedent(Hobbit*);

    // Parameters: Hobbit object as a pointer for descendent
    // Returns: nothing
    // Description: Sets the descendent of the hobbit class to the given parameter.
    void setDescendent(Hobbit*);
    
    // **********ACCESSORS**********
    
    // Parameters: nothing
    // Returns: string for name
    // Description: Returns the name of the hobbit class.
    string getName() const;
    
    // Parameters: nothing
    // Returns: unsigned short for age
    // Description: Returns the age of the hobbit class.
    unsigned short getAge() const;
    
    // Parameters: nothing
    // Returns: Hobbit object as pointer for antecedent
    // Description: Returns the antecedent of the hobbit class.
    Hobbit* getAntecedent() const;
    
    // Parameters: nothing
    // Returns: Hobbit object as pointer for descendent
    // Description: Returns the descendent of the hobbit class.
    Hobbit* getDescendent() const;
    
    // **********UTIL FUNCTIONS*********
    
    // Parameters: Hobbit object
    // Returns: true or false
    // Description: Returns true if this(the current Hobbit) is parent of the Hobbit passed in,
    //              false otherwise.
    bool isParentOf(Hobbit*);

private:
    // Member vars
    string hobbitName;
    unsigned short hobbitAge;
    Hobbit *hobbitAntecedent;
    Hobbit *hobbitDescendent;
    
};

#endif