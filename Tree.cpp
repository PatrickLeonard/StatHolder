/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: Tree.cpp 						     *
*									     *
*       This C++ file implements the Tree class which is a binary search     *
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


#include "Tree.h"

//Default constructor, initializes root to null, and searchFound to false
Tree::Tree(): root(0), searchFound(false) 

	{

	}

//Destructor, deleting the root causes the destructor of NodeList to delete it's children, cascade effect 
//to destroy the entire tree
Tree::~Tree()

	{

		delete root;

	}

//Copy constructor, calls copyTree with a pointer to the sources root node
Tree::Tree(const Tree &source): root(0), searchFound(false)

	{

		NodeList* copyNode = 0;  //Initialize and assign a NodeList link to null

		copyNode = source.root; //point copyNode to the source's root node

		copyTree(copyNode);     //call copyTree function with pointer to source root as argument

	}

//Recursive insertion of deeply copied nodes into tree being copied into 
void Tree::copyTree(NodeList* tempRoot)

	{

		if(tempRoot == 0)  //If input node is null, then return

			{

				return;

			}

		this->copyInsert(tempRoot->getKey(), *tempRoot);  //Use copyInsert to insert deep copied nodes into tree

		NodeList* left = tempRoot->getLeftChild();    //Set left pointer to point to the leftChild of input node from source

		NodeList* right = tempRoot->getRightChild();  //Set right pointer to point to the rightChild of input node from source

		this->copyTree(left);  //recursive call to the left 

		this->copyTree(right);  //recursive call to the right

	}

//Creates and inserts a node with the key given as input
void Tree::insertNode(int key)

	{

		NodeList* newNode = new NodeList(); //create a new Node using default constructor

		newNode->setKey(key);    //Set the new node's key to the input key

		NodeList* parent = 0;    //Create a NodeList pointer for the parent of the new node and set to null

		NodeList* current = 0;   //Create a NodeList pointer for the current node and set to null 

		if(root == 0)  //if tree is empty, make inserted node the root

			{

				root = newNode;

				return;

			}

		else           //Tree is not empty, must find the proper place to insert a node

			{

				current = root;  //Start at the root of the tree

				while(current != 0)  //While the current node isn't null, when the current is null, the parent will be the node to attach to

					{

						parent = current;      //Set parent to current, keeps the parent one behind the current	

						if(current->keyCompare(key) == 1)   //Key is greater than current node so go right 

							{

								current = current->getRightChild();

							}	

						else if(current->keyCompare(key) == -1)            //Key is less than current node so go left
							
							{

								current = current->getLeftChild();

							}

						else             //Node already exists keyCompare() returns 0, don't duplicate nodes 

							{
							
								std::cout << "Node already exists!" << std::endl;

								return;

							}

					}

				if(parent->keyCompare(key) == 1)  //If the node attaches to right side of parent then attach

					{

						parent->setRightChild(newNode);

						return;

					}

				else                             //If the node attches to the left side of the parent then attach

					{

						parent->setLeftChild(newNode);

						return;

					}

			}

	}

//Special insert function that is exacty like the normal insert function except that the node is a deep copy from another tree
//This function takes an additional arguement to make deep copies of the NodeList objects. Please refer to above for additional comments
void Tree::copyInsert(int key, const NodeList &source)

	{

		NodeList* newNode = new NodeList(source);   //this is the difference, when the node is created it is a deep copy

		newNode->setKey(key);

		NodeList* parent = 0;

		NodeList* current = 0;

		if(root == 0)

			{

				root = newNode;

				return;

			}

		else

			{

				current = root;

				while(current != 0)

					{

						parent = current;	

						if(current->keyCompare(key) == 1)

							{

								current = current->getRightChild();

							}	

						else
							
							{

								current = current->getLeftChild();

							}

					}

				if(parent->keyCompare(key) == 1)

					{

						parent->setRightChild(newNode);

						return;

					}

				else

					{

						parent->setLeftChild(newNode);

						return;

					}

			}

	}

