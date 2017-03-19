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
    northCorridor = new Corridor(nullptr,nullptr,nullptr,nullptr,"North Corridor");
    westCorridor = new Corridor(nullptr,nullptr,nullptr,nullptr,"West Corridor");
	southCorridor = new Corridor(nullptr,nullptr,nullptr, nullptr, "South Corridor");
	eastCorridor = new Corridor(nullptr,nullptr,nullptr,nullptr,"East Corridor");
    cryoRoom = new CryoChamber(southCorridor, nullptr, nullptr, nullptr, "Cryo Chamber");
    commonArea = new CommonRoom(northCorridor,eastCorridor,southCorridor,westCorridor, "Common Area");
    storageRoom = new StorageRoom(nullptr,westCorridor,nullptr,nullptr, "Storage Room");
    cockpit = new Cockpit(nullptr,nullptr,northCorridor,nullptr, "Cockpit");
    airlock = new Airlock(nullptr,nullptr,nullptr,eastCorridor,"Airlock");
    
    
    northCorridor -> setDirectionPointer(commonArea, DOWN);
    northCorridor -> setDirectionPointer(cockpit, UP);
    westCorridor -> setDirectionPointer(commonArea, RIGHT);
    westCorridor -> setDirectionPointer(storageRoom, LEFT);
    southCorridor -> setDirectionPointer(cryoRoom, DOWN); 
    southCorridor -> setDirectionPointer(commonArea, UP);
    eastCorridor -> setDirectionPointer(commonArea, LEFT);
    eastCorridor -> setDirectionPointer(airlock, RIGHT);
    currentRoom = cryoRoom;
}

/*********************************************************************
** Description: Destructor that will delete the the allocated memory
** for the Spaces.
*********************************************************************/
Game::~Game()
{
    delete cryoRoom;
    cryoRoom = nullptr;
    delete cockpit;
    cockpit = nullptr;
    delete commonArea;
    commonArea = nullptr;
    delete storageRoom;
    storageRoom = nullptr;
    delete airlock;
    airlock = nullptr; 
    delete westCorridor;
    westCorridor = nullptr;
    delete northCorridor;
    northCorridor = nullptr;
	delete southCorridor;
    southCorridor = nullptr;
    delete eastCorridor;
    eastCorridor = nullptr;
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
    cout << endl << "The game's background is that you (the player) wake up in a cryo chamber " << endl
                 << "on a spaceship with no knowledge of what's going on around you. The" << endl
                 << "intended goal is to repair various parts of the ship in order to use the" << endl
                 << "FTL (Faster Than Light) drive to escape the event horizon of a Black Hole." << endl;
    cout << endl << endl;
    printStartingScene();
    cout << endl << endl;
    pauseScreen();
}


/*********************************************************************
** Description: Method that will print the starting scene information.
*********************************************************************/
void Game::printStartingScene()
{
    printColor("Game Introduction - The Starting Scene\n",YELLOW, BOLD);
    cout << "You wake up in a cryo pod. Through the tiny viewport at eye level, you can see" << endl;
    cout << "red lights flashing in an otherwise dark room. Knowing that you need to get" << endl;
    cout << "out of the pod, you search the interior and see a button near your left shoulder." << endl;
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
    printColor("******************************", RED, BOLD);
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
				changeRooms();
				pauseScreen();
				break;
			// Perform Special Action
			case 2:
				performSpecialAction();
				pauseScreen();
				break;
			// Check Player Inventory
			case 3:
                player.printInventory();
                pauseScreen();
				break;
            // Pick up an item in the room
            case 4:
				getItemFromRoom();
                pauseScreen();
                break;
            // Use item from inventory
            case 5:             
				useItem();
                pauseScreen();
                break;
		}	
        clearScreen();
	} while (true);
}

