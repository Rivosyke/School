#include "Game.hpp"


Game::Game()
{
	playerOneWins = 0;
	playerTwoWins = 0;
}

void Game::play()
{
	bool playerOneChosen  = false;
	bool playerTwoChosen  = false;
	int initialMenuChoice = 0;
	int numOfMonsters = -1;
	
	do
	{
		clearScreen();
		printInitialMenu();
		
		cout << "User Input: ";
		initialMenuChoice = getInt();
		
		while ((initialMenuChoice < 1) || (initialMenuChoice > 5))
        {
            cout << endl << "Choice is not valid: Please choose 1-5.";
            cout << endl << "User Input: ";
            initialMenuChoice = getInt();
        }
        
		
		// Checks to see if player one has already chosen fighters
		if (initialMenuChoice == 2 and playerOneChosen)
		{
			cout << "Player one has already chosen!" << endl;
			cout << "Please choose again." << endl;
			pauseScreen();
		}
		// Checks to see if player two has already chosen fighters
		else if (initialMenuChoice == 3 and playerTwoChosen)
		{
			cout << "Player two has already chosen!" << endl;
			cout << "Please choose again." << endl;
			pauseScreen();
		}
		else
		{
			switch(initialMenuChoice)
			{
				// Choosing the number of monsters
				case 1:
					cout << "Number of monsters on both sides: ";
					numOfMonsters = getInt();
					
					while (numOfMonsters < 1)
					{
						cout << "There must be at least one monster on each side!" << endl;
						cout << "Number of monsters on both sides: ";
						numOfMonsters = getInt();
					}
					pauseScreen();
					break;
				// Player one monster inputs
				case 2:
					if (numOfMonsters == -1)
					{
						cout << "You must first choose the monster number!" << endl;
						pauseScreen();
					}
					else
					{
						monsterInput(1, numOfMonsters);
						pauseScreen();
						playerOneChosen = true;
					}

					break;
				// Player two monster inputs
				case 3:
					if (numOfMonsters == -1)
					{
						cout << "You must first choose the monster number!" << endl;
						pauseScreen();
					}
					else
					{
						monsterInput(2, numOfMonsters);
						pauseScreen();
						playerTwoChosen = true;
					}
					break;
				// Starting the fights
				case 4:
					monsterFighting();
					pauseScreen();
					break;
				// Exit
				case 5:
					break;
			}
		}
	} while (initialMenuChoice != 5);		
}		
		
		
/*********************************************************************
** Description: This method will populate the player lists with monsters
** based on the player's choices.
*********************************************************************/			
void Game::monsterInput(int playerNum, int monsterNum)
{
	int userChoice = 0;
	
	if (playerNum == 1)
	{
		for (int x = 0; x < monsterNum; x++)
		{
			clearScreen();
			printMonsters();
			cout << "Monster #" << x+1 << " choice: ";
			userChoice = getInt();
			
			// Ensures the monster choice is valid
			while ((userChoice < 1) || (userChoice > 5))
			{
				cout << endl << "Choice is not valid: Please choose 1-5.";
				cout << endl << "Choice: ";
				userChoice = getInt();
			}		
			playerOneFighters.addNodeTail(monsterChoice(userChoice));
		}
	}
	else
	{		
		for (int x = 0; x < monsterNum; x++)
		{
			clearScreen();
			printMonsters();
			cout << "Monster #" << x+1 << " choice: ";
			userChoice = getInt();
			
			// Ensures the monster choice is valid
			while ((userChoice < 1) || (userChoice > 5))
			{
				cout << endl << "Choice is not valid: Please choose 1-5.";
				cout << endl << "Choice: ";
				userChoice = getInt();
			}
			
			playerTwoFighters.addNodeTail(monsterChoice(userChoice));
		}
	}
}
	