//Deletes a node from the tree with the given key as argument
void Tree::deleteNode(int key)

	{

		NodeList* current = root;  //Start at the top of the tree 

		NodeList* parent = root;  //Parent will stay a node behind, but will also start at the top of tree

		bool found = false;  //Initialize found bool to false, to manage finding the node to be deleted

		if(root == 0)      //If root is null then the tree is empty and there is nothing to delete 

			{

				std::cout << "The Tree is empty!" << std::endl;

				return;

			}

		while(current != 0)   //While current points to a node in the tree, compare the key to find the correct node 

			{

		
				if(current->keyCompare(key) == 0) //If match break out of whie loop and set found to true

					{

						found = true;

						break;

					}

				else if(current->keyCompare(key) == 1)  //If input key is greater than the node's key, go right

					{

						parent = current;  //Set parent to current and current to the right, keeps parent behind by one

						current = current->getRightChild();

					}

				else

					{

						parent = current;  //Set parent to current and current to the left, keeps parent behind by one

						current = current->getLeftChild();

					}

			}	


		if(!found)  //If node isn't found, say so and return

			{

				std::cout << "Node not found" << std::endl;

				return;

			}

		//When deleting from a binary search tree there are three possibilities: 1. The node is a leaf and has no children, 2. The node has one child
		//and 3. The node has two children. Each possibility is addressed below

	
 		//The node has one child, either on the left or the right
		if(((current->getLeftChild() != 0) && (current->getRightChild() == 0)) || ((current->getLeftChild() == 0) && (current->getRightChild() != 0)))

			{

				if((current->getLeftChild() != 0) && (current->getRightChild() == 0))  //if the child of deleted node is on the left

					{

						if(parent->getLeftChild() == current)  //if the delete node is on the left of the parent (one behind)

							{

								parent->setLeftChild(current->getLeftChild());  //then make the left child node the left child node of parent

								current->setLeftChild(0);  //Completely cut the deleted node out of the tree

								current->setRightChild(0); //Protects against unintentially destroying the rest of tree
								
								delete current;   //Delete the node

								return;

							}

						else
					
							{	

								parent->setRightChild(current->getLeftChild());  //then make the right child node the left child node of parent

								current->setLeftChild(0);  //Completely cut the deleted node out of the tree

								current->setRightChild(0); //Protects against unintentially destroying the rest of tree
								
								delete current;   //Delete the node

								return;

							}

					}	

				else

					{	

						if(parent->getRightChild() == current)  //Node to be deleted is the right node of the parent (one behind)

							{

								parent->setRightChild(current->getRightChild()); //make the right child of the node the right child of parent

								current->setLeftChild(0);  //Completely cut the deleted node out of the tree

								current->setRightChild(0); //Protects against unintentially destroying the rest of tree

								delete current;

								return;

							}

						else

							{

								parent->setLeftChild(current->getRightChild()); //make the left child of the node the right child of parent 

								current->setLeftChild(0);  //Completely cut the deleted node out of the tree

								current->setRightChild(0); //Protects against unintentially destroying the rest of tree

								delete current;

								return;

							}

					}	

				
	
			}


		//Node has two children, now have to take into account the children of the children...damn grandkids :P 
		else if((current->getLeftChild() != 0) && (current->getRightChild() != 0))

			{

				//Simple case, the children have not children
				if((current->getRightChild()->getLeftChild() == 0) && (current->getRightChild()->getRightChild() == 0))

					{
				
						NodeList* successor = current->getRightChild(); //Create a successor pointer and assign it to the right child

						successor->setLeftChild(current->getLeftChild());  //Set the successor's left child to the left child of the deleted node

						if(current == parent->getLeftChild())  //If the deleted node is to the left of the parent

							{

								parent->setLeftChild(successor);  //set the left child of parent to the successor

							}

						else

							{

								parent->setRightChild(successor); //Else it's on the right and the right child of parent is set to succesor

							}

						if(current == root)  //If the deleted node is the root make sure to assign root to successor, always keep track of root

							{

								root = successor;

							}

						current->setRightChild(0);  //Competely cut node out of tree before deletion

				                current->setLeftChild(0);   //Keeps node from cascadingly destroying parts(whole) of tree
						
						delete current;

						return;

					}

				else        //The child nodes have their own children, a proper successor must be found and promoted

					{

						NodeList* successor = current->getRightChild();   //Set successor pointer to the right child of deleted node

						NodeList* successorParent = 0;  //Initialize a parent successor to null

						while(successor->getLeftChild() != 0)  //After going right once, successor goes left until the next left is null

							{

								successorParent = successor; //Set successor parent to successor and succesor goes left (keeps parent one back)

								successor = successor->getLeftChild();  //succesor to left

							}

						if(successor->getRightChild() != 0) //If the successor (the far left node after going right once) has a right child

							{
								successorParent->setLeftChild(successor->getRightChild());  //then successorParent must point to it

							}

						else

							{

								successorParent->setLeftChild(0); //if the successor has no right child then successorParent will point to null

							}

						if(current = parent->getLeftChild()) //if the node to be deleted is on the left side of its parent 

							{

								parent->setLeftChild(successor); //Then promote succesor to the left child of deleted node's parent

							}

						else

							{

								parent->setRightChild(successor); //Else it's on the right and must promote to right child of delete node parent

							}

						successor->setLeftChild(current->getLeftChild()); //Place the successor into the spot of the deleted node

						successor->setRightChild(current->getRightChild());  //by setting the left/right child to that of the deleted node's

						if(current == root) //If the deleted node is the root, assign successor to root, always keep track of the root node

							{

								root = successor;

							}

						current->setLeftChild(0); //Cut the node completely out of the tree before deletion

						current->setRightChild(0); //Prevents node from cascade deletion of the rest of the tree

						delete current;

						return;

					}	
						
			}

		else   //The deleted node has no children (a leaf)....the simple case..hence the much less code

			{

				if(current == parent->getLeftChild())  //If the deleted node is to the left of the parent

					{

						parent->setLeftChild(0);  //Set the parent node right child to null

						delete current;   //No need to cut it out of the tree since it's children don't exist

						return;

					}

				else

					{

						parent->setRightChild(0); //Set the parent node right child to null

						delete current;  //No need to cut it out of the tree since it's children don't exist

						return;

					}
		
			}  

	}

