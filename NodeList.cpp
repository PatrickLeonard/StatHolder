/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: NodeList.cpp 						     *
*									     *
*       This C++ file impelements the NodeList class which is derived        *
*       from the LinkList class. It handles comparisons and are the nodes    * 
*       for the Tree.cpp Binary Search Tree data structure. The nodes use    * 
*       a key that is hashed from the Player number input into the Player    *
*       class data member (pNum). This class manages pointers to the left    *
*       and right children of the node, and compares the key to make the     *
*       correct decision to go left or right in the binary tree structure.   *
*                                                                            *
*                                                                            *
*****************************************************************************/


#include "NodeList.h"

//Default constructor, initializes key to 0, and leftChild/rightChild pointers to null
NodeList::NodeList(): key(0), leftChild(0), rightChild(0)

	{

	}

//Copy constructor, invokes the bass class (LinkList) copy constructor, and initializes leftChild
//rightChild to null, and assigns the key from the source to key
NodeList::NodeList(const NodeList &source): LinkList(source), leftChild(0), rightChild(0)

	{

		key = source.key;	

	}

//Destructor, calls delete on the left and right child pointers to efficiently destroy the binary tree
NodeList::~NodeList()

	{

		delete leftChild;

		delete rightChild;

	}

//Sets the node's key to the key that is input
void NodeList::setKey(int newKey)

	{

		key = newKey;

	} 

//Returns the node's key (Only used in copying the binary tree structure)
int NodeList::getKey()

	{

		return key;

	}

//Compares the input key to the key of the node
int NodeList::keyCompare(int keyEnter) 
	
	{

		int temp = 0;  //Initlize temp int variable to zero

		temp = keyEnter - key;  //Subtract node key from input key


		if(temp > 0)  //If keyEnter is > key , then temp is postive and thus go right by returning 1

			{

				return 1;

			}

		else if(temp < 0) //If keyEnter is < key, the temp is negative and thus go left by return -1

			{

				return -1;

			}

		else

			{

				return 0;  //Key and keyEnter match, found the correct node, return 0 

			}

	}

//Set leftChild pointer to point at the input link
void NodeList::setLeftChild(NodeList* newLeft) 
		
	{

		leftChild = newLeft;

	}

//Set rightChild pointer to point at the input link
void NodeList::setRightChild(NodeList* newRight) 
		
	{

		rightChild = newRight;

	}

//Returns a pointer to the nodes left child 
NodeList* NodeList::getLeftChild()
	
	{

		return leftChild;

	}

//Returns a pointer to the nodes right child
NodeList* NodeList::getRightChild()

	{

		return rightChild;

	}

//Displays the node's key. Very helpul in testing, really used in the program
void NodeList::displayKey()

	{

		std::cout << "Node Key: " << key << std::endl;

		return;

	}
		 
