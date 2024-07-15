#include "ExODU.h"
#include "endGame.h"
#include "ArtificialIntelligence.h"
#include <string>

// Human functionalities only
// This function will be revisited once checkPegs is functional
void ExODU::humanPlay(playerData& gamePlayer, boardData& gameBoard)
{
    // Variables
    int multipleChoice;

    cout << "Your turn.  You Rolled a " << roll << endl;

    // If the roll is 6 and there are pegs out at the moment
    // Give the human player an option to choose to move a peg out or move his or her respective peg
    if( (roll == 6) && (gamePlayer.getpegsOut(0) > 0) && (gamePlayer.getpegsOut(0) < 4) )
    {
        cout << "press 1 to move a peg to start" << endl;
        cout << "press 2 to move any other of your pegs" << endl;
        cin >> multipleChoice;
    }

    // If the roll is 6 (this takes priority over all functions given)
    // This function below only applies when there are no pegs out on the board
    if( (roll == 6) && (gamePlayer.getpegsOut(0) == 0))
    {
        // Variables
        int choice; // hold the variable based on the player's choice
        string tempPeg; // hold the pegs
        string tempHold;    // hold the current peg chosen

        // Input the string pegs into temporary
        tempPeg = gamePlayer.getpeg(0);

        cout << "press 1 to move a peg to start" << endl;
        cin >> choice;

        //Determine what the player what peg he or she wants to move
        if(choice == 1)
        {
            cout << "Enter the index of the peg you want to move" << endl;
            cout << "Available pegs are   : " << tempPeg[0] << " " << tempPeg[1] << " " << tempPeg[2] << " " << tempPeg[3] << endl;
            cin >> choice;
        }

        // Setting the board
        tempHold = tempPeg[choice-1]; // now hold the temporary value
        gameBoard.setBoard(0, tempHold); // set the current game board with this peg

        // Based on the player's choice, remove it from the box
        if(choice == 1)
            tempPeg[0] = ' ';
        else if(choice == 2)
            tempPeg[1] = ' ';
        else if(choice == 3)
            tempPeg[2] = ' ';
        else if(choice == 4)
            tempPeg[3] = ' ';

        // Now input the tempPeg to the actual pegs
        gamePlayer.setpeg(0, tempPeg);

        // Increment the amount of pegs out
        int tempNumber = gamePlayer.getpegsOut(0);
        tempNumber++;
        gamePlayer.setpegsOut(0, tempNumber);
    }

    // If the multiple choice is done
    // Do this function
    if( multipleChoice == 1 )
    {
        // Variables
        int choice; // hold the variable based on the player's choice
        string tempPeg; // hold the pegs
        string tempHold;    // hold the current peg chosen

        // Input the string pegs into temporary
        tempPeg = gamePlayer.getpeg(0);

        //Determine what the player what peg he or she wants to move
        cout << "Enter the index of the peg you want to move" << endl;
        cout << "Available pegs are   : " << tempPeg[0] << " " << tempPeg[1] << " " << tempPeg[2] << " " << tempPeg[3] << endl;
        cin >> choice;

        // Setting the board
        tempHold = tempPeg[choice-1]; // now hold the temporary value
        gameBoard.setBoard(0, tempHold); // set the current game board with this peg

        // Based on the player's choice, remove it from the box
        if(choice == 1)
            tempPeg[0] = ' ';
        else if(choice == 2)
            tempPeg[1] = ' ';
        else if(choice == 3)
            tempPeg[2] = ' ';
        else if(choice == 4)
            tempPeg[3] = ' ';

        // Now input the tempPeg to the actual pegs
        gamePlayer.setpeg(0, tempPeg);

        // Increment the amount of pegs out
        int tempNumber = gamePlayer.getpegsOut(0);
        tempNumber++;
        gamePlayer.setpegsOut(0, tempNumber);
    }

    // Once a peg is out of the box, go through this entire function (Always active)
    if(gamePlayer.getpegsOut(0) > 0)
    {
        // Variables used below
        string choice;
        string tempPeg;
        int position = 0;
        int homePosition = 0;
        int flag = 0;
        int homeFlag = 0;
        int movePeg;
        int tempRoll;

        // Display the current status of the board and generate a new roll
        generateRoll();
        gameBoard.display(gamePlayer, roll);

        // Display the next portion
        cout << "Your turn. You Rolled a " << roll << endl;
        cout << "press 1,2,3, or 4 to move your respective peg (peg must be moved to start first-can only be done by rolling a six)" << endl;
        cin >> choice;

        // Scan the board based on the choice given and move that peg based on the roll
        // and increment the position
        for(int i = 0; i < 40; i++)
        {
            if(gameBoard.getBoard(i) == choice)
            {
                tempPeg = gameBoard.getBoard(i);
                flag = 1;
            }

            if(flag == 0)
                position++;
        }

        // Scan the home positions and increment the home positions
        flag = 0;
        for(int i = 0; i < 4; i++)
        {
            if(gameBoard.getplayerEnd(i) == choice)
            {
                tempPeg = gameBoard.getplayerEnd(i);
                flag = 1;
                homeFlag = 1;   // this is used if the peg is inside home and will skip a function later
            }

            if(flag == 0)
                homePosition++;
        }

        // Move the peg one space at a time (one space)
        // Roll will stay the same
        // tempRoll will decrement every space moved
        int calculateTempRoll;
        int doNotMove = 0;

        // pesky pegs can be hidden and must be moved accordingly
        moveHidden(gamePlayer, gameBoard, doNotMove, homeFlag, choice, roll, NULL, 1);

        // calculation stuff to determine when going out of scope with the board array
        calculateTempRoll = 40 - position;
        tempRoll = roll - calculateTempRoll;
        movePeg = position + roll; // This will get the current location and add the roll

        /*
            - Check to make sure the peg does not go out of bounds with the array
            - If it does, move the peg into the home position
                but first check to make sure there is enough space to roll
            - This function will only be done once if the peg is not at home
        */

        if( (movePeg > 39) && (homeFlag == 0) )
        {
            int taken = 0;
            string holdItem;

            // Check if the spot is not taken (refer to homeFlag ==1 function)
            // tempRoll is used because it is exactly on spot
            // check ahead first
            if(tempRoll < 4)
            {
                holdItem = gameBoard.getplayerEnd(tempRoll);

                if(holdItem == "0")
                    taken = 0;  // Free
                else taken = 1; //Nope
            }


            if(taken == 0)
            {
                // Set it to the location and delete the previous location
                gameBoard.setplayerEnd(tempRoll, tempPeg);
                gameBoard.setBoard(position, "*");
                doNotMove = 1;
            }
            else
            {
                // Not enough? Tell the user
                cout << "There is not enough space to enter" << endl;
                doNotMove = 1;
            }
        }

        // if homeFlag == 1, move ONLY inside the home for the peg
        // check to make sure the roll is less than what it needs to be
        // use roll and homePosition

        if( homeFlag == 1 )
        {
            int doIMove = 0; // flag
            int shouldIReallyMove = 0; // flag
            int homeMove; //temporary
            int checkAhead; // spot checking
            string holdItem;

            // even though these two variables are the same numbers
            // they both have different uses and will not be messed up what
            // the function or calculation is used for different purposes
            homeMove = homePosition + roll;
            checkAhead = homePosition + roll;

            // Make sure that the roll does not go out of scope with the playerEnd array
            if(checkAhead < 4)
                doIMove = 0; // It is fine
            else doIMove = 1;   // No no no, do not move the peg

            if( doIMove == 0 )
            {
                // check the peg to make sure it doesn't land on top of each other
                holdItem = gameBoard.getplayerEnd(checkAhead);

                if(holdItem == "0")
                    shouldIReallyMove = 0; //YES!
                else shouldIReallyMove = 1; // NO...

                if(shouldIReallyMove == 0)
                {
                    gameBoard.setplayerEnd(homeMove, tempPeg);  // move the peg to the new position
                    gameBoard.setplayerEnd(homePosition, "0");  // delete the last position

                    doNotMove = 1;
                }
                else cout << "There is not enough space to move in home." << endl;
            }

            if( doIMove == 1)
                doNotMove = 1;
        }

        // If all else fails, peg will be moved
        if(doNotMove == 0)
        {
            // Based on the position given and what peg the player wants to move, move it based on the given roll
            checkPegs(gamePlayer, gameBoard, tempPeg, roll, 1);
            gameBoard.setBoard(movePeg, tempPeg);

            // Delete the old position and replace it with an asterisk
            gameBoard.setBoard(position, "*");
        }
    }

        /// END OF THE ENTIRE FUNCTION
}