//Inserts argument link into the tree     
void Tree::insertLink(Link* newLink)

	{

		int key = newLink->hashNumber();  //Get proper node key from hashNumber()

		NodeList* temp = findNode(key);   //Find the proper node with said key, and return node pointer into temp

		temp->insertLink(newLink);	//Call insertLink() from NodeList to insert the link into the linked list	

	}

//Deletes the argument link from the tree
void Tree::deleteLink(Link* delLink)

	{

		int key = delLink->hashNumber();  //Get proper node key from hashNumber()

		NodeList* temp = findNode(key);   //Find the proper node with said key, and return node pointer into temp

		temp->deleteLink(delLink); 	//Call deleteLink() from NodeList to delete the link from the linked list

	}

//Finds the correct node with the given key, used in treeNumTeamSearch(), insertLink(), deleteLink(). Traverses the tree using the keyCompare() of NodeList 
NodeList* Tree::findNode(int key)

	{

		NodeList* current = root;  //Start at the beginning

		while(current != 0)    //While current points at a node

			{

				if(current->keyCompare(key) == -1)  //if the input key is less than the node key, then go left

					{

						current = current->getLeftChild();

					}

				else if(current->keyCompare(key) == 1)  //if the input key is greater than the node key, the go right

					{

						current = current->getRightChild();

					}

				else    //The keys match, so break out of the loop with current pointing to the correct node

					{

						 break;

					}

			}

		if(current == 0)  //If current is null (either the tree is empty or the node isn't in the tree)

			{

				std::cout << "Node not found!" << std::endl;

		 	}

		return current;  //return current null or not

	}
		
//Recursive creation of a balanced tree. This function takes a range of keys as the argument, and is meant to match up with 
//the hashNumber() functions to produce keys in the proper range. Recursively inserting the mid of the range in the proper order
//will create a balanced tree for any range.  
void Tree::buildBalancedTree(int min, int max)

	{

		if(min > max)  //Stop trying to insert if the min key becomes greater than the max, no mid key can be found that will keep the tree balanced 

			{

				return;

			}

		int mid = 0;  //Make sure mid is 0 to keep the math correct and protect against erroneous errors

		mid = (max - min)/2 + min; //Find the mid value key to insert the proper node to keep balance 	

		insertNode(mid);    //Insert the node

		buildBalancedTree(min, mid - 1);  //Recursive call to insert a node to the left of the current insert, that is the mid of the range

		buildBalancedTree(mid + 1, max);  //Recursive call to insert a node to the right of the current insert, that is the mid of the range

	}

