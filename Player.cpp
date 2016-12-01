/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: Player.cpp 						     *
*									     *
*	This C++ file implements the Player class that will hold and         *
*       manage the data for the player's profile. Holds different            * 
*       statistical information as well as the vital information for         * 
*       players in the league. This is the base class for the derived        *
*       class Link.                                                          *
*                                                                            *
*                                                                            *
*****************************************************************************/
 
#include "Player.h"

//Default constructor initializes all member data to null 
Player::Player(): firstName(0), lastName(0), position(0), middleInitial(0), heightFeet(0), 
		  heightInches(0), weightLbs(0), teamName(0), playerNumber(0), fortyMeterTime(0),
		  numberInput(false)
		  
	{

	}

//Overloaded constructor takes in arguements for the player profile and properly assigns them 
//to the member data. The name is divided into two arrays and a char (first name, mi, last name)
//Unsigned ints for the integer data, and a float for the 40m sprint time.
Player::Player(char fn[], char ln[], char p[], char tm[], char mi, unsigned int pnum, unsigned int hf,
	       unsigned int hi, unsigned int w, float t40)
	
	{

		firstName = arrayEcreator(fn);

		lastName = arrayEcreator(ln);

		position = arrayEcreator(p);

		middleInitial = mi;

		heightFeet = hf;

		heightInches = hi;

		weightLbs = w;

		teamName = arrayEcreator(tm);

		playerNumber = pnum;

		fortyMeterTime = t40;
	}

//arrayEcreator creates a dynamically allocated array from an input array 
//and returns a pointer to the new dynamically allocated array
char* Player::arrayEcreator(char* input )

	{
		
		int length = std::strlen(input);       //get the length of the input array

		char* eArray = new char[length + 1]; //create a new DMA array of proper length

		std::strcpy(eArray, input);            //copy the input array into the DMA array	
	
		return eArray;                       //return a pointer to the DMA array

	}

//Destructor for Player class, calls delete on the dynamically allocated data members
Player::~Player()

	{

		delete [] firstName;

		delete [] lastName;

		delete [] position;	

		delete [] teamName;

	}

//Copy constructor, frees DMA space and then makes a deep copy of data members to new object
Player::Player(const Player &source)

	{

		delete [] firstName;

		delete [] lastName;

		delete [] position;	

		delete [] teamName;

		firstName = arrayEcreator(source.firstName); //Use arrayEcreator to make deep copies
		
		lastName = arrayEcreator(source.lastName);

		position = arrayEcreator(source.position);

		teamName = arrayEcreator(source.teamName);

		middleInitial = source.middleInitial;

		heightFeet = source.heightFeet;

		heightInches = source.heightInches;

		weightLbs = source.weightLbs;

		playerNumber = source.playerNumber;

		fortyMeterTime = source.fortyMeterTime;
	
	}	

//Overloaded assignment operator. Not sure If implemented correctly, but wanted to try
Player & Player::operator=(const Player &source)
	
	{

		if(this != &source)

			{

				delete [] firstName;

				delete [] lastName;

				delete [] position;	

				delete [] teamName;

				firstName = arrayEcreator(source.firstName);
				
				lastName = arrayEcreator(source.lastName);

				position = arrayEcreator(source.position);

				teamName = arrayEcreator(source.teamName);

				middleInitial = source.middleInitial;

				heightFeet = source.heightFeet;

				heightInches = source.heightInches;

				weightLbs = source.weightLbs;

				playerNumber = source.playerNumber;

				fortyMeterTime = source.fortyMeterTime;

			}

		return *this;

	}
		
//Displays the member data (Player profile), nicely formatted with proper precision for foryMeterTime data. 
void Player::displayPlayerProfile()
	
	{

		std::cout << "\nPlayer Profile\n";

		std::cout << "----------------------------------------\n\n";
	
		std::cout << "Name: " << firstName << " " <<  middleInitial << ". " << lastName <<  "\n";
		
		std::cout << "Height: " << heightFeet << "\' " << heightInches << "\"" << "   Weight: " << weightLbs << " Lbs.\n";

		std::cout << "Team: " << teamName << "  Number: " << std::setw(2) << std::setfill('0') << playerNumber << "   40m Time: " << std::fixed  << std::setw(3) 
			  << std::setprecision(2)  << fortyMeterTime << "  Position: " << position << "\n";

	}