// This will always be called before the actual peg is moved
// this function is used only for the human player in the ExODU humanPlay function
void ExODU::checkPegs(playerData& checkPlayer, boardData& checkBoard, string choice, int roll, int player)
{
    int ignore = 0;
    int flag = 0;
    int position = 0;
    string tempPeg, aheadPeg;    // holding variable
    int checkAhead; // used to get position + roll

    if(player==1)
    {
        // get the position of what peg will be moving and hold it as a tempPeg (used throughout the entire function)
        for(int i = 0; i < 40; i++)
        {
            if(checkBoard.getBoard(i) == choice)
            {
                tempPeg = checkBoard.getBoard(i);
                flag = 1;
            }

            if(flag == 0)
                position++;
        }
        // Check on the position of where the peg will be moving to
        checkAhead = position + roll;

        for(int i = 0; i < 40; i++)
        {
            // if the board piece is not a peg
            if(checkBoard.getBoard(checkAhead) != "*")
            {
                // get the peg from that position
                aheadPeg = checkBoard.getBoard(checkAhead);
                ignore = 0;
            }
            // else set ignore = 1;
            else ignore = 1;
        }
    }

    /*
        By using the tempPeg and aheadPeg, we can compare the two strings to check if they are a team member
        or if they are not. Based on what it is, do the following below.

        If ignore = 0 then do the following if statement below
        If ignore = 1, then skip the if statement below
    */

    if(ignore == 0)
    {
        string holdTempItem;
        int ignoreKill = 0;

        // Check if the peg is on the same team
        // If the peg is on the same team, move it to tempBoard
        // Based on the user choice of what peg is moving
        // Have to make separate statements for every peg
        /*
            A bunch of if statements will determine if the aheadPeg is on the same team
            If the peg that ahead is on the same time, the ignoreKill will set to 1 - means that the function after this will be skipped
        */
        if(player == 1) // human player
            if(aheadPeg == "1")
            {
                holdTempItem = checkBoard.gettempBoard(checkAhead); // Take out the temporary board by using check ahead (the exact position the peg is supposed to land on)
                ignoreKill = 1;
            }
            else if(aheadPeg == "2")
            {
                holdTempItem = checkBoard.gettempBoard(checkAhead);
                ignoreKill = 1;
            }
            else if(aheadPeg == "3")
            {
                holdTempItem = checkBoard.gettempBoard(checkAhead);
                ignoreKill = 1;
            }
            else if(aheadPeg == "4")
            {
                holdTempItem = checkBoard.gettempBoard(checkAhead);
                ignoreKill = 1;
            }
            else ignoreKill = 0;

        // Now scan the tempBoard for a spot to use as a holding place
        int tempBoardFlag = 0;
        for(int i = 0; i < 3; i++)
        {
            if( (holdTempItem[i] == '*') && (tempBoardFlag==0) )
            {
                holdTempItem[i] = aheadPeg[0]; // move the peg that was ahead
                tempBoardFlag = 1;  // say this loop is done
                checkBoard.settempBoard(checkAhead, holdTempItem); //input it back to the board
            }
        }

        // If the peg is an enemy
        // Kill it and the killed peg will return to its respective owner
        // Based on the player number, each will have its own function
        if(ignoreKill == 0)
        {
            if(player == 1) // if the player is human, do this entire function
            {
                int done = 0;
                string holdPegBox;
                int tempCount;

                // If the peg does not belong to player 1, kill it and send that peg back to its owner
                // now depending on who the peg belongs to, send it back to the owner
                // decrement the amount of pegs out on the board for that player
                if(aheadPeg == "g") // if green
                {
                    holdPegBox = checkPlayer.getpeg(1);

                    // now scan the holdPegBox for any available spot to take
                    for(int i = 0; i < 4; i++)
                        if( (holdPegBox[i] == ' ') && (done == 0) )
                        {
                            holdPegBox[i] = aheadPeg[0];
                            done = 1;
                        }
                        else done = 0; // keep searching


                    // decrement the total pegs out for green
                    tempCount = checkPlayer.getpegsOut(1);
                    tempCount--;
                    checkPlayer.setpegsOut(1, tempCount);

                    // Now check the tempBoard for any pegs hidden
                    string holdTempBoard;
                    int shouldIDelete = 0;

                    holdTempBoard = checkBoard.gettempBoard(checkAhead);

                    for(int i = 0; i < 3; i++)
                    {
                        shouldIDelete = 0;
                        done = 0;

                        // every time there is a peg in the tempBoard, set done = 0 so that it can remove the peg from
                        // the temp board and put it back in the pegBox
                        if(holdTempBoard[i] == 'g')
                        {
                            holdTempBoard[i] = '*';

                            tempCount = checkPlayer.getpegsOut(1);
                            tempCount--;
                            checkPlayer.setpegsOut(1, tempCount);
                        }
                        else
                        {shouldIDelete = 1; done = 1;}

                        // now scan the holdPegBox for any available spot to take
                        if(shouldIDelete = 0)
                            for(int j = 0; j < 4; j++)
                                if( (holdPegBox[j] == ' ') && (done = 0) )
                                {
                                    holdPegBox[j] = 'g';
                                    done = 1;
                                }else done = 0;
                    } // end for statement

                    // put the pegs back in the box
                    checkPlayer.setpeg(1, holdPegBox);

                } // ends the entire if statement for green peg
                else if(aheadPeg == "r") // if red
                {
                    holdPegBox = checkPlayer.getpeg(2);

                    // now scan the holdPegBox for any available spot to take
                    for(int i = 0; i < 4; i++)
                        if( (holdPegBox[i] == ' ') && (done == 0) )
                        {
                            holdPegBox[i] = aheadPeg[0];
                            done = 1;
                        }
                        else done = 0; // keep searching


                    // decrement the total pegs out for green
                    tempCount = checkPlayer.getpegsOut(2);
                    tempCount--;
                    checkPlayer.setpegsOut(2, tempCount);

                    // Now check the tempBoard for any pegs hidden
                    string holdTempBoard;
                    int shouldIDelete = 0;

                    holdTempBoard = checkBoard.gettempBoard(checkAhead);

                    for(int i = 0; i < 3; i++)
                    {
                        shouldIDelete = 0;
                        done = 0;

                        // every time there is a peg in the tempBoard, set done = 0 so that it can remove the peg from
                        // the temp board and put it back in the pegBox
                        if(holdTempBoard[i] == 'r')
                        {
                            holdTempBoard[i] = '*';

                            tempCount = checkPlayer.getpegsOut(2);
                            tempCount--;
                            checkPlayer.setpegsOut(2, tempCount);
                        }
                        else
                        {shouldIDelete = 1; done = 1;}

                        // now scan the holdPegBox for any available spot to take
                        if(shouldIDelete = 0)
                            for(int j = 0; j < 4; j++)
                                if( (holdPegBox[j] == ' ') && (done = 0) )
                                {
                                    holdPegBox[j] = 'r';
                                    done = 1;
                                }else done = 0;
                    } // end for statement

                    // put the pegs back in the box
                    checkPlayer.setpeg(2, holdPegBox);
                    checkPlayer.setpegsOut(2, tempCount);
                }
                else if(aheadPeg == "b") // if blue
                {
                    holdPegBox = checkPlayer.getpeg(3);

                    // now scan the holdPegBox for any available spot to take
                    for(int i = 0; i < 4; i++)
                        if( (holdPegBox[i] == ' ') && (done == 0) )
                        {
                            holdPegBox[i] = aheadPeg[0];
                            done = 1;
                        }
                        else done = 0; // keep searching


                    // decrement the total pegs out for green
                    tempCount = checkPlayer.getpegsOut(3);
                    tempCount--;
                    checkPlayer.setpegsOut(3, tempCount);

                    // Now check the tempBoard for any pegs hidden
                    string holdTempBoard;
                    int shouldIDelete = 0;

                    holdTempBoard = checkBoard.gettempBoard(checkAhead);

                    for(int i = 0; i < 3; i++)
                    {
                        shouldIDelete = 0;
                        done = 0;

                        // every time there is a peg in the tempBoard, set done = 0 so that it can remove the peg from
                        // the temp board and put it back in the pegBox
                        if(holdTempBoard[i] == 'b')
                        {
                            holdTempBoard[i] = '*';

                            tempCount = checkPlayer.getpegsOut(3);
                            tempCount--;
                            checkPlayer.setpegsOut(3, tempCount);
                        }
                        else
                        {shouldIDelete = 1; done = 1;}

                        // now scan the holdPegBox for any available spot to take
                        if(shouldIDelete = 0)
                            for(int j = 0; j < 4; j++)
                                if( (holdPegBox[j] == ' ') && (done = 0) )
                                {
                                    holdPegBox[j] = 'b';
                                    done = 1;
                                }else done = 0;
                    } // end for statement

                    // put the pegs back in the box
                    checkPlayer.setpeg(3, holdPegBox);
                }
            }// end player 1 statement
        }
    }//end ignore statement
}