//This function calls a recursive function after checking if the tree is empty, it takes a player's full name as the three arguements
//It calls treeSearchName() with a pointer to a link, the root pointer of the tree, and the name arguements.
Link* Tree::nameSearchCall(char* fName, char midIni, char* lName)
	
	{

		searchFound = false;   //must reset searchFound before searching

		if(root == 0)  //Tree is empty!~

			{
			
				std::cout << "Tree is empty!" << std::endl;
	
				return 0;

			}

		Link* link = 0;  //Initialize a Link ponter to null

		treeSearchName(link, root, fName, midIni, lName); //Call recursive search function, the Link pointer is passed by reference

		if(link == 0)  //If link is null the profile wasn't found

			{
		
				std::cout << "Profile not found!" << std::endl;

			}

		else

			{

				std::cout << "Found profile!" << std::endl;

			}

		return link;  //return a pointer to the found Link object

	}

//Recursive function that does a breadth-first search for the given name arguements from nameSearchCall()		
void Tree::treeSearchName(Link*& searchLink, NodeList* node, char* fName, char midIni, char* lName) 
	
	{

		if(node == 0) //If node is null, the end of the tree was reached without finding the Link

			{

				return;

			}

		else if(searchFound == true) //If searchFound is true, then the Link was found and the search can be stopped
	
			{
	
				return;

			}

		else        //Not done searching yet

			{
	
				searchLink = node->nameSearch(fName, midIni, lName);   //call nameSearch() from NodeList class recursively with name arguments

				if(searchLink != 0) //If a Link in the node is found set searchFound bool to true, this tells other searches to stop

					{

						searchFound = true;

					}

				treeSearchName(searchLink, node->getLeftChild(), fName, midIni, lName);  //Recursive call passing the Link pointer by reference to the left

				treeSearchName(searchLink, node->getRightChild(), fName, midIni, lName); //Recursive call passing the LInk pointer by reference to the right

			}

	}

//A search function that returns a pointer to a Link object with the player's number and team name as arguments 
Link* Tree::treeNumTeamSearch(int pnum, char* tName) 

	{

		int key = 0; //Set int to 0

		key = hashNumber(pnum); //Get the node key from input player number using hashNumber(pnum)

		NodeList* tempNode = 0;  //temporary pointer to a NodeList object initialized to null

		tempNode = findNode(key);  //Get the node from findNode() and assign to tempNode

		if(tempNode == 0)  //If tempNode is null then the node doesn't exist

			{

				std::cout << "Profile not found!" << std:: endl;

				return 0;

			}

		Link* tempLink = 0;  //Intialize a temporary pointer to a Link object to null

		tempLink = tempNode->numTeamSearch(pnum, tName);  //The proper node was found, search the node for the proper Link

		if(tempLink == 0) //tempNode returned 0 meaning the profile wasn't in the link list

			{

				std::cout << "Profile not found!" << std::endl;

				return tempLink;

			}

		else       //Profile found, return the pointer to it
	
			{
			
				std::cout << "Found profile!" << std::endl;

				return tempLink;

			}

	}

//Recursive function that displays the node keys of the tree in order, used for testing
void Tree::inOrderTraverse(NodeList* node)

	{

		if(node != 0)  //If the node exists
			
			{

				if(node->getLeftChild() != 0)  //If the node's left child exists recursive call that to the left 

					{

						inOrderTraverse(node->getLeftChild());

					}

				node->displayKey();  //Call display key function

				if(node->getRightChild() != 0) //If the node's right child exists recursive call the to the right

					{

						inOrderTraverse(node->getRightChild());	

					}

			}


		else   //Reached the end of the tree, stop traversing

			{

				return;

			}

	}

//Function to call the recursive function inOrderTraverse, uses the root as the arguement for the function call
void Tree::displayTree()

	{

		inOrderTraverse(root);

	}

//Matching hashNumber() used to for searches to match the insertion hashNumber() function in Link.cpp
unsigned int Tree::hashNumber(int pNum)

	{
		
		const int PRIME = 3571;  //A large constant prime number to help evenly distribute Links throughout the tree

		const int MAX_RANGE = 32;  //Top range of output values

		const int OFF_BY_ONE = 1;  //To make 0-31 into 1-32, no node keys of 0

		unsigned int hash = pNum;  //intialize hash to the input pNum

		hash = ((hash * PRIME) % MAX_RANGE) + OFF_BY_ONE;	 //Does the math to create a key to insert the Link object into the proper NodeList

		return hash;	

	}