void Game::monsterFighting()
{
        int startingFighter = 0;
        int rounds = 1;
        
        // Array of Creature pointers to handle which fighter goes first
        Creature* fightOrder[2];
        
        Creature* p1Fighter = playerOneFighters.getHead();
        Creature* p2Fighter = playerTwoFighters.getHead();

        // Loop that determines when either player is out of fighters
        while (p1Fighter and p2Fighter)
        {
			// Sets which fighter goes first
			startingFighter = randomNum(2);
			
			if (startingFighter == 0)
			{
				fightOrder[0] = p1Fighter;
				fightOrder[1] = p2Fighter;
			}
			else
			{
				fightOrder[0] = p2Fighter;
				fightOrder[1] = p1Fighter;
			}
			
			while (p1Fighter -> living() and p2Fighter -> living())
			{
					//cout << endl << "Attack: " << fightOrder[0] -> getName() << endl;
					fightOrder[1] -> defense(fightOrder[0] -> attack());
					//cout << "Remaining str for " << fightOrder[1] -> getName() 
					//	 << " : " << fightOrder[1] -> getStr() << endl;
            
					// Checks to see if the first attack of the round killed the 
					// second monster
					if (fightOrder[1] -> living())
					{
					//	cout << endl << "Attack: " << fightOrder[1] -> getName() << endl;
						fightOrder[0] -> defense(fightOrder[1] -> attack());
					//	cout << "Remaining str for " << fightOrder[0] -> getName() 
					//		 << " : " << fightOrder[0] -> getStr() << endl;
					}
			}
			
			cout << endl;
			cout << "***********************************************" << endl;
			cout << "Round #" << rounds << endl;
			cout << "Fighter One : " << fightOrder[0] -> getName() << endl;
			cout << "Fighter Two : " << fightOrder[1] -> getName() << endl;
			
			// Checks to see if monster 2 has died
			if (!(fightOrder[1] -> living()))
			{
				// If Player one's monster went first
				if (startingFighter == 0)
				{
					playerOneWins++;
					cout << "Round winner: Player One's " 
					     << fightOrder[0] -> getName() << endl;
					// Winning monster gets put on the back of the lineup
					p1Fighter -> restoreHP();
					playerOneFighters.addNodeTail(p1Fighter);
					// Losing monster gets added to the loser pile
					playerTwoLosers.addNodeHead(p2Fighter);
				}
				else
				{
					playerTwoWins++;
					cout << "Round winner: Player Two's " 
					     << fightOrder[0] -> getName() << endl;
					// Winning monster gets put on the back of the lineup
					p2Fighter -> restoreHP();
					playerTwoFighters.addNodeTail(p2Fighter);
					// Losing monster gets added to the loser pile
					playerOneLosers.addNodeHead(p1Fighter);

				}
			}
			else
			{
				// If player two's monster went first
				if (startingFighter == 0)
				{
					playerTwoWins++;
					cout << "Round winner: Player Two's " 
					     << fightOrder[1] -> getName() << endl;
					// Winning monster gets put on the back of the lineup
					p2Fighter -> restoreHP();
					playerTwoFighters.addNodeTail(p2Fighter);
					// Losing monster gets added to the loser pile
					playerOneLosers.addNodeHead(p1Fighter);
				}
				else
				{
					playerOneWins++;
					cout << "Round winner: Player One's " 
					     << fightOrder[1] -> getName() << endl;
 					// Winning monster gets put on the back of the lineup
 					p1Fighter -> restoreHP();
					playerOneFighters.addNodeTail(p1Fighter);
					// Losing monster gets added to the loser pile
					playerTwoLosers.addNodeHead(p2Fighter);

				}
			}
			
			// Get new fighters from the respective lists
			p1Fighter = playerOneFighters.getHead();
			p2Fighter = playerTwoFighters.getHead();
			rounds++;
			pauseScreen();
		} 
		
		// Output the tourney winner
		winner();
}

/*********************************************************************
** Description: This method will determine and output the winner of the
** tournament.
*********************************************************************/
void Game::winner()
{
	cout << "***********************************************" << endl;
	cout << "--------------Tournament results---------------" << endl;
	cout << "Player One Wins: " << playerOneWins << endl;
	cout << "Player Two Wins: " << playerTwoWins << endl;
	cout << endl;
	cout << "Tourney winner: ";
	
	if (playerOneWins > playerTwoWins)
	{
		cout << "Player One!" << endl;
	}
	else
	{
		cout << "Player Two!" << endl;
	}
}

/*********************************************************************
** Description: This method will output the loser lists
*********************************************************************/
void Game::losers()
{
	cout << "***********************************************" << endl;
	cout << "--------------Tournament results---------------" << endl;
	cout << "Player One Wins: " << playerOneWins << endl;
	cout << "Player Two Wins: " << playerTwoWins << endl;
	cout << endl;
	cout << "Tourney winner: ";
	
	if (playerOneWins > playerTwoWins)
	{
		cout << "Player One!" << endl;
	}
	else
	{
		cout << "Player Two!" << endl;
	}
}

/*********************************************************************
** Description: This method will print out the list of monsters
** available to the players.
*********************************************************************/
void Game::printMonsters()
{
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
	cout << "*                                              *" << endl;
    cout << "*             Choose your monsters!            *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl << endl;
    
    cout << "1) Barbarian" << endl;
    cout << "2) Vampire" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;
    cout << endl;
    
}