// If the peg is not on the board, check the hidden board
// Since the function will be used for both human and AIs, the player if statement will separate it
void ExODU::moveHidden(playerData& hiddenPlayer, boardData& hiddenBoard, int &flag1, int &flag2, string choice, int roll, int botPosition, int player)
{
    // if player = 1, human stuff
    if(player == 1)
    {
        int position = 0;
        int stopCount = 0;
        int ignore = 0;

        // First, check the main board and set ignore = 1 if the peg is on the main board
        for(int i = 0; i < 40; i++)
            if(hiddenBoard.getBoard(i) == choice)
                ignore = 1;

        // check the home board to make sure that it isn't there
        // THIS WILL ALWYS IGNORE THE FUNCTION BELOW!!! Pegs cannot be stacked at home
        for(int i = 0; i < 4; i++)
            if(hiddenBoard.getplayerEnd(i) == choice)
                ignore = 1;

        // move the hidden peg if ignore = 0
        if(ignore == 0)
        {
            int skip = 0;
            string tempPeg; // hold only the peg
            string holdItem;    // hold the entire array block

            // grab the hidden peg
            for(int i = 0; i < 40; i++)
            {
                // each block in the array must be scanned individually
                // but skip if the entire block equals to "***" - this is to speed up the process
                // also increment the position based on how many times it scans
                if(hiddenBoard.gettempBoard(i) == "***")
                    skip = 1;
                else skip = 0;

                if(skip == 0)
                {
                    // grab the hidden peg based on user's choice
                    holdItem = hiddenBoard.gettempBoard(i);

                    char check;
                    check = choice[0];
                    // convert the choice to char

                    // now scan each item in holdItem
                    for(int j = 0; j < 3; j++)
                    {
                        if(holdItem[j] == check)
                        {
                            // hold that peg
                            tempPeg = holdItem[j];
                            stopCount = 1;

                            // replace that peg with an asterisk
                            holdItem[j] = '*';
                        }
                    }
                }

                if(stopCount == 0)
                    position++;

                if(stopCount == 1)
                    hiddenBoard.settempBoard(position, holdItem);

            } // end the entire loop

            // now the tempPeg will be moved
            // first scan the board ahead
            int scanAhead = 0;
            int movePeg = 0;
            scanAhead = position + roll;
            movePeg = position + roll;

            // the peg will be moved in this function instead
            if(scanAhead >= 40)
            {
                flag1 = 1; // ignore the movement as well in the humanPlay
                flag2 = 1; // the flag for home in the humanPlay
            }

            /*
                Inside this function, flag1 is movement on the main board, flag2 is when the flag past out of scope array
                For these two flags, think opposite when the scanAhead is over
            */

            // move the peg
            // if the peg is on the temp board, move it accordingly
            if(flag1 == 0)
            {
                checkPegs(hiddenPlayer, hiddenBoard, tempPeg, scanAhead, player);  // the peg will still be checked if it needs to stack again or kill
                hiddenBoard.setBoard(movePeg, tempPeg); // move the peg
                flag1 = 1; // to set the doNotMove value in the play (this is already done here)
                flag2 = 2; // this is set to 2 so it does not interact with the function here, and does not interact with the function in the human play
            }

            // if the peg is going to home, move it accordingly
            if(flag2 == 1)
            {
                // calculation for roll
                int calculation;
                int tempRoll;

                calculation = 40 - position;
                tempRoll = roll - calculation;



                // check if the spot is taken
                if(scanAhead > 39)
                {
                    int taken = 0;
                    string hold;

                    if( tempRoll < 4)
                    {
                        hold = hiddenBoard.getplayerEnd(tempRoll);

                        if(hold == "0")
                            taken = 0;
                        else taken = 1;
                    }

                    if(taken == 0)
                    {
                        // Set it to the location and delete the previous location
                        hiddenBoard.setplayerEnd(tempRoll, tempPeg);
                        hiddenBoard.setBoard(position, "*");
                    }
                    else
                    {
                        // Not enough? Tell the user
                        cout << "There is not enough space to enter" << endl;
                    }
                }
            }// end flag2
        }// end if(gnore =- ? )
    }// end if statement
} // end of moveHidden function

