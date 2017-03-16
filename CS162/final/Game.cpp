/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the Game class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Game.hpp"

/*********************************************************************
** Description: Constructor that will initialize and allocate memory
** for all the appropriate Spaces.
*********************************************************************/
Game::Game()
{
    cryoRoom = new CryoChamber(nullptr, nullptr, nullptr, nullptr, "Cryo Chamber");
    currentRoom = cryoRoom;
}

/*********************************************************************
** Description: Destructor that will delete the the allocated memory
** for the Spaces.
*********************************************************************/
Game::~Game()
{
    delete cryoRoom;
}

/*********************************************************************
** Description: Public method that will handle the main functionality
** of the game including the primary loop, changing rooms, etc.
*********************************************************************/
void Game::play()
{
    clearScreen();
    printBanner();
    printGameDesc();
    primaryDecisionLoop();
}

/*********************************************************************
** Description: Method that will be printed right after the banner
** and will give the description of the game and the goal.
*********************************************************************/
void Game::printGameDesc()
{
    cout << endl << endl;
    cout << "This game is the final project for CS162, written by Ryan McGinn. " << endl;
    cout << endl << "The game's background is that you (the player) wakes up in a cryo chamber " << endl
                 << "on a spaceship with no knowledge of what's going on around you. The" << endl
                 << "intended goal is to repair various parts of the ship in order to use the" << endl
                 << "FTL (Faster Than Light) drive to escape the event horizon of a Black Hole." << endl;
    cout << endl << endl;
    pauseScreen();
}


/*********************************************************************
** Description: Method that will print the starting scene information.
*********************************************************************/
void Game::printStartingScene()
{
    cout << "You wake up in a cryo pod. Through the tiny glass at eye level, you can see" << endl;
    cout << "red lights flashing in an otherwise dark room. Knowing that you need to get" << endl;
    cout << "out of the pod, you search the interior and see a button near your left shoulder" << endl;
    cout << "The button is labeled but your eyes can't quite focus on the writing. Finding" << endl;
    cout << "nothing else, you press the button and see the pod's hatch swing up and out of" << endl;
    cout << "the way. You peel yourself out of the pod and step onto the cold floor. Taking" << endl;
    cout << "your first real look at your surroundings, you need to decide what the next move is..." << endl;
}


/*********************************************************************
** Description: Method that will print the banner (title) of the game.
** ASCII Art obtained from http://patorjk.com/software/taag
*********************************************************************/
void Game::printBanner()
{
    string b1 = " _____                                _    _            ______  _               _      _   _         _       ";
    string b2 = "|  ___|                              | |  | |           | ___ \\| |             | |    | | | |       | |     ";
    string b3 = "| |__  ___   ___  __ _  _ __    ___  | |_ | |__    ___  | |_/ /| |  __ _   ___ | | __ | |_| |  ___  | |  ___";
    string b4 = "|  __|/ __| / __|/ _  ||  _ \\  / _ \\ | __||  _ \\  / _ \\ | ___ \\| | / _  | / __|| |/ / |  _  | / _ \\ | | / _ \\";
    string b5 = "| |___\\__ \\| (__| (_| || |_) ||  __/ | |_ | | | ||  __/ | |_/ /| || (_| || (__ |   <  | | | || (_) || ||  __/";
    string b6 = "\\____/|___/ \\___|\\__ _||  __/  \\___|  \\__||_| |_| \\___| \\____/ |_| \\__ _| \\___||_|\\_\\ \\_| |_/ \\___/ |_| \\___|";
    string b7 = "                       | |                                                                                   ";
    string b8 = "                       |_|                                                                                   ";
    
    cout << b1 << endl << b2 << endl << b3 << endl << b4 << endl << b5 << endl << b6 << endl << b7 << endl << b8 << endl;
}

/*********************************************************************
** Description: Method that will print the initial options to the user.
** Additional menus will be spawned/printed based on the initial choice.
*********************************************************************/
void Game::printUserInputMenu()
{
    cout << endl;
    printColor("*******************", RED, BOLD);
    cout << endl;
    printColor("What will you do?", CYAN, BOLD);
    cout << endl;
    cout << "1) Change Rooms" << endl;
    cout << "2) Perform Room Special Action" << endl;
    cout << "3) Check Inventory" << endl;
    cout << "4) Pick up item" << endl;
    cout << "5) Use Item" << endl;
    
}

/*********************************************************************
** Description: Method that will print the banner (title) of the game.
** ASCII Art obtained from http://patorjk.com/software/taag
*********************************************************************/
void Game::primaryDecisionLoop()
{
    clearScreen();
    printStartingScene();
    
    int userInput = 0;	
	
	do
	{   
        cout << endl;
        printColor("Current Location: ", RED, BOLD);
		cout << currentRoom -> getName();
        cout << endl;
        currentRoom -> displayDesc();
        printUserInputMenu();
		printColor("Choice: ", YELLOW, NORMAL);
		
		userInput = getInt();
		
		while (userInput < 1 or userInput > 5)
        {
            cout << endl << "Choice is not valid: Please choose 1-5.";
            cout << endl << "Choice: ";
            userInput = getInt();
		}	
        switch (userInput)
        {
			// Change Rooms
			case 1:	
				pauseScreen();
				break;
			// Perform Special Action
			case 2:
                currentRoom -> specialAction();
				pauseScreen();
				break;
			// Check Player Inventory
			case 3:
                player.printInventory();
                pauseScreen();
				break;
            // Pick up item in room
            case 4:
                pauseScreen();
                break;
            // Use item from inventory
            case 5:
                
                pauseScreen();
                break;
		}	
        clearScreen();
	} while (userInput != 10);
}