void Game::printInitialMenu()
{
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*             Monster Tournament!              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*           Have both players choose           *" << endl;
    cout << "*               their fighters!                *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl << endl;
    
    cout << "1) Choose number of fighters" << endl;
    cout << "2) Player One Fighter Input" << endl;
    cout << "3) Player Two Fighter Input" << endl;
    cout << "4) Duke it out!" << endl;
    cout << "5) Exit" << endl;
    cout << endl;
    
}




/*********************************************************************
** Description: This function will implement the functionality of the 
** options presented by the printMenu() function.
*********************************************************************/
/*
void Game::menuFunctionality()
{
    seedRN();
    int monsterChoiceOne;
    int monsterChoiceTwo;    
    int rounds = 0;   
    char userInput;
    Creature* monsters[2];

    do
    {
		rounds = 0;
        // Clears the screen and prints the menu
        clearScreen();
        printMenu();
        
        cout << "1st Monster Choice: ";
        
        monsterChoiceOne = getInt();
    
		// Checks for invalid menu choice
        while ((monsterChoiceOne < 1) || (monsterChoiceOne > 5))
        {
            cout << endl << "Choice is not valid: Please choose 1-5.";
            cout << endl << "Choice: ";
            monsterChoiceOne = getInt();
        }
        
        cout << "2nd Monster Choice: ";
        
        monsterChoiceTwo = getInt();
		
		// Checks for invalid menu choice
        while ((monsterChoiceTwo < 1) || (monsterChoiceTwo > 5))
        {
            cout << endl << "Choice is not valid: Please choose 1-5.";
            cout << endl << "Choice: ";
            monsterChoiceTwo = getInt();
        }
        
        // Determines which fighter goes first
        int startingFighter = randomNum(2);
        
        // Sets the monster choices based on the starting fighter random
        if (startingFighter == 0)
        {
            monsters[0] = monsterChoice(monsterChoiceOne);
            monsters[1] = monsterChoice(monsterChoiceTwo);
        }
        else
        {
            monsters[0] = monsterChoice(monsterChoiceTwo);
            monsters[1] = monsterChoice(monsterChoiceOne);
        }
    
        
        // Loop that handles the monster fighting based on the living
		// status of each monster
        while (monsters[0]->living() and monsters[1]->living())
        {
			cout << "***********************************************" << endl;
			cout << "Round #" << rounds +1 << endl;
			
            cout << endl << "Attack: " << monsters[0]->getName() << endl;
            monsters[1]->defense(monsters[0]->attack());
            cout << "Remaining str for " << monsters[1]->getName() 
				 << " : " << monsters[1]->getStr() << endl;
            
            // Checks to see if the first attack of the round killed the 
            // second monster
            if (monsters[1]->living())
            {
                cout << endl << "Attack: " << monsters[1]->getName() << endl;
                monsters[0]->defense(monsters[1]->attack());
                cout << "Remaining str for " << monsters[0]->getName() 
                     << " : " << monsters[0]->getStr() << endl;
            }
            
            cout << endl;
            rounds++;
        }
        
		cout << "***********************************************" << endl;
		
		// Checks to see if monster 2 has died
        if (!monsters[1]->living())
        {
            cout << "Monster #1, " << monsters[0]->getName() 
				 << " is the winner!" << endl;
        }
        else
        {
            cout << "Monster #2, " << monsters[1]->getName() 
				 << " is the winner!" << endl;
        }
        

        cout << "The fight took " << rounds << " rounds." << endl;
        
        cout << "Play again? (y) or (n): ";
        cin >> userInput;
        
        cin.clear();
        cin.ignore(500, '\n');
        
        // Checks for invalid y or n user input
        while (userInput != 'y' and userInput != 'n')
        {
			cout << "Invalid choice. Please inputer either 'y' or 'n' " << endl;
			cout << "Play again? (y) or (n): ";
			cin >> userInput;
			cin.clear();
			cin.ignore(500, '\n');
		}
		
        delete monsters[0];
        delete monsters[1];
        
        monsters[0] = nullptr;
        monsters[1] = nullptr;
        
    } while (userInput != 'n');
    
}
*/
/*********************************************************************
** Description: This function takes in an int and uses a switch to 
** create and return a new object based on the choice.
*********************************************************************/
Creature* Game::monsterChoice(int choice)
{
    switch (choice)
        {
            case 1:
                return new Barbarian();
                break;
            case 2:
                return new Vampire();
                break;
            case 3:
                return new BlueMen();
                break;
            case 4:
                return new Medusa();
                break;
            case 5:
                return new HarryPotter();
                break;
            default:
                return nullptr;
        };
}