// The game will be played
void ExODU::playGame()
{
    // Class objects
    playerData myplayer;
    boardData myboard;
    ArtificialIntelligence myAI;
    endGame mygame;

    // Initializing the entire game
    myplayer.createName();  // Create the starting names for the human player and three computers
    myplayer.createPegs();  // Create the starting pegs for the human player and three computers
    myplayer.createPegsOut(); // All pegs currently out are none (0)
    myboard.createBoard();  // Create the starting board

    // THis is ignored completely as it will only be used when the player presses the enter key
    string enter;

    // The game will be actually played in this while loop
    // The flag will change accordingly based on who has four pegs in home
    do
    {

        generateRoll(); // Roll the dice
        myboard.display(myplayer, roll);    // display the board
        humanPlay(myplayer, myboard);    // algorithms and stuff will be here based on human

        cout << "Press Enter to Continue";
        getline(cin, enter);

        // computer turns
        myAI.greenPlay(myplayer, myboard);
        myAI.redPlay(myplayer, myboard);
        myAI.bluePlay(myplayer, myboard);

        // flag checking
        mygame.checkHomeSpace(myboard, flag);   // check if four pegs are in any home
    }while(flag == 0);

    // Display the board one last time
    cout << endl << endl << endl;
    myboard.display(myplayer, roll);

    // based on what flag is set, display the winner
    if(flag == 1)
        cout << "\nGame Over - Player : 1 Wins!\n";
    else if(flag == 2)
        cout << "\nGame Over - Player : 2 Wins!\n";
    else if(flag == 3)
        cout << "\nGame Over - Player : 3 Wins!\n";
    else if(flag == 4)
        cout << "\nGame Over - Player : 4 Wins!\n";

    /// Testing Only
/*
    // To test the dowhile loop with certain functions
    string enter;
    do
    {
        myboard.setBoard(roll-1, "*");  // to remove the old place
        generateRoll();
        myboard.setBoard(roll-1, "1");  // to set the new place
        myboard.display(myplayer, roll);    // display the board
        cout << "Your turn.  You Rolled a " << roll << endl;
        cin >> enter;
        flag = 1;
    }while(flag == 0);

    if(flag == 1)
        cout << "\nPlayer 1 Wins!\n";

    // To read the string length and stuff
    int length;     // get the size of the string
    string tempPeg; // temporary holding string for the peg
    char output;    // to output a single character at a time
    tempPeg = myplayer.getpeg(0);   // tempPeg will hold myplayer
    length = tempPeg.length();  // length will get the size of the string
    cout << tempPeg << " pegs. Has a total of " << length << " numbers" << endl;    // display tempPeg and show the size of the length
    for(int i = 0; i < length; i++) // input an individual tempPeg string to the output and then display it
    {
        output = tempPeg[i];
        cout << output << " ";
    }
    cout << endl;

    // Check if something match in a string and then change the value of it to a space
    for(int i = 0; i < length; i++)
    {
        if(tempPeg[i] == '2')
        {
            tempPeg[i] = ' ';
            cout << "tempPeg: " << tempPeg << endl;
        }
    }
    // Since tempPeg is only a temporary string, input it back to the actual peg
    myplayer.setpeg(0, tempPeg);
    cout << "getPeg: " << myplayer.getpeg(0); // display the results

    myboard.setBoard(15, "2");
    myboard.setBoard(30, "r");

    generateRoll();
    myboard.display(myplayer, roll);


    cout << endl;
    // See if all pegs are in the pegs array (WORKING OKAY!)
    for(int i = 0; i < 4; i++)
        cout << "Player " << myplayer.getname(i) << " with pegs " << myplayer.getpeg(i) << endl;

    cout << endl;
    for(int i = 0; i < 40; i++)
        cout << myboard.getBoard(i);

    cout << endl;
    for(int i = 0; i < 4; i++)
        cout << myboard.getplayerEnd(i) << myboard.getgreenEnd(i) << myboard.getblueEnd(i) << myboard.getredEnd(i);

    cout << endl;
    generateRoll();
    cout << "Your roll is: " << roll;
*/

    return;
}
