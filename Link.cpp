/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: Link.cpp 						     *
*									     *
*	This C++ file implements the Link class that compares the            *
*       Player class member data and is derived from the Player class.       * 
*       This class is also a link node that will be inserted  into           * 
*       the NodeList/LinkList class. It manages the pointer to the           *
*       next Link.                                                           *
*                                                                            *
*                                                                            *
*****************************************************************************/

#include "Link.h"

//Default constructor, intializes next pointer to null
Link::Link(): next(0)

	{

	}

//Destructor, No DMA in this class
Link::~Link()

	{

	}

//Copy constructor, initializes next to null, and calls Player copy constructor
Link::Link(const Link &source): Player(source), next(0) 

	{

	}

//Attempt at operator overloading
Link & Link::operator=(const Link &source)

	{

		if(this == &source)

			{

				return *this;

			}

		Link* copyLink = new Link();

		copyLink->Player::operator=(source);

		copyLink->setNext(0);

		return *copyLink;

	}	

//Sets the next pointer to point at the next Link in the list
void Link::setNext(Link* newNext)

	{

		next = newNext;

	}

//Getter function for returning the next link in the list
Link* Link::getNext()

	{

		return next;

	}

//Compares the Player Member data to input data for the name, used in treeNameSearch() in Tree.cpp
bool Link::nameCompare(char* fname, char midIni, char* lName)

	{

		bool testBool = false;  //initialize bool variable to false

		testBool = ((strcmp(fname, getFirstName()) == 0) &&  //Test for match using strcmp()
			   (strcmp(lName, getLastName()) == 0) &&
		           (midIni == getMiddleInitial()));

		return testBool;  //return true/false after comparing input first, last, and middle initial.
	}

//Compares the Player member data (teamName) against the input data argument, used in numTeamSearch() in Tree.cpp
bool Link::teamCompare(char* tName)

	{

		return (strcmp(tName, getTeamName()) == 0);

	}

//Compares the Player member data (pNum) against the input data argument, used in numTeamSearch() in Tree.cpp
bool Link::numberCompare(int pNum)

	{

		return (pNum == getNumber());

	}

//Generates a hash number from the Player member data pNum, used to insert the link into the proper nodeList.   
unsigned int Link::hashNumber()

	{
		
		const int PRIME = 3571;  //A large constant prime number to hlep evenly distribute Links throughout the tree

		const int MAX_RANGE = 32; //Top range of output values

		const int OFF_BY_ONE = 1; //To make 0-31 into 1-32, no keys of 0

		unsigned int hash = getNumber();  //Calls getNumber() and assigns to hash

	 	hash = ((hash * PRIME) % MAX_RANGE) + OFF_BY_ONE;	 //Does the math to create a key to insert the Link objects into the proper NodeList 

		return hash;	

	}