//This function manages the process for editing a profile, it has a lot of user input and output with 
//some input checking. 
void Player::editProfile()

	{
		
		const int LOWER_CASE_LOW = 96;    //constant variables to hold literal unchanging numbers

		const int LOWER_CASE_HIGH = 123;

		const int UPPER_CASE_LOW = 64;

		const int UPPER_CASE_HIGH = 91;

		const int UPPER_LOWER_DIFF = 32;

		const int INPUT_BUFFER_SIZE = 50;

		int choice = 0;                            //Choice variable for switch statement. Uses decides what process to do next (with restrictions)

		char ok = 'N';                             //Char variable for user confirmation of input data
		

		do                                        //Begin do-while loop for user input of profile, ends when a user chooses and when enough profile has be input
			{

				choice = 0; //Re-assign choice to zero when starting loop again.   
	
				if((firstName != 0) && (position != 0) && (teamName != 0))   //make sure the DMA arrays aren't empty before accessing
				
					{			

						displayPlayerProfile();

					}

				//Prompt the user for choices to make durring profile editing. Nicely formatted
				std::cout << "\n\n";
				
				std::cout << "Please choose what part of the profile you would like to edit.\n";

				std::cout << "Name, Number, Team, and Position must be entered into the Profile to continue.\n\n";
		
				std::cout << "1. Name\n2. Number\n3. Team\n4. Position\n5. Height\n6. Weight\n7. 40m Time\n8. to Quit\n";

				std::cout << "Selection: ";

				std::cin >> choice;

				while(!(choice > 0) && !(choice < 9))     //Input validation to make sure a proper choice was made. Loop will stop when choice is valid
	
					{

						std::cout << "Invalid entry. Please try again selecting 1-8.\n";

						std::cin >> choice;

					}

				switch(choice)

					{

						case 1:   do   //Input Name
								
								{

                                                                      if(firstName != 0)  //If a name has already been input, display it to edit properly

									{

									  std::cout << "Current Name: " << firstName << " " << middleInitial << ". " << lastName << std::endl;
				
									}

								      //Prompt user and get name input
							              std::cout << "Please enter first name: ";

								      char* fNameInput = new char[INPUT_BUFFER_SIZE];
							  	      
							  	      std::cin >> fNameInput;

							              //Ensure proper case of the input first name
							  	      if(fNameInput[0] < LOWER_CASE_HIGH && fNameInput[0] > LOWER_CASE_LOW)

										{

											fNameInput[0] -= UPPER_LOWER_DIFF;

										}

								      for(int i = 1; i < strlen(fNameInput); i++)

										{

											if(fNameInput[i] > UPPER_CASE_LOW &&
											   fNameInput[i] < UPPER_CASE_HIGH)

												{

												   fNameInput[i] += UPPER_LOWER_DIFF;

												}

										}

								      //Prompt user for input
								      std::cout << "Please enter middle initial: ";

								      char* midInput = new char[INPUT_BUFFER_SIZE];

								      std::cin >> midInput; 


								      //Ensure proper case of middle initial
								      if(midInput[0] < LOWER_CASE_HIGH && midInput[0] > LOWER_CASE_LOW)

										{

											midInput[0] -= UPPER_LOWER_DIFF;

										}

								      //Prompt user for input
								      std::cout << "Please enter last name: ";

								      char* lNameInput = new char[INPUT_BUFFER_SIZE];

								      std::cin >> lNameInput;

								      //Ensure proper case of input last name
								      if(lNameInput[0] < LOWER_CASE_HIGH && lNameInput[0] > LOWER_CASE_LOW)

										{

											lNameInput[0] -= UPPER_LOWER_DIFF;

										}

								      for(int i = 1; i < strlen(lNameInput); i++)

										{

											if(lNameInput[i] > UPPER_CASE_LOW &&
											   lNameInput[i] < UPPER_CASE_HIGH)

												{

												   lNameInput[i] += UPPER_LOWER_DIFF;

												}

										}
	
							 	      //Display the name that was input and ask use to confirm 
							  	      std::cout << "\n" << fNameInput << " " << midInput[0] << ". " << lNameInput <<  "   OK? (Y/N): ";
								
								      std::cin >> ok;
	
								      //Input validation for confirmation
								      while((ok != 'y') && (ok != 'Y') && (ok !=  'n') && (ok != 'N'))
									 	
										{

											std::cout << "Invalid input. Please enter (Y/N): ";
			
											std::cin >> ok; 

										}

							              //If confirmed free up DMA and assign name to proper member data
								      if(ok == 'y' || 'Y')
							
										{

		    								        delete [] firstName; 
									
										        delete [] lastName;

											firstName = arrayEcreator(fNameInput);

											lastName = arrayEcreator(lNameInput);

											middleInitial = midInput[0]; 	

											delete [] fNameInput;

											delete [] lNameInput;
							
											delete []  midInput;

										}

								} while((ok != 'y') && (ok != 'Y'));  //Continue do-while loop until name is confirmed

								break; //end case 1

						case 2:	  do    //input the player's number

								{

									//Prompt user for input
									std::cout << "Please enter the player's number(0-99): ";

									std::cin >> playerNumber;

									//Input validation, player numbers are only from 00 to 99 in most sports
									while(playerNumber > 99 || playerNumber < 0)

										{

											std::cout << "Invalid input. Please enter a number between 00 and 99: ";

											std::cin >> playerNumber;
										
										}

									//Display input player number and prompt for confirmation
									std::cout << "Player's Number: " << std::setw(2) << std::setfill('0') << playerNumber << "  OK? (Y/N):"; 	  
					
									std::cin >> ok;

									//Input validation on confirmation
									while((ok != 'y') && (ok != 'Y') && (ok != 'n') && (ok != 'N'))
									 	
										{

											std::cout << "Invalid input. Please enter (Y/N): ";
			
											std::cin >> ok; 

										}

								}while((ok != 'y') && (ok != 'Y'));  //Continue input of player number until confirmed

								numberInput = true; //A number was input necessary for insertion of player profile, edit must continue if false 

								break; //end case 2

											
							case 3:	  do   //Enter the team name

								{

									//Prompt user for input
									std::cout << "Please enter the team name: ";

									char* teamInput = new char[INPUT_BUFFER_SIZE];

									std::cin >> teamInput;

									//Ensure proper case for team name input (first letter capitalized, rest lower case)
									if(teamInput[0] < LOWER_CASE_HIGH && teamInput[0] > LOWER_CASE_LOW)

										{

											teamInput[0] -= UPPER_LOWER_DIFF;

										}

								      	for(int i = 1; i < strlen(teamInput); i++)

										{

											if(teamInput[i] > UPPER_CASE_LOW &&
											   teamInput[i] < UPPER_CASE_HIGH)

												{

												   teamInput[i] += UPPER_LOWER_DIFF;

												}

										}

									//Prompt for confirmation of team name input
									std::cout << "Team Name: " << teamInput << "   OK? (Y/N): ";

									std::cin >> ok;

									//Input validation for confirmation
									while((ok != 'y') && (ok != 'Y') && (ok != 'n') && (ok != 'N'))
									 	
										{

											std::cout << "Invalid input. Please enter (Y/N): ";
			
											std::cin >> ok; 

										}

								         //If confirmed, assign input to member data using arrayEcreator() 
								         if(ok == 'y' || 'Y')
							
										{
											
											delete [] teamName;

											teamName = arrayEcreator(teamInput);

											delete [] teamInput;

										}


								}while((ok != 'y') && (ok != 'Y'));   //Continue loop until user confirms input
				
								break; //end case 3  


						case 4:	  do    //Input position, using two letter code for position from the sport of American Football

								{

									//Prompt user for input
									std::cout << "Please enter the player's position (ex. QB): ";

									char* positionInput = new char[INPUT_BUFFER_SIZE];

									std::cin >> positionInput;

									//Ensure that only two letters are input (Specific to football)
									if(std::strlen(positionInput) > 3)
		
										{

											std::cout << "Invalid Input. Please enter only two characters (ex. QB): ";

											std::cin >> positionInput;

										}

									//Ensure that both letters are capitalized
								      	for(int i = 0; i < strlen(positionInput); i++)

										{

											if(positionInput[i] > LOWER_CASE_LOW &&
											   positionInput[i] < LOWER_CASE_HIGH)

												{

												   positionInput[i] -= UPPER_LOWER_DIFF;

												}

										}

									//Prompt user for confirmation
									std::cout << "Position: " << positionInput << "   OK? (Y/N): ";

									std::cin >> ok;

									//Input validation for confirmation
									while((ok != 'y') && (ok != 'Y') && (ok !='n') && (ok != 'N'))
									 	
										{

											std::cout << "Invalid input. Please enter (Y/N): ";
			
											std::cin >> ok; 

										}

								       //If confirmed assign input data into member data using arrayEcreator
								       if(ok == 'y' || 'Y')
							
										{

											delete [] position;

											position = arrayEcreator(positionInput);

											delete [] positionInput;

										}


								}while((ok != 'y') && (ok != 'Y'));  //Continue loop until data input is confirmed
				
								break; //end case 4  




						case 5:	  do    //Input height, first feet then inches

								{

									//Prompt user for input
									std::cout << "Please enter the player's height(feet): ";

									std::cin >> heightFeet;

									//Input validation
									while(heightFeet < 0)

										{

											std::cout << "Invalid input. Please enter a positive number: ";

											std::cin >> heightFeet;
										
										}

									//Prompt user for input
									std::cout << "Please enter the player's height(inches): ";

									std::cin >> heightInches;

									//Input validation, inches must be betwee 0-11
									while(heightInches < 0 || heightInches > 12)

										{

											std::cout << "Invalid input. Please enter a positive number between 0 and 12: ";

											std::cin >> heightInches;
										
										}

									//Display input and prompt for confirmation
									std::cout << "Player's Height: " << heightFeet << "' " << heightInches <<  "\"  OK? (Y/N):"; 	  
					
									std::cin >> ok;

									//Input validation for confirmation
									while((ok != 'y') && (ok !=  'Y') && (ok != 'n') && (ok != 'N'))
									 	
										{

											std::cout << "Invalid input. Please enter (Y/N): ";
			
											std::cin >> ok; 

										}

								}while((ok != 'y') && (ok != 'Y'));  //Continue loop until user confirms input

								break; //end case 5

						case 6:	  do   //Input player's weight

								{

									//Prompt user for input
									std::cout << "Please enter the player's weight(Lbs.): ";

									std::cin >> weightLbs;

									//Input validation, weight must be a positive number
									while(weightLbs < 0)

										{

											std::cout << "Invalid input. Please enter a positive number: ";

											std::cin >> weightLbs;
										
										}

									//Display input, and prompy user for confirmation
									std::cout << "Player's weight: " << weightLbs << "Lbs.  OK? (Y/N):"; 	  
					
									std::cin >> ok;

									//Input validation for confirmation
									while((ok != 'y') && (ok != 'Y') && (ok != 'n') && (ok != 'N'))
									 	
										{

											std::cout << "Invalid input. Please enter (Y/N): ";
			
											std::cin >> ok; 

										}

								}while((ok != 'y') && (ok != 'Y'));   //Continue loop until user confirms input

								break; //end case 6


						case 7:	  do    //Input 40m sprint time, American Football specific

								{

									//Prompt user for input
									std::cout << "Please enter the player's 40m Time(ex. 4.40): ";

									std::cin >> fortyMeterTime;

									//Input validation, time should be a positive number
									while(fortyMeterTime < 0)

										{

											std::cout << "Invalid input. Please enter a positive number: ";

											std::cin >> fortyMeterTime;
										
										}

									//Display input, and prompt user for confirmation
									std::cout << "Player's 40m Time: " << fortyMeterTime << "  OK? (Y/N):"; 	  
					
									std::cin >> ok;

									//Input validation for confirmation
									while((ok != 'y') && (ok != 'Y') && (ok != 'n') && (ok != 'N'))
									 	
										{

											std::cout << "Invalid input. Please enter (Y/N): ";
			
											std::cin >> ok; 

										}

								}while((ok != 'y') && (ok != 'Y'));  //Continue loop until user confirms input

								break; //end case 7

						case 8: break;  //Case to end switch statement

						default: break;  //retry choice while still in do-while loop
															
					}
			
			} while((choice != 8) || (firstName == 0) || (!numberInput) || (teamName == 0) || (position == 0)); //end while loop
			//Only ends the loop when the user chooses AND when the name, team name, position, and number have been entered into profile (per instructions)
	
	}

//Getter function for the player number, needed to insert profile into data structures
//returns an int by value
unsigned int Player::getNumber()

	{

		return playerNumber;

	}
//Getter function for the first name, used in searching for the profile
//returns a pointer to the member data
char* Player::getFirstName()

	{

		return firstName;

	}

//Getter function for the last name, used in searching for the profile
//returns a pointer to the member data
char* Player::getLastName()

	{

		return lastName;

	}

//Getter function for the middle initial, used in searching for the profile 
//returns the member data by value
char Player::getMiddleInitial()

	{

		return middleInitial;

	}

//Getter function for the team name, used in searching for the profile
//returns a pointer to the member data
char* Player::getTeamName()

	{

		return teamName;

	}
