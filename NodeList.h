/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: NodeList.h 						     *
*									     *
*       This header file declares the NodeList class which is derived        *
*       from the LinkList class. It handles comparisons and are the nodes    * 
*       for the Tree.cpp Binary Search Tree data structure. The nodes use    * 
*       a key that is hashed from the Player number input into the Player    *
*       class data member (pNum). This class manages pointers to the left    *
*       and right children of the node, and compares the key to make the     *
*       correct decision to go left or right in the binary tree structure.   *
*                                                                            *
*                                                                            *
*****************************************************************************/


#include "LinkList.h"

class NodeList : public LinkList

	{

		private:

			int key;               //Integer key for binary search 	

			NodeList* leftChild;   //Pointer to the left child of the node

			NodeList* rightChild;  //Pointer to the right child of the node


		public:

			//Default constructor, initialize left and right child to null, and key to 0
			NodeList();

			//Copy contructor, creates a copy of the node, and therefore the derived link list
			NodeList(const NodeList &source);

			//Destructor, calls delete on the left and right children for efficienct destruction of whole tree
			~NodeList();

			//Sets the key of the node to the input value (will be based on hashNumber(int pNum) from Tree.cpp
			void setKey(int key);

			//Returns the key to the node, found that it was required(or at least made it much easier) to copy the tree in Tree.cpp coy constructor
			int getKey();

			//Compares the key input to the key of the node, returns a 1, -1, or 0. (1 means go right, -1 means go left, 0 means match)
			int keyCompare(int keyEnter);

			//Set leftChild pointer to the input pointer 
			void setLeftChild(NodeList* newLeft);

			//Set leftChild pointer to the input pointer				
			void setRightChild(NodeList* newRight);

			//Getter for the pointer to the leftChild of the node, returns a pointer to the leftChild
			NodeList* getLeftChild();

			//Getter for the pointer to the rightChild of the node, returns a pointer to the leftChild
			NodeList* getRightChild();

			//Display the key to the node, was very helpful in testing insert, delete, and search functions of the Tree.cpp binary tree
			void displayKey();
			
	};

