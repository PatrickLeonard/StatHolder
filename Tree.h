/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: Tree.h 						     *
*									     *
*       This header file declares the Tree class which is a binary search    *
*       search tree data structure that uses the NodeList class as nodes.    * 
*       This class has the insert and delete node functions as well as two   * 
*       search function that rely on the search and compare functions of     *
*       the NodeList and Link classes. It also handles inserting links into  *
*       the NodeList class by managing the binary tree structure. It also    *
*       has a function that will recursively construct a completely balanced *
*       tree with the input of a range of keys for the tree. This is because *
*       the tree itself is not self balancing, so making a balanced tree at  *
*       onset of the program keep the complexity down while still having     *
*       a balanced tree. The program will not be able to insert and delete   *
*       nodes(NodeList) so as not to disturb the tree's balance.             *
*                                                                            *
*                                                                            *
*****************************************************************************/


#include "NodeList.h"

class Tree

	{

		private:

			NodeList* root;   //A pointer to the root of the tree

			bool searchFound;  //A member data bool used for a breadth first recursive search (treeSearchName())

			
		public:

			//Default contructor, initializes root to null, and searchFound to false
			Tree();

			//Destructor, deletes the root node, which cascade deletes the rest of the tree using the NodeList destructor
			~Tree();

			//Copy construtor, creates a duplicate tree with a deep copy of all data members/classes
			Tree(const Tree &source);

			//Recursive node insertion used by the copy constructor
			void copyTree(NodeList* tempRoot);

			//Insert a node with an input key, used during buildBalancedTree(), and can be used normally			
			void insertNode(int key);

			//Special insert function used only by the copy constructor, inserts deeply copied NodeList objects 
			void copyInsert(int key, const NodeList &source);

			//Deletes nodes from the tree with given key, compilcated code ^^;
			void deleteNode(int key);

			//Inserts input link into the proper NodeList, uses hashNumber() to find correct node, then calls insertLink() from NodeList class 
			void insertLink(Link* newLink);

			//Deletes the input link from the proper NodeList, uses hashNumber() to find correct node, then calls deleteLink() from NodeList class
			void deleteLink(Link* delLink);

			//Tree traverse function to get the proper node with a given key attainted from using hashNumber()
			NodeList* findNode(int key);

			//Builds a balanced tree using insertNode(), this is done recursively by giving it a range of keys and inserting nodes with a key that is  
			//the mid of the range.
			void buildBalancedTree(int min, int max);

			//Calls the recursive search function treeSearchName() with input arguments for the name of player being searched for, returns pointer
			//passed by reference to treeSearchName
			Link* nameSearchCall(char* fName, char midIni, char* lName);

			//Recursive breadth-first search for a player profile, assigned link to a pointer passed by refernce when profile is found
			void treeSearchName(Link*& searchLink, NodeList* node, char* fName, char midIni, char* lName);

			//Returns a link from a binary search that uses hashNumber() and findNode() to find the correct node then calls numTeamSearch() from NodeList class
			Link* treeNumTeamSearch(int pnum, char* tName);

			//Recursive in-order traverse of all the nodes in the tree, used for testing, displays the key of the node visited to ensure proper insertion/deletion
			void inOrderTraverse(NodeList* node);

			//Calls inOrderTravers() with root as the input node to begin the recursive display of the tree 
			void displayTree();

			//Takes the player number being search for, and returns the proper hashed number. Link.cpp has the same function but without input.
			//Used to match the search with how the links are inserted.
			unsigned int hashNumber(int pNum);

	};

  
