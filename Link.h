/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: Link.h 						     *
*									     *
*	This header file declares the Link class that compares the           *
*       Player class member data and is derived from the Player class.       * 
*       This class is also a link node that will be inserted  into           * 
*       the NodeList/LinkList class. It manages the pointer to the           *
*       next Link.                                                           *
*                                                                            *
*                                                                            *
*****************************************************************************/

#include "Player.h"

class Link : public Player

	{

		private:

			Link* next; //Pointer to the next link in the list

		public:

			//Default contructor 
			Link();

			//Destructor 
			~Link();

			//Copy constructor
			Link(const Link &source);

			//Attempt at operator overloading
			Link & operator=(const Link &source);

			//Sets the next pointer to point at the next link in the list, a pointer argument
			void setNext(Link* newNext);

			//Returns a pointer to the next link in the list, needed for iteration through the list
			Link* getNext();

			//Compares the three input arguments (array, char, array) to the Player member data and returns true if match, false otherwise
			bool nameCompare(char* fName, char midIni, char*  lName);

			//Compares input team array to Player member data, and returns true if match, false otherwise
			bool teamCompare(char* tName);

			//Compares input player number to Player member data, and returns true if match, false otherwise
			bool numberCompare(int pNum);

			//Returns a hash number for the node key, to properly insert the link into the binary search tree list
			unsigned int hashNumber();

	};