/*********************************************************************
** Description: Method that will print the available spaces connected
** to the current space and then change the current room to the user
** selection
*********************************************************************/
void Game::changeRooms()
{
    unsigned int userInput = 0;
	vector<Space*> availableRooms;
    Space* userChoice = nullptr;
    
    // Populates the vector with the current room's connected spaces
	currentRoom -> fillSpaceVector(&availableRooms);
    
	printColor("******************************\n", RED, BOLD);
	printColor("Connected Spaces\n",CYAN,BOLD);
	
	for (unsigned int x = 0; x < availableRooms.size(); x++)
	{
		cout << x + 1 << ") " << availableRooms.at(x) -> getName() << endl;
	}
    
	cout << endl;	
    printColor("Choice: ", YELLOW, NORMAL);
    userInput = getInt();
    
    while (userInput < 1 or userInput > availableRooms.size())
    {
        cout << endl << "Choice is not valid: Please choose 1-" << availableRooms.size() << ".";
        cout << endl << "Choice: ";
        userInput = getInt();
    }
    
    
    userChoice = availableRooms.at(userInput -1);   
    // Checks with the current room to see if a space change is possible
    if (currentRoom -> canChangeRooms(userChoice))
    {
        currentRoom = availableRooms.at(userInput -1);
        printColor("The door slides open with a whine from disuse. You step into the next room\n",GREEN,BOLD);
        printColor("and the door grinds to a close behind you...\n",GREEN,BOLD);
    }
    else
    {
        cout << endl;
        printColor("Something is preventing you from changing rooms, try exploring the room first\n",RED,BOLD);
    }
}

/*********************************************************************
** Description: Method that will perform the room's special action.
** There is a check in case the player tries to depressurize the 
** airlock while not wearing the pressure suit.
*********************************************************************/
void Game::performSpecialAction()
{
	if (currentRoom -> getName() == "Airlock" and !(player.pressureSuitEquipped()))
	{
		printColor("Without a pressure suit, cycling the airlock will kill you. Find\n",RED,BOLD);
		printColor("a pressure suit to proceed to the Cargo Hold.\n",RED,BOLD);
	}
	else
	{					
		currentRoom -> specialAction();
	}
}

/*********************************************************************
** Description: Method that will attempt to pickup an item from the
** current room.
*********************************************************************/
void Game::getItemFromRoom()
{
	// Special first case to let the player get the pressure suit
	if (currentRoom -> getName() == "Cryo Chamber")
	{
		player.pickUpItem(currentRoom -> getItem());
	}
	// If the player has the suit equipped, get the item.
	else if (player.pressureSuitEquipped())
	{
		player.pickUpItem(currentRoom -> getItem());
	}
	else
	{
		printColor("You aren't wearing anything with pockets!\n",RED,BOLD);
	}
}

/*********************************************************************
** Description: Method that will attempt to use an item in the player's
** inventory in the current room. Various checks are performed to 
** determined if any of the items can be used in that room.
*********************************************************************/
void Game::useItem()
{
	if(currentRoom -> canUseItems())
	{
		if (player.inventorySize() == 0)
		{
			player.printInventory();
		}
		else
		{						
			unsigned int playerInvChoice = 0;
			player.printInventory();
			printColor("Choice: ", YELLOW, NORMAL);

			playerInvChoice = getInt();
			
			while (playerInvChoice < 1 or (playerInvChoice > player.inventorySize()))
			{
				cout << endl << "Choice is not valid: Please choose 1-" << player.inventorySize() << ".";
				cout << endl << "Choice: ";
				playerInvChoice = getInt();
			}
			
			/* This block of code will take an item off the player's inventory and
			 * push it to the current room to see if the item is used in that room.
			 * If it is not, the item will be pushed back onto the player's inventory.
			 */
			Item* tempItem = player.removeItem(playerInvChoice);
			if (!(currentRoom -> placeItem(tempItem)))
			{
				printColor("This item is not used in this room.\n",RED,BOLD);
				player.pickUpItem(tempItem);
			}

			tempItem = nullptr;						
		}                 
	}
	else
	{
		printColor("None of your items are needed in this room.\n", RED, BOLD);
	}
}
