/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: LinkList.cpp 						     *
*									     *
*       This C++ file implements the LinkList class which creates a          *
*       Linear Linked List data structure. This linked list does not         * 
*       create its links from within. They are inserted from outside         * 
*       the NodeList/LinkList class. Links are inserted at the front         *
*       of the list and are kept in no particular order. The list has        *
*       two search functions, and an iterate display of all the links.       *
*                                                                            *
*****************************************************************************/


#include "LinkList.h"

//Default contructor, initializes first and current pointers to null
LinkList::LinkList(): first(0), current(0)

	{

	}

//Destructor, if the list has links in it, it iterates through the list deleting all links 
LinkList::~LinkList() 

	{

		Link* temp = 0;     //Create a temp pointer to hold a link for deletion

		current = first;    //Set the current link to the first (start at beginning)

		if(current = 0)     //If current is null, then there are no links to delete

			{

				return;

			}

		else
			{
				
				while(current != 0)  //While the current pointer isn't pointing at null

					{

						temp = current;    //Point temp at the current link

						current = current->getNext();   //Move the current pointer to the next link

						delete temp;      //Delete the link pointed at by temp, the one behind the new current

					}

				temp = 0;  //After all links have been deleted, and current is null, set temp to null and end destructor

				return;

			}

	}

//Copy Constructor, copies a link list with a deep copy of member data (including bass class data)
//Initialize the LinkList first to null, then add deeply copied links to the link list being copied over 
LinkList::LinkList(const LinkList &source): first(0)

	{

		Link* copyLink = 0;    //Initialize a new pointer to a link being copied and set to null	

		Link* tempCurrent = source.first;  //Initialize and assign a pointer to the first link in list being copied

		while(tempCurrent != 0)   //While the current pointer doesn't point to null

			{

				copyLink = new Link(*tempCurrent);  //create a new link with deep copy of member data

				this->insertLink(copyLink);         //Insert new link into Link List   		

				tempCurrent  = tempCurrent->getNext(); //Step current to the next link in the List being copied

			}

	}

//Iterates through the list and displays the Player profile for every link
void LinkList::displayList()

	{

		current = first;  //Start at the beginning of the list

		if(current == 0)  //If current is null, the list is empty

			{

				std::cout << "The list is empty.\n";

				return;

			}

		else

			{

				while(current != 0)  //While current points at a link

					{

						current->displayPlayerProfile();  //Display the profile

						current = current->getNext();  //Move to next link

					}

				return;

			}

	}

//Insert a link from outside the class into the front of the list
void LinkList::insertLink(Link* newLink)

	{

		if(first == 0)  //if list is empty point first at input link

			{

				first = newLink;

			}

		else           //If not empty, point input link at the first, then first at the input link

			{

				newLink->setNext(first);

				first = newLink;

			}

	}

//Takes input link from the outside, finds the link and deletes it from list structure
void LinkList::deleteLink(Link* delLink)

	{

		Link* temp = 0;  //Create a temp pointer to maintain link list

		current = first;  //Start from beginning

		if((delLink == current) && (current->getNext() != 0)) //If the link being deleted if the first 

			{

				first = current->getNext(); //Point first at the next link

				delete current;  //Delete the link

				current = 0;    //Set current to null
		
			}

		else if((delLink == current) && (current->getNext() == 0)) //If there is only one link in the list 

			{

				first = 0;

				delete current;

				current = 0;	

			}

		else

			{

				while(current != 0) //While current points at a link

					{

						if(current->getNext() == delLink)  //Check to see if the next link is the link being deleted

							{
							
								temp = current->getNext();  //Assign temp to next link

								current->setNext(delLink->getNext());  //Set the current links next to the link after the deleted link
												       //This fills the gap being made by deleting the link

								delete temp;  //Delete the link after cutting it out of the list

								current = 0;  //Set current to null

							}

						else

							{

								current = current->getNext();  //If the next link isn't being deleted go to th

							}

					}

			}

	}

//Returns the link that matches the name for the input arguments, uses nameCompare() from Link.cpp
Link* LinkList::nameSearch(char* fName, char midIni, char* lName)

	{

		current = first; //start at the beginning

		if(current == 0)  //if list is empty, return null pointer

			{

				//std::cout << "List is empty!" << std::endl;

				return 0;
			
			}

		else

			{

				while(current != 0) //if not empty iterate through list comparing the data

					{

						if(current->nameCompare(fName, midIni, lName) == true)  //if match found return pointer to link

							{

								return current;

							}

						current = current->getNext();  //Set current to next pointer for comparison
					}

				return 0;  //If link not found in list, return a null pointer

			}

	} 

//Returns the link that matches the number and team for the input arguments, uses numberCompare() and teamCompare() from Link.cpp
Link* LinkList::numTeamSearch(int pnum, char* tName)


	{

		current = first;   //start at beginning

		if(current == 0)   //If list is empty report that and return null pointer

			{

				std::cout << "List is empty!" << std::endl;

				return 0;

			}

		else

			{

				while(current != 0) //If current points at a link, inspect it, return link if match, return null if not

					{

						if((current->numberCompare(pnum) == true) && (current->teamCompare(tName) == true))


							{

								return current; //If match, return pointer to link

							}	

						current = current->getNext();  //Iterated through the list one at a time

					}
			
				return 0;   //If not found return null pointer

			}

	}
