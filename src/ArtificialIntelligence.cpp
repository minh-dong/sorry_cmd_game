#include "ArtificialIntelligence.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

// function for checking AIs and human on the main board
// the &flag is used to change the value of flag if something happens, like if the peg belongs to the same player, do not move it.
void ArtificialIntelligence::AIcheck(playerData& AIplayer, boardData& AIboard, int roll, int checkAhead, int player)
{
    if(player == 2)
    {
        string holdPeg;
        string holdPlayerBox;
        int totalPegsOut;

        string enter;

        // by using the position (current) and checkAhead (to see what's ahead of them), test that position to see what it is
        if(AIboard.getBoard(checkAhead) != "*")
        {
            //check the peg there
            holdPeg = AIboard.getBoard(checkAhead); // hold the current peg

            // now test to see who the peg belongs to
            if( (holdPeg == "1") || (holdPeg == "2") || (holdPeg == "3") || (holdPeg == "4") )
            {
                holdPlayerBox = AIplayer.getpeg(0);
                totalPegsOut = AIplayer.getpegsOut(0);

                // peg is killed and message will be displayed to user
                if(holdPeg == "1")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[0] = '1';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 1 peg has been killed by a green peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "2")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[1] = '2';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 2 peg has been killed by a green peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "3")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[2] = '3';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 3 peg has been killed by a green peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "4")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[3] = '4';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 4 peg has been killed by a green peg. Press Enter to Continue.";
                    getline(cin, enter);
                }

                // make sure to check the temp Board for any stacked pegs
                if(AIboard.gettempBoard(checkAhead) != "***")
                {
                    string holdTempBoard;
                    holdTempBoard = AIboard.gettempBoard(checkAhead);

                    // scan each individual spot
                    for(int i = 0; i < 3; i++)
                    {
                        holdPlayerBox = AIplayer.getpeg(0);
                        totalPegsOut = AIplayer.getpegsOut(0);

                        if(holdTempBoard[i] != '*')
                        {
                            holdPeg = holdTempBoard[i];

                            if(holdPeg == "1")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[0] = '1';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 1 peg has been killed by a green peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "2")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[1] = '2';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 2 peg has been killed by a green peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "3")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[2] = '3';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 3 peg has been killed by a green peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "4")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[3] = '4';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 4 peg has been killed by a green peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                        } //end checking certain spots
                    }// end loop
                    // replace the entire spot with asterisks

                    AIboard.settempBoard(checkAhead, "***");

                } // end killing on tempBoard

            } // end killing human peg

            // check for red peg
            if(holdPeg == "r")
            {
                holdPlayerBox = AIplayer.getpeg(2);
                totalPegsOut = AIplayer.getpegsOut(2);

                // test for a position to put the peg in a spot
                int done = 0;

                for(int i = 0; i < 4; i++)
                {
                    if( (holdPlayerBox[i] == ' ') && (done == 0) )
                    {
                        holdPlayerBox[i] == 'r';
                        totalPegsOut--;
                        AIplayer.setpegsOut(2, totalPegsOut);
                        AIplayer.setpeg(2, holdPlayerBox);
                        done = 1;
                    }
                }
            } // end for holdPeg == "r"

            if(holdPeg == "b")
            {
                holdPlayerBox = AIplayer.getpeg(3);
                totalPegsOut = AIplayer.getpegsOut(3);

                // test for a position to put the peg in a spot
                int done = 0;

                for(int i = 0; i < 4; i++)
                {
                    if( (holdPlayerBox[i] == ' ') && (done == 0) )
                    {
                        holdPlayerBox[i] == 'b';
                        totalPegsOut--;
                        AIplayer.setpegsOut(3, totalPegsOut);
                        AIplayer.setpeg(3, holdPlayerBox);
                        done = 1;
                    }
                }
            }// end for holdPeg == "b"
        }// end the statement if != "*"
    }// end player 2 checking

    if(player == 3)
    {
        string holdPeg;
        string holdPlayerBox;
        int totalPegsOut;

        string enter;

        // by using the position (current) and checkAhead (to see what's ahead of them), test that position to see what it is
        if(AIboard.getBoard(checkAhead) != "*")
        {
            //check the peg there
            holdPeg = AIboard.getBoard(checkAhead); // hold the current peg

            // now test to see who the peg belongs to
            if( (holdPeg == "1") || (holdPeg == "2") || (holdPeg == "3") || (holdPeg == "4") )
            {
                holdPlayerBox = AIplayer.getpeg(0);
                totalPegsOut = AIplayer.getpegsOut(0);

                // peg is killed and message will be displayed to user
                if(holdPeg == "1")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[0] = '1';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 1 peg has been killed by a red peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "2")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[1] = '2';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 2 peg has been killed by a red peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "3")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[2] = '3';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 3 peg has been killed by a red peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "4")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[3] = '4';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 4 peg has been killed by a red peg. Press Enter to Continue.";
                    getline(cin, enter);
                }

                // make sure to check the temp Board for any stacked pegs
                if(AIboard.gettempBoard(checkAhead) != "***")
                {
                    string holdTempBoard;
                    holdTempBoard = AIboard.gettempBoard(checkAhead);

                    // scan each individual spot
                    for(int i = 0; i < 3; i++)
                    {
                        holdPlayerBox = AIplayer.getpeg(0);
                        totalPegsOut = AIplayer.getpegsOut(0);

                        if(holdTempBoard[i] != '*')
                        {
                            holdPeg = holdTempBoard[i];

                            if(holdPeg == "1")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[0] = '1';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 1 peg has been killed by a red peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "2")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[1] = '2';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 2 peg has been killed by a red peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "3")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[2] = '3';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 3 peg has been killed by a red peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "4")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[3] = '4';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 4 peg has been killed by a red peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                        } //end checking certain spots
                    }// end loop
                    // replace the entire spot with asterisks

                    AIboard.settempBoard(checkAhead, "***");

                } // end killing on tempBoard

            } // end killing human peg

            // check for red peg
            if(holdPeg == "g")
            {
                holdPlayerBox = AIplayer.getpeg(1);
                totalPegsOut = AIplayer.getpegsOut(1);

                // test for a position to put the peg in a spot
                int done = 0;

                for(int i = 0; i < 4; i++)
                {
                    if( (holdPlayerBox[i] == ' ') && (done == 0) )
                    {
                        holdPlayerBox[i] == 'g';
                        totalPegsOut--;
                        AIplayer.setpegsOut(1, totalPegsOut);
                        AIplayer.setpeg(1, holdPlayerBox);
                        done = 1;
                    }
                }
            } // end for holdPeg == "r"

            if(holdPeg == "b")
            {
                holdPlayerBox = AIplayer.getpeg(3);
                totalPegsOut = AIplayer.getpegsOut(3);

                // test for a position to put the peg in a spot
                int done = 0;

                for(int i = 0; i < 4; i++)
                {
                    if( (holdPlayerBox[i] == ' ') && (done == 0) )
                    {
                        holdPlayerBox[i] == 'b';
                        totalPegsOut--;
                        AIplayer.setpegsOut(3, totalPegsOut);
                        AIplayer.setpeg(3, holdPlayerBox);
                        done = 1;
                    }
                }
            }// end for holdPeg == "b"
        }// end the statement if != "*"
    }// end player 3 checking

    if(player == 4)
    {
        string holdPeg;
        string holdPlayerBox;
        int totalPegsOut;

        string enter;

        // by using the position (current) and checkAhead (to see what's ahead of them), test that position to see what it is
        if(AIboard.getBoard(checkAhead) != "*")
        {
            //check the peg there
            holdPeg = AIboard.getBoard(checkAhead); // hold the current peg

            // now test to see who the peg belongs to
            if( (holdPeg == "1") || (holdPeg == "2") || (holdPeg == "3") || (holdPeg == "4") )
            {
                holdPlayerBox = AIplayer.getpeg(0);
                totalPegsOut = AIplayer.getpegsOut(0);

                // peg is killed and message will be displayed to user
                if(holdPeg == "1")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[0] = '1';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 1 peg has been killed by a blue peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "2")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[1] = '2';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 2 peg has been killed by a blue peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "3")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[2] = '3';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 3 peg has been killed by a blue peg. Press Enter to Continue.";
                    getline(cin, enter);
                }
                else if(holdPeg == "4")
                {
                    // now move the peg back to it's respective spot
                    holdPlayerBox[3] = '4';
                    AIplayer.setpeg(0, holdPlayerBox);

                    totalPegsOut--;
                    AIplayer.setpegsOut(0, totalPegsOut);

                    //display the board and the message
                    AIboard.display(AIplayer, roll);
                    cout << "Oh no! Your 4 peg has been killed by a blue peg. Press Enter to Continue.";
                    getline(cin, enter);
                }

                // make sure to check the temp Board for any stacked pegs
                if(AIboard.gettempBoard(checkAhead) != "***")
                {
                    string holdTempBoard;
                    holdTempBoard = AIboard.gettempBoard(checkAhead);

                    // scan each individual spot
                    for(int i = 0; i < 3; i++)
                    {
                        holdPlayerBox = AIplayer.getpeg(0);
                        totalPegsOut = AIplayer.getpegsOut(0);

                        if(holdTempBoard[i] != '*')
                        {
                            holdPeg = holdTempBoard[i];

                            if(holdPeg == "1")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[0] = '1';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 1 peg has been killed by a blue peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "2")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[1] = '2';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 2 peg has been killed by a blue peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "3")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[2] = '3';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 3 peg has been killed by a blue peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                            else if(holdPeg == "4")
                            {
                                // now move the peg back to it's respective spot
                                holdPlayerBox[3] = '4';
                                AIplayer.setpeg(0, holdPlayerBox);

                                totalPegsOut--;
                                AIplayer.setpegsOut(0, totalPegsOut);

                                //display the board and the message
                                AIboard.display(AIplayer, roll);
                                cout << "Oh no! Your 4 peg has been killed by a blue peg. Press Enter to Continue.";
                                getline(cin, enter);
                            }
                        } //end checking certain spots
                    }// end loop
                    // replace the entire spot with asterisks

                    AIboard.settempBoard(checkAhead, "***");

                } // end killing on tempBoard

            } // end killing human peg

            // check for red peg
            if(holdPeg == "r")
            {
                holdPlayerBox = AIplayer.getpeg(2);
                totalPegsOut = AIplayer.getpegsOut(2);

                // test for a position to put the peg in a spot
                int done = 0;

                for(int i = 0; i < 4; i++)
                {
                    if( (holdPlayerBox[i] == ' ') && (done == 0) )
                    {
                        holdPlayerBox[i] == 'r';
                        totalPegsOut--;
                        AIplayer.setpegsOut(2, totalPegsOut);
                        AIplayer.setpeg(2, holdPlayerBox);
                        done = 1;
                    }
                }
            } // end for holdPeg == "r"

            if(holdPeg == "g")
            {
                holdPlayerBox = AIplayer.getpeg(1);
                totalPegsOut = AIplayer.getpegsOut(1);

                // test for a position to put the peg in a spot
                int done = 0;

                for(int i = 0; i < 4; i++)
                {
                    if( (holdPlayerBox[i] == ' ') && (done == 0) )
                    {
                        holdPlayerBox[i] == 'g';
                        totalPegsOut--;
                        AIplayer.setpegsOut(1, totalPegsOut);
                        AIplayer.setpeg(1, holdPlayerBox);
                        done = 1;
                    }
                }
            }// end for holdPeg == "b"
        }// end the statement if != "*"
    }// end checking for player 4
}// close the AIcheck function


