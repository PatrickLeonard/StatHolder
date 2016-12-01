/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: Player.h						     *
*									     *
*	This header file begins the Player class that will hold and          *
*       manage the data for the player's profile. Holds different            * 
*       statistical information as well as the vital information for         * 
*       players in the league. This is the base class for the derived        *
*       class Link.                                                          *
*                                                                            *
*                                                                            *
*****************************************************************************/
 
       

#include <iostream>
#include <iomanip>
#include <cstring>

class Player

	{

	private:

		char* firstName;            //A pointer to a char array holding the first name

		char* lastName;             //A pointer to a char array holding the last name

		char* teamName;             //A pointer to a char array holding the teamName

		char* position;             //A pointer to a char array holding the position

		char middleInitial;         //A char variable to hold the middle initial 

		unsigned int playerNumber;  //An unsigned int to hold the player number

		unsigned int heightFeet;    //An unsigned int to hold the player's height(feet)

		unsigned int heightInches;  //An unsigned int to hold the player's height(inches)

		unsigned int weightLbs;     //An unsigned int to hold the player's weight

		float fortyMeterTime;       //A float holding the player's 40m sprint time

		bool numberInput;           //To ensure that a player number was input as it is needed to place the player into the correct node-list


	public:	

		//default constructor
		Player();

		//Overloaded constructor
		//Takes all the player's information to create a Player object 
		Player(char fn[], char ln[], char p[], char tm[], char mi, unsigned int pnum,
		       unsigned int hf, unsigned int hi,  unsigned int w, float t40);

		//Copy Constructor
		Player(const Player &source);

		//Destructor
		~Player();
	
		//An attempt at operator overloading. Overloads the assignment operator.	
		Player & operator=(const Player &source);

		//Displays the players profile, properly formatted 
		void displayPlayerProfile();

		//Takes in a statically allocated array for input and converts to a dynamically     
		//array using strcpy for storage in the Player object
		char* arrayEcreator(char arr[]);

		//Manages the input and output for editing the player's profile. Uses arrayEcreator
		void editProfile();

		//Returns the player's number, used to by hashNumber() to create the proper node key
		unsigned int getNumber();

		//Returns a pointer to the team's name, used by teamCompare() to find the profile
		char* getTeamName();

		//Returns a pointer to the player's first name, used by nameCompare() to search for the profile 
		char* getFirstName();

		//Returns a char to the player's middle name, used by nameCompare() to search for the profile
		char getMiddleInitial();

		//Returns a pointer to the player's last name, used by nameCompare() to search for the profile
		char* getLastName();

	};
