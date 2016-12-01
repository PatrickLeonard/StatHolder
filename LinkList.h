/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: LinkList.h  						     *
*									     *
*       This header file declares the LinkList class which creates a         *
*       Linear Linked List data structure. This linked list does not         * 
*       create its links from within. They are inserted from outside         * 
*       the NodeList/LinkList class. Links are inserted at the front         *
*       of the list and are kept in no particular order. The list has        *
*       two search functions, and an iterate display of all the links.       *
*       This class is the base class from which NodeList is derived.         *
*                                                                            *
*                                                                            *
*****************************************************************************/


#include "Link.h"

class LinkList

	{

		private:

			Link* first;    //Pointer to the first link in the list

			Link* current;  //POinter to the current link pointed to in member functions

		public:

			//Default constuctor  
			LinkList();

			//Destructor, iterates through the list deleting every Link 
			~LinkList();

			//Copy constructor
			LinkList(const LinkList &source);

			//Iterates through the list and displays the player profile of every link 
			void displayList();

			//Inserts a link into the list, only takes in links from outside the class
			void insertLink(Link* newLink);

			//Deletes a link from the list, uses a pointer to that link input from outside the class
			void deleteLink(Link* delLink);

			//Calls the nameCompare() from Link.cpp to find the correct link in the list O(n) search
			Link* nameSearch(char* fName, char midIni, char* lName);

			//Calls teamCompare() and numberCompare() to find the correct link in the list O(n) search
			Link* numTeamSearch(int pnum, char* tName);

	};

