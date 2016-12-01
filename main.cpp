/*****************************************************************************
*									     *
*	Name: Patrick Leonard						     *
*	Class: CS202 Fall 2012						     *
*	Assignment: Program 1						     *
*	Date: 10/16/2012						     *
*	Filename: main.cpp 						     *
*									     *
*      Welcome to the Team Sports Roster v.5!                                *
*                                                                            * 
*      This program allows you to enter in the name, team name, player       * 
*      number, position, height, weight, and 40m sprint time of players      *
*      in your American Football League. This program will allow you to      *
*      enter hundreds of player profiles, edit these profiles, delete them,  *
*      and search by name or teamn and number. In this very beta program     *
*      however, you won't be able to save the rosters, export them to a file *
*      or print them. That will come in later versions should I decide to    *
*      continue to support this program. Thanks for taking a look at the     *
*      beta release of Team Sports Roster v.5. I will enjoy your feedback.   *
*                                                                            *
*                                                                            *
*****************************************************************************/


#include "Tree.h"

int main()

	{

		const int MAX_RANGE = 32;   //Used to create the balanced tree see buildBalancedTree() in Tree.cpp

		const int MIN_RANGE = 1;

		const int LOWER_CASE_LOW = 96;    //constant variables to hold literal unchanging numbers

		const int LOWER_CASE_HIGH = 123;  //Used to ensure proper case in char arrays

		const int UPPER_CASE_LOW = 64;

		const int UPPER_CASE_HIGH = 91;

		const int UPPER_LOWER_DIFF = 32;

		const int INPUT_BUFFER_SIZE = 50;  //Buffer size for input char arrays

		int choice = 0;   //Used in switch statement for choices

		int selection = 0;  //Used in nested do-while loop for editing or deleting a search for profile

		char ok = 'x';    //Used in confirming user input

		Link* searchLink = 0;    //Pointer to a Link object that will hold return values for searches

		Tree* tree = new Tree();   //Create a new Tree object to implement the program

		tree->buildBalancedTree(MIN_RANGE, MAX_RANGE); //Build a balanced tree using proper range(which corresponds to hashNumber() function(s))			

		//Output to user the purpose of the program, and to explain the programs current limitations.
		std::cout << "Team Sports Roster v.5\n";

		std::cout << "----------------------\n\n";

		std::cout << "Welcome to the Team Sports Roster v.5! As of now this program is configured for American Football.\n";

		std::cout << "If you were hoping for a different sport then you'll have to purchase a different version of this\n";

		std::cout << "program. This is a very early beta version for demonstration purposes only. There is no ability\n";

		std::cout << "to save the rosters, export them to a file, or print them. You are able to created and edit\n";

		std::cout << "profiles, delete profiles, search for profiles by name, and search by player number and team name.\n";		

		std::cout << "You must insert a profile before it can be searched for, edited, or deleted. You must search for a\n";

		std::cout << "profile before it can be edited or deleted.\n\n";

		do    //begin do-while loop for using the program...end loop = end program

			{

				//Prompt user with choices and ask for selection
				std::cout << "\n\n\nHow would you like to proceed?\n";	

				std::cout << "1.Create a profile\n";

				std::cout << "2.Search by Name\n";

				std::cout << "3.Search by player number and team\n";

				std::cout << "4.Quit the program\n";

				std::cout << "Selection: ";

				std::cin >> choice;

				//Input validation for choice
				while((choice < 1) || (choice > 4))
				
					{

						std::cout << "Invalid selection. Please choose 1-4: ";
						 					
						std::cin >> choice;

					}

				switch(choice)   //Begin switch statement

					{

						case 1 :{    //case 1 creates a new link, edits the profile, and inserts the link into the Tree 

							Link* link = new Link();

							link->editProfile();

							tree->insertLink(link);	
	
							break;
							
							}//end case 1

						case 2:{   //case 2 searches the tree using nameSearchCall() in Tree.cpp 

							 do  //begin do-while loop for search name input

							     {
								
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

								      //If confirmed call nameSearchCall() in Tree.cpp and delete input char arrays 
								      if(ok == 'y' || 'Y')
							
										{

											searchLink = tree->nameSearchCall(fNameInput, midInput[0], lNameInput);

											delete [] fNameInput;

											delete [] midInput;

											delete [] lNameInput;
								
										}

						       	   } while((ok != 'y') && (ok != 'Y'));  //Continue do-while loop until name is confirmed

							   if(searchLink == 0)  //After search check if found, if not break

								{

									break;

								}

							   else

								{

									do  //If found begin nested do-while loop for editing for deleting profile

										{

											//Display the profile under consideration
											searchLink->displayPlayerProfile();

											selection = 0;  //Set selection to default value

											//Prompt user with selections and ask user for input
											std::cout << "\n\n\nWould you like to edit or delete profile?\n";

											std::cout << "1. Edit\n";

											std::cout << "2. Delete\n";

											std::cout << "3. Return to previous menu\n";

											std::cin >> selection;
											
											//Input validation for selection
											while((selection != 1) && (selection != 2) && (selection != 3))

												{

													std::cout << "Invalid input. Please choose 1, 2 , or 3: ";

													std::cin >> selection;	
							
												}

											if(selection == 1)  //Selection 1 is to editProfile

												{

													searchLink->editProfile(); 

												}

											else if(selection == 2)  //Selection 2 is to delete profile

												{

													tree->deleteLink(searchLink);  //delete link

													searchLink = 0;  //Set searchLink back to null

													selection = 3;  //Return to previous menu as there is no link to edit

												}

										}while(selection != 3); //Either link is deleted or user is finished editing to end do-while

									break; //break from switch

								    }//end case 2

								}


							case 3:{ //Search by team name and player number 

								do

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


									int playerNumber = 0;  //Initialize playerNumber input variable to 0   

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

									//If confirmed call  treeNumTeamSearch() in Tree.cpp and delete input char array
									if(ok == 'y' || 'Y')	

										{ 
								   			searchLink = tree->treeNumTeamSearch(playerNumber, teamInput); 

											delete [] teamInput;

										}

								    } while((ok != 'y') && (ok != 'Y'));  //Continue do-while loop until player number is confirmed


								   if(searchLink == 0)  //Check if search succeeded, if not break    

									{

										break;

									}

								   else

									{

									    do  //If search succeeded then proceed to nested do-while loop for editing or deletion


										{

											//Display profile under consideration
											searchLink->displayPlayerProfile();

											selection = 0;  //Set to default value

											//Prompt user with selections and ask for input
											std::cout << "\nWould you like to edit or delete profile?\n";

											std::cout << "1. Edit\n";

											std::cout << "2. Delete\n";

											std::cout << "3. Return to previous menu\n";

											std::cin >> selection;
											
											//Input vaidation for selection
											while((selection != 1) && (selection != 2) && (selection != 3))

												{

													std::cout << "Invalid input. Please choose 1, 2 , or 3: ";

													std::cin >> selection;	
							
												}

											if(selection == 1) //Selection 1 to edit profile

												{

													searchLink->editProfile();

												}

											else if(selection == 2) //Delete profile, set searchLink to null, 
														//and return to previous menu

												{

													tree->deleteLink(searchLink);

													searchLink = 0;

													selection = 3;
												}

										}while(selection != 3); //Either the user is done editing or the profile is deleted				

									break; //End case 3

									}

								   }

							case 4: break; //case 4 is to exit the program
							
							default: break; //retry while still in do-while loop 

					}//end switch statement

			}while(choice != 4);

		delete tree;  //program is over delete the tree 

		return 0;

	}