// green player function
void ArtificialIntelligence::greenPlay(playerData& greenPlayer, boardData& greenBoard)
{
    int skipFunction = 0;
    int multipleChoice = 0;

    srand(time(NULL));
    roll green;

    // generate a green roll that will be used for the entire function
    green.greenRoll = rand()%6+1;

    /// multiple choice function goes here
    // when given the chance, there will be a 66% chance that a peg will be moved out, 33% will be to move accordingly
    if( (green.greenRoll == 6) && (greenPlayer.getpegsOut(1) > 0) && (greenPlayer.getpegsOut(1) < 4) )
    {
        // the bot will choose a function to use
        int getMultipleDecision = rand()%3+1;

        if(getMultipleDecision < 3)
        {
            multipleChoice = 1; // move the peg out of the box
            skipFunction = 1;
        }
        else multipleChoice = 0;  // skip the moving peg out
    }

    // first, initialize the game
    if( (green.greenRoll == 6) && (greenPlayer.getpegsOut(1) == 0))
    {
        // always grab the first peg
        int pegsOut;
        int scan = 0;
        string tempPeg;
        string holdItem;

        holdItem = greenPlayer.getpeg(1);

        for(int i = 0; i < 4; i++)
            if(scan == 0)
                if(holdItem[i] == 'g')
                {
                    tempPeg = holdItem[i];
                    holdItem[i] = ' ';
                    scan = 1;
                    greenPlayer.setpeg(1, holdItem);

                    // increment the number of pegs out
                    pegsOut = greenPlayer.getpegsOut(1);
                    pegsOut++;
                    greenPlayer.setpegsOut(1, pegsOut);
                }

        // Now move the green peg to the correct starting position
        AIcheck(greenPlayer, greenBoard, green.greenRoll, 10, 2);
        greenBoard.setBoard(10, tempPeg);

        // generate a new roll to move
        green.greenRoll = rand()%6+1;

        // now move the peg
        int movePeg;
        movePeg = 10 + green.greenRoll;

        AIcheck(greenPlayer, greenBoard, green.greenRoll, movePeg, 2);

        greenBoard.setBoard(movePeg, tempPeg);
        greenBoard.setBoard(10, "*");

        // if this is set to 1,skip any other functions to prevent moving again
        skipFunction = 1;

    }   // end the starting function


    /// if multiple choice == 1 function goes here
    // if the answer is yes, run this function and then end turn
    if(multipleChoice == 1)
    {
        // same functionality for moving a peg out of the box
        // always grab the first peg
        int pegsOut;
        int scan = 0;
        string tempPeg;
        string holdItem;

        holdItem = greenPlayer.getpeg(1);

        for(int i = 0; i < 4; i++)
            if(scan == 0)
                if(holdItem[i] == 'g')
                {
                    tempPeg = holdItem[i];
                    holdItem[i] = ' ';
                    scan = 1;
                    greenPlayer.setpeg(1, holdItem);

                    // check for peg at space 10
                    AIcheck(greenPlayer, greenBoard, green.greenRoll, 10, 2);

                    // increment the number of pegs out
                    pegsOut = greenPlayer.getpegsOut(1);
                    pegsOut++;
                    greenPlayer.setpegsOut(1, pegsOut);
                }

        // Now move the green peg to the correct starting position
        greenBoard.setBoard(10, tempPeg);

        // generate a new roll to move
        green.greenRoll = rand()%6+1;

        // now move the peg
        int movePeg;
        int checkAhead;

        movePeg = 10 + green.greenRoll;
        checkAhead = 10 + green.greenRoll;

        /// create AIcheckPegs function to use for this
        // use the checkAhead to grab the peg and run it through AIcheckPegs
        if(greenBoard.getBoard(checkAhead) == "*")
        {
            greenBoard.setBoard(movePeg, tempPeg);
            greenBoard.setBoard(10, "*");
            skipFunction = 1;
        }
        else if(greenBoard.getBoard(checkAhead) == "g")
        {
            skipFunction = 1;
        }
        else
        {
            AIcheck(greenPlayer, greenBoard, green.greenRoll, checkAhead, 2);
            greenBoard.setBoard(movePeg, tempPeg);
            greenBoard.setBoard(10, "*");
            skipFunction = 1;
        }
    }


    if( (greenPlayer.getpegsOut(1) > 0) && (skipFunction == 0) )
    {
        // use the amount of pegs out to determine the what peg the AI should move
        int totalPegs = greenPlayer.getpegsOut(1);
        int moveDone = 0;
        int flag = 0;
        int dontMove = 0;
        int endTurn = 0;

        // The decision will be 66% yes, 33% no. If scanned to last peg, always move that last peg
        // 1-2 = yes, 3 = no
        int decision;

        int position = 0;
        string tempPeg;
        int pegMove;
        int checkAhead;


        // test to see whether the AI wants to move the home peg
        // variables used only for home position
        int homePosition = 0;
        string tempHomePeg;
        int homePegMove;
        int homeCheckAhead;
        int homeFlag = 0; // flag checker to see if any pegs are there
        int homeEndTurn = 0;
        int homeChecked = 0;

        for(int i = 0; i < 4; i++)
            if(greenBoard.getgreenEnd(i) == "g")
                homeFlag = 1;

        // test if the AI wants to move a peg in home
        if(homeFlag == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                // check ahead and make sure the roll is enough to move
                homePegMove = homePosition + green.greenRoll;

                if(homeEndTurn = 0)
                {
                    // scan each section again
                    if(greenBoard.getgreenEnd(i) == "g")
                    {
                        if(homePegMove < 4)
                        {
                            //if it is enough, make sure the space is not occupied
                            if(greenBoard.getgreenEnd(homePegMove) == "0")
                            {
                                // move it
                                greenBoard.setgreenEnd(homePegMove, "g");
                                greenBoard.setgreenEnd(homePosition, "0");

                                // when moved, end the function
                                homeEndTurn = 1;
                                endTurn = 1;
                            }
                        }
                    }
                }

                homePosition++; // increment
            }
        }

        // scan the board for available pegs to move
        for(int i = 0; i < 40; i++)
        {
          if(endTurn == 0)
          {
            flag = 0;

            // scan for the first peg
            if(greenBoard.getBoard(i) == "g")
            {
                tempPeg = greenBoard.getBoard(i);
                flag = 1;
            }

            if(flag == 0)
                position++;

            checkAhead = position + green.greenRoll;    // used throughout the entire function to determine certain spots on the board

            // make sure to check if the position is on the correct spot
            // this is only a test when there are MULTIPLE PEGS are out
            if(greenBoard.getBoard(position) == "*")
                flag = 0;

            // check for position when the peg is about to go into home position
            // check positions between 4-9 and when flag == 1
            // also checkAhead will still be determined to make sure it doesn't go over 10
            if( (position >= 4) && (position <= 9) && (flag == 1) )
            {
                int goHome = 0;

                if(checkAhead > 9)
                    goHome = 0;
                else goHome = 1;

                if(goHome == 0)
                {
                    //now do some calculations to determine how far to go in
                    int calculation;
                    int tempRoll;
                    int taken = 0;

                    calculation = 10 - position;
                    tempRoll = green.greenRoll - calculation;

                    // determine if it is enough space to actually enter home
                    if(tempRoll < 4)
                    {
                        if(greenBoard.getgreenEnd(tempRoll) == "0")
                        {
                            // move in
                            greenBoard.setgreenEnd(tempRoll, tempPeg);
                            greenBoard.setBoard(position, "*");
                        }
                    }

                    // make sure the peg cannot be moved again for other functions
                    dontMove = 1;
                    //endTurn = 1;
                }
            }// end going home


            // check to make sure the peg does not go out of scope
            // when the checkAhead > 39

            if( (checkAhead > 39) && (flag == 1) )
            {
                int calculation;
                int tempRoll;

                calculation = 40 - position;
                tempRoll = green.greenRoll - calculation;

                // check for pegs here
                // by using the new tempRoll, check if the spot is occupied or not

                if(greenBoard.getBoard(tempRoll) == "*")
                {
                    //move in
                    greenBoard.setBoard(tempRoll, tempPeg);
                    greenBoard.setBoard(position, "*");
                    dontMove = 1;
                    endTurn = 1;
                }
                else if(greenBoard.getBoard(tempRoll) == "g")
                {
                    //do not move
                    dontMove = 1;
                    endTurn = 1;
                }
                else
                {
                    AIcheck(greenPlayer, greenBoard, green.greenRoll, tempRoll, 2);

                    greenBoard.setBoard(tempRoll, tempPeg);
                    greenBoard.setBoard(position, "*");

                    dontMove = 1;
                    endTurn = 1;
                }


            }

            // if all tests fail, do this part
            if(dontMove == 0)
            {
                decision = rand()%3+1;  // decision making

                if(flag == 1)
                {
                    if(moveDone == 0)
                    {
                        // do i want to move this?
                        if(decision < 3) // yes
                        {
                            // yes move this peg

                            pegMove = green.greenRoll + position;

                            // check for pegs here
                            // by using pegMove, check if the space is occupied or not

                            if(greenBoard.getBoard(pegMove) == "*")
                            {
                                //move in
                                greenBoard.setBoard(pegMove, tempPeg);
                                greenBoard.setBoard(position, "*");
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else if(greenBoard.getBoard(pegMove) == "g")
                            {
                                //do not move
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else
                            {
                                AIcheck(greenPlayer, greenBoard, green.greenRoll, pegMove, 2);

                                greenBoard.setBoard(pegMove, tempPeg);
                                greenBoard.setBoard(position, "*");

                                dontMove = 1;
                                endTurn = 1;
                            }
                        }
                        else{
                            totalPegs--;
                        }

                    }
                }

                // always move if it is the last peg out
                if( (totalPegs == 0) && (moveDone == 0) )
                {
                    // always move the last available peg
                    // yes move this peg
                    pegMove = green.greenRoll + position;

                    // check for pegs here
                    // by using pegMove, check if the space is occupied or not

                    if(greenBoard.getBoard(pegMove) == "*")
                            {
                                //move in
                                greenBoard.setBoard(pegMove, tempPeg);
                                greenBoard.setBoard(position, "*");
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else if(greenBoard.getBoard(pegMove) == "g")
                            {
                                //do not move
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else
                            {
                                AIcheck(greenPlayer, greenBoard, green.greenRoll, pegMove, 2);

                                greenBoard.setBoard(pegMove, tempPeg);
                                greenBoard.setBoard(position, "*");

                                dontMove = 1;
                                endTurn = 1;
                            }
                }

            } // end don'tmove
          }// end turn
        }// end loop
    }// end the function that always move if possible

    // Only for displaying
    string enter;
    greenBoard.display(greenPlayer, green.greenRoll);
    cout << "green finished his turn. Press Enter to Continue.";
    getline(cin, enter);

}    /// END OF ENTIRE GREEN PLAY FUCNTION


// red player function
void ArtificialIntelligence::redPlay(playerData& redPlayer, boardData& redBoard)
{
    int skipFunction = 0;
    int multipleChoice = 0;

    srand(time(NULL));
    roll red;

    // generate a red roll that will be used for the entire function
    red.redRoll = rand()%6+1;

    /// multiple choice function goes here
    // when given the chance, there will be a 66% chance that a peg will be moved out, 33% will be to move accordingly
    if( (red.redRoll == 6) && (redPlayer.getpegsOut(2) > 0) && (redPlayer.getpegsOut(2) < 4) )
    {
        // the bot will choose a function to use
        int getMultipleDecision = rand()%3+1;

        if(getMultipleDecision < 3)
        {
            multipleChoice = 1; // move the peg out of the box
            skipFunction = 1;
        }
        else multipleChoice = 0;  // skip the moving peg out
    }

    // first, initialize the game
    if( (red.redRoll == 6) && (redPlayer.getpegsOut(2) == 0))
    {
        // always grab the first peg
        int pegsOut;
        int scan = 0;
        string tempPeg;
        string holdItem;

        holdItem = redPlayer.getpeg(2);

        for(int i = 0; i < 4; i++)
            if(scan == 0)
                if(holdItem[i] == 'r')
                {
                    tempPeg = holdItem[i];
                    holdItem[i] = ' ';
                    scan = 1;
                    redPlayer.setpeg(2, holdItem);

                    // increment the number of pegs out
                    pegsOut = redPlayer.getpegsOut(2);
                    pegsOut++;
                    redPlayer.setpegsOut(2, pegsOut);
                }

        // Now move the red peg to the correct starting position
        AIcheck(redPlayer, redBoard, red.redRoll, 20, 3);
        redBoard.setBoard(20, tempPeg);

        // generate a new roll to move
        red.redRoll = rand()%6+1;

        // now move the peg
        int movePeg;
        movePeg = 20 + red.redRoll;

        AIcheck(redPlayer, redBoard, red.redRoll, movePeg, 3);

        redBoard.setBoard(movePeg, tempPeg);
        redBoard.setBoard(20, "*");

        // if this is set to 1,skip any other functions to prevent moving again
        skipFunction = 1;

    }   // end the starting function


    /// if multiple choice == 1 function goes here
    // if the answer is yes, run this function and then end turn
    if(multipleChoice == 1)
    {
        // same functionality for moving a peg out of the box
        // always grab the first peg
        int pegsOut;
        int scan = 0;
        string tempPeg;
        string holdItem;

        holdItem = redPlayer.getpeg(2);

        for(int i = 0; i < 4; i++)
            if(scan == 0)
                if(holdItem[i] == 'r')
                {
                    tempPeg = holdItem[i];
                    holdItem[i] = ' ';
                    scan = 1;
                    redPlayer.setpeg(2, holdItem);

                    // check for peg at space 10
                    AIcheck(redPlayer, redBoard, red.redRoll, 20, 3);

                    // increment the number of pegs out
                    pegsOut = redPlayer.getpegsOut(2);
                    pegsOut++;
                    redPlayer.setpegsOut(2, pegsOut);
                }

        // Now move the red peg to the correct starting position
        redBoard.setBoard(20, tempPeg);

        // generate a new roll to move
        red.redRoll = rand()%6+1;

        // now move the peg
        int movePeg;
        int checkAhead;

        movePeg = 20 + red.redRoll;
        checkAhead = 20 + red.redRoll;

        /// create AIcheckPegs function to use for this
        // use the checkAhead to grab the peg and run it through AIcheckPegs
        if(redBoard.getBoard(checkAhead) == "*")
        {
            redBoard.setBoard(movePeg, tempPeg);
            redBoard.setBoard(20, "*");
            skipFunction = 1;
        }
        else if(redBoard.getBoard(checkAhead) == "r")
        {
            skipFunction = 1;
        }
        else
        {
            AIcheck(redPlayer, redBoard, red.redRoll, checkAhead, 3);
            redBoard.setBoard(movePeg, tempPeg);
            redBoard.setBoard(20, "*");
            skipFunction = 1;
        }
    }


    if( (redPlayer.getpegsOut(2) > 0) && (skipFunction == 0) )
    {
        // use the amount of pegs out to determine the what peg the AI should move
        int totalPegs = redPlayer.getpegsOut(2);
        int moveDone = 0;
        int flag = 0;
        int dontMove = 0;
        int endTurn = 0;

        // The decision will be 66% yes, 33% no. If scanned to last peg, always move that last peg
        // 1-2 = yes, 3 = no
        int decision;

        int position = 0;
        string tempPeg;
        int pegMove;
        int checkAhead;


        // test to see whether the AI wants to move the home peg
        // variables used only for home position
        int homePosition = 0;
        string tempHomePeg;
        int homePegMove;
        int homeCheckAhead;
        int homeFlag = 0; // flag checker to see if any pegs are there
        int homeEndTurn = 0;
        int homeChecked = 0;

        for(int i = 0; i < 4; i++)
            if(redBoard.getredEnd(i) == "r")
                homeFlag = 1;

        // test if the AI wants to move a peg in home
        if(homeFlag == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                // check ahead and make sure the roll is enough to move
                homePegMove = homePosition + red.redRoll;

                if(homeEndTurn = 0)
                {
                    // scan each section again
                    if(redBoard.getredEnd(i) == "r")
                    {
                        if(homePegMove < 4)
                        {
                            //if it is enough, make sure the space is not occupied
                            if(redBoard.getredEnd(homePegMove) == "0")
                            {
                                // move it
                                redBoard.setredEnd(homePegMove, "r");
                                redBoard.setredEnd(homePosition, "0");

                                // when moved, end the function
                                homeEndTurn = 1;
                                endTurn = 1;
                            }
                        }
                    }
                }

                homePosition++; // increment
            }
        }

        // scan the board for available pegs to move
        for(int i = 0; i < 40; i++)
        {
          if(endTurn == 0)
          {
            flag = 0;

            // scan for the first peg
            if(redBoard.getBoard(i) == "r")
            {
                tempPeg = redBoard.getBoard(i);
                flag = 1;
            }

            if(flag == 0)
                position++;

            checkAhead = position + red.redRoll;    // used throughout the entire function to determine certain spots on the board

            // make sure to check if the position is on the correct spot
            // this is only a test when there are MULTIPLE PEGS are out
            if(redBoard.getBoard(position) == "*")
                flag = 0;

            // check for position when the peg is about to go into home position
            // check positions between 4-9 and when flag == 1
            // also checkAhead will still be determined to make sure it doesn't go over 10
            if( (position >= 14) && (position <= 19) && (flag == 1) )
            {
                int goHome = 0;

                if(checkAhead > 19)
                    goHome = 0;
                else goHome = 1;

                if(goHome == 0)
                {
                    //now do some calculations to determine how far to go in
                    int calculation;
                    int tempRoll;
                    int taken = 0;

                    calculation = 20 - position;
                    tempRoll = red.redRoll - calculation;

                    // determine if it is enough space to actually enter home
                    if(tempRoll < 4)
                    {
                        if(redBoard.getredEnd(tempRoll) == "0")
                        {
                            // move in
                            redBoard.setredEnd(tempRoll, tempPeg);
                            redBoard.setBoard(position, "*");
                        }
                    }

                    // make sure the peg cannot be moved again for other functions
                    dontMove = 1;
                    //endTurn = 1;
                }
            }// end going home


            // check to make sure the peg does not go out of scope
            // when the checkAhead > 39

            if( (checkAhead > 39) && (flag == 1) )
            {
                int calculation;
                int tempRoll;

                calculation = 40 - position;
                tempRoll = red.redRoll - calculation;

                // check for pegs here
                // by using the new tempRoll, check if the spot is occupied or not

                if(redBoard.getBoard(tempRoll) == "*")
                {
                    //move in
                    redBoard.setBoard(tempRoll, tempPeg);
                    redBoard.setBoard(position, "*");
                    dontMove = 1;
                    endTurn = 1;
                }
                else if(redBoard.getBoard(tempRoll) == "r")
                {
                    //do not move
                    dontMove = 1;
                    endTurn = 1;
                }
                else
                {
                    AIcheck(redPlayer, redBoard, red.redRoll, tempRoll, 3);

                    redBoard.setBoard(tempRoll, tempPeg);
                    redBoard.setBoard(position, "*");

                    dontMove = 1;
                    endTurn = 1;
                }


            }

            // if all tests fail, do this part
            if(dontMove == 0)
            {
                decision = rand()%3+1;  // decision making

                if(flag == 1)
                {
                    if(moveDone == 0)
                    {
                        // do i want to move this?
                        if(decision < 3) // yes
                        {
                            // yes move this peg

                            pegMove = red.redRoll + position;

                            // check for pegs here
                            // by using pegMove, check if the space is occupied or not

                            if(redBoard.getBoard(pegMove) == "*")
                            {
                                //move in
                                redBoard.setBoard(pegMove, tempPeg);
                                redBoard.setBoard(position, "*");
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else if(redBoard.getBoard(pegMove) == "r")
                            {
                                //do not move
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else
                            {
                                AIcheck(redPlayer, redBoard, red.redRoll, pegMove, 3);

                                redBoard.setBoard(pegMove, tempPeg);
                                redBoard.setBoard(position, "*");

                                dontMove = 1;
                                endTurn = 1;
                            }
                        }
                        else{
                            totalPegs--;
                        }

                    }
                }

                // always move if it is the last peg out
                if( (totalPegs == 0) && (moveDone == 0) )
                {
                    // always move the last available peg
                    // yes move this peg
                    pegMove = red.redRoll + position;

                    // check for pegs here
                    // by using pegMove, check if the space is occupied or not

                    if(redBoard.getBoard(pegMove) == "*")
                            {
                                //move in
                                redBoard.setBoard(pegMove, tempPeg);
                                redBoard.setBoard(position, "*");
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else if(redBoard.getBoard(pegMove) == "r")
                            {
                                //do not move
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else
                            {
                                AIcheck(redPlayer, redBoard, red.redRoll, pegMove, 3);

                                redBoard.setBoard(pegMove, tempPeg);
                                redBoard.setBoard(position, "*");

                                dontMove = 1;
                                endTurn = 1;
                            }
                }

            } // end don'tmove
          }// end turn
        }// end loop
    }// end the function that always move if possible

    // Only for displaying
    string enter;
    redBoard.display(redPlayer, red.redRoll);
    cout << "red finished his turn. Press Enter to Continue.";
    getline(cin, enter);

}    /// END OF ENTIRE red PLAY FUCNTION


// blue player function
void ArtificialIntelligence::bluePlay(playerData& bluePlayer, boardData& blueBoard)
{
    int skipFunction = 0;
    int multipleChoice = 0;

    srand(time(NULL));
    roll blue;

    // generate a blue roll that will be used for the entire function
    blue.blueRoll = rand()%6+1;

    /// multiple choice function goes here
    // when given the chance, there will be a 66% chance that a peg will be moved out, 33% will be to move accordingly
    if( (blue.blueRoll == 6) && (bluePlayer.getpegsOut(3) > 0) && (bluePlayer.getpegsOut(3) < 4) )
    {
        // the bot will choose a function to use
        int getMultipleDecision = rand()%3+1;

        if(getMultipleDecision < 3)
        {
            multipleChoice = 1; // move the peg out of the box
            skipFunction = 1;
        }
        else multipleChoice = 0;  // skip the moving peg out
    }

    // first, initialize the game
    if( (blue.blueRoll == 6) && (bluePlayer.getpegsOut(3) == 0))
    {
        // always grab the first peg
        int pegsOut;
        int scan = 0;
        string tempPeg;
        string holdItem;

        holdItem = bluePlayer.getpeg(3);

        for(int i = 0; i < 4; i++)
            if(scan == 0)
                if(holdItem[i] == 'b')
                {
                    tempPeg = holdItem[i];
                    holdItem[i] = ' ';
                    scan = 1;
                    bluePlayer.setpeg(3, holdItem);

                    // increment the number of pegs out
                    pegsOut = bluePlayer.getpegsOut(3);
                    pegsOut++;
                    bluePlayer.setpegsOut(3, pegsOut);
                }

        // Now move the blue peg to the correct starting position
        AIcheck(bluePlayer, blueBoard, blue.blueRoll, 30, 4);
        blueBoard.setBoard(30, tempPeg);

        // generate a new roll to move
        blue.blueRoll = rand()%6+1;

        // now move the peg
        int movePeg;
        movePeg = 30 + blue.blueRoll;

        AIcheck(bluePlayer, blueBoard, blue.blueRoll, movePeg, 4);

        blueBoard.setBoard(movePeg, tempPeg);
        blueBoard.setBoard(30, "*");

        // if this is set to 1,skip any other functions to prevent moving again
        skipFunction = 1;

    }   // end the starting function


    /// if multiple choice == 1 function goes here
    // if the answer is yes, run this function and then end turn
    if(multipleChoice == 1)
    {
        // same functionality for moving a peg out of the box
        // always grab the first peg
        int pegsOut;
        int scan = 0;
        string tempPeg;
        string holdItem;

        holdItem = bluePlayer.getpeg(3);

        for(int i = 0; i < 4; i++)
            if(scan == 0)
                if(holdItem[i] == 'b')
                {
                    tempPeg = holdItem[i];
                    holdItem[i] = ' ';
                    scan = 1;
                    bluePlayer.setpeg(3, holdItem);

                    // check for peg at space 10
                    AIcheck(bluePlayer, blueBoard, blue.blueRoll, 30, 4);

                    // increment the number of pegs out
                    pegsOut = bluePlayer.getpegsOut(3);
                    pegsOut++;
                    bluePlayer.setpegsOut(3, pegsOut);
                }

        // Now move the blue peg to the correct starting position
        blueBoard.setBoard(30, tempPeg);

        // generate a new roll to move
        blue.blueRoll = rand()%6+1;

        // now move the peg
        int movePeg;
        int checkAhead;

        movePeg = 30 + blue.blueRoll;
        checkAhead = 30 + blue.blueRoll;

        /// create AIcheckPegs function to use for this
        // use the checkAhead to grab the peg and run it through AIcheckPegs
        if(blueBoard.getBoard(checkAhead) == "*")
        {
            blueBoard.setBoard(movePeg, tempPeg);
            blueBoard.setBoard(30, "*");
            skipFunction = 1;
        }
        else if(blueBoard.getBoard(checkAhead) == "b")
        {
            skipFunction = 1;
        }
        else
        {
            AIcheck(bluePlayer, blueBoard, blue.blueRoll, checkAhead, 4);
            blueBoard.setBoard(movePeg, tempPeg);
            blueBoard.setBoard(30, "*");
            skipFunction = 1;
        }
    }


    if( (bluePlayer.getpegsOut(3) > 0) && (skipFunction == 0) )
    {
        // use the amount of pegs out to determine the what peg the AI should move
        int totalPegs = bluePlayer.getpegsOut(3);
        int moveDone = 0;
        int flag = 0;
        int dontMove = 0;
        int endTurn = 0;

        // The decision will be 66% yes, 33% no. If scanned to last peg, always move that last peg
        // 1-2 = yes, 3 = no
        int decision;

        int position = 0;
        string tempPeg;
        int pegMove;
        int checkAhead;


        // test to see whether the AI wants to move the home peg
        // variables used only for home position
        int homePosition = 0;
        string tempHomePeg;
        int homePegMove;
        int homeCheckAhead;
        int homeFlag = 0; // flag checker to see if any pegs are there
        int homeEndTurn = 0;
        int homeChecked = 0;

        for(int i = 0; i < 4; i++)
            if(blueBoard.getblueEnd(i) == "b")
                homeFlag = 1;

        // test if the AI wants to move a peg in home
        if(homeFlag == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                // check ahead and make sure the roll is enough to move
                homePegMove = homePosition + blue.blueRoll;

                if(homeEndTurn = 0)
                {
                    // scan each section again
                    if(blueBoard.getblueEnd(i) == "b")
                    {
                        if(homePegMove < 4)
                        {
                            //if it is enough, make sure the space is not occupied
                            if(blueBoard.getblueEnd(homePegMove) == "0")
                            {
                                // move it
                                blueBoard.setblueEnd(homePegMove, "b");
                                blueBoard.setblueEnd(homePosition, "0");

                                // when moved, end the function
                                homeEndTurn = 1;
                                endTurn = 1;
                            }
                        }
                    }
                }

                homePosition++; // increment
            }
        }

        // scan the board for available pegs to move
        for(int i = 0; i < 40; i++)
        {
          if(endTurn == 0)
          {
            flag = 0;

            // scan for the first peg
            if(blueBoard.getBoard(i) == "b")
            {
                tempPeg = blueBoard.getBoard(i);
                flag = 1;
            }

            if(flag == 0)
                position++;

            checkAhead = position + blue.blueRoll;    // used throughout the entire function to determine certain spots on the board

            // make sure to check if the position is on the correct spot
            // this is only a test when there are MULTIPLE PEGS are out
            if(blueBoard.getBoard(position) == "*")
                flag = 0;

            // check for position when the peg is about to go into home position
            // check positions between 4-9 and when flag == 1
            // also checkAhead will still be determined to make sure it doesn't go over 10
            if( (position >= 24) && (position <= 29) && (flag == 1) )
            {
                int goHome = 0;

                if(checkAhead > 29)
                    goHome = 0;
                else goHome = 1;

                if(goHome == 0)
                {
                    //now do some calculations to determine how far to go in
                    int calculation;
                    int tempRoll;
                    int taken = 0;

                    calculation = 30 - position;
                    tempRoll = blue.blueRoll - calculation;

                    // determine if it is enough space to actually enter home
                    if(tempRoll < 4)
                    {
                        if(blueBoard.getblueEnd(tempRoll) == "0")
                        {
                            // move in
                            blueBoard.setblueEnd(tempRoll, tempPeg);
                            blueBoard.setBoard(position, "*");
                        }
                    }

                    // make sure the peg cannot be moved again for other functions
                    dontMove = 1;
                    //endTurn = 1;
                }
            }// end going home


            // check to make sure the peg does not go out of scope
            // when the checkAhead > 39

            if( (checkAhead > 39) && (flag == 1) )
            {
                int calculation;
                int tempRoll;

                calculation = 40 - position;
                tempRoll = blue.blueRoll - calculation;

                // check for pegs here
                // by using the new tempRoll, check if the spot is occupied or not

                if(blueBoard.getBoard(tempRoll) == "*")
                {
                    //move in
                    blueBoard.setBoard(tempRoll, tempPeg);
                    blueBoard.setBoard(position, "*");
                    dontMove = 1;
                    endTurn = 1;
                }
                else if(blueBoard.getBoard(tempRoll) == "b")
                {
                    //do not move
                    dontMove = 1;
                    endTurn = 1;
                }
                else
                {
                    AIcheck(bluePlayer, blueBoard, blue.blueRoll, tempRoll, 4);

                    blueBoard.setBoard(tempRoll, tempPeg);
                    blueBoard.setBoard(position, "*");

                    dontMove = 1;
                    endTurn = 1;
                }


            }

            // if all tests fail, do this part
            if(dontMove == 0)
            {
                decision = rand()%3+1;  // decision making

                if(flag == 1)
                {
                    if(moveDone == 0)
                    {
                        // do i want to move this?
                        if(decision < 3) // yes
                        {
                            // yes move this peg

                            pegMove = blue.blueRoll + position;

                            // check for pegs here
                            // by using pegMove, check if the space is occupied or not

                            if(blueBoard.getBoard(pegMove) == "*")
                            {
                                //move in
                                blueBoard.setBoard(pegMove, tempPeg);
                                blueBoard.setBoard(position, "*");
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else if(blueBoard.getBoard(pegMove) == "b")
                            {
                                //do not move
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else
                            {
                                AIcheck(bluePlayer, blueBoard, blue.blueRoll, pegMove, 4);

                                blueBoard.setBoard(pegMove, tempPeg);
                                blueBoard.setBoard(position, "*");

                                dontMove = 1;
                                endTurn = 1;
                            }
                        }
                        else{
                            totalPegs--;
                        }

                    }
                }

                // always move if it is the last peg out
                if( (totalPegs == 0) && (moveDone == 0) )
                {
                    // always move the last available peg
                    // yes move this peg
                    pegMove = blue.blueRoll + position;

                    // check for pegs here
                    // by using pegMove, check if the space is occupied or not

                    if(blueBoard.getBoard(pegMove) == "*")
                            {
                                //move in
                                blueBoard.setBoard(pegMove, tempPeg);
                                blueBoard.setBoard(position, "*");
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else if(blueBoard.getBoard(pegMove) == "b")
                            {
                                //do not move
                                dontMove = 1;
                                endTurn = 1;
                            }
                            else
                            {
                                AIcheck(bluePlayer, blueBoard, blue.blueRoll, pegMove, 4);

                                blueBoard.setBoard(pegMove, tempPeg);
                                blueBoard.setBoard(position, "*");

                                dontMove = 1;
                                endTurn = 1;
                            }
                }

            } // end don'tmove
          }// end turn
        }// end loop
    }// end the function that always move if possible

    // Only for displaying
    string enter;
    blueBoard.display(bluePlayer, blue.blueRoll);
    cout << "blue finished his turn. Press Enter to Continue.";
    getline(cin, enter);

}    /// END OF ENTIRE blue PLAY FUCNTION
