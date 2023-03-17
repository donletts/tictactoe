#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include "TicTacMain.h"
using namespace std;

GameSetUp::GameSetUp(){
int i = 0;
 for (i = 0 ; i < 9; i++){
	 board[i] = char(i+49);//ASCI Uppercase letters
 } board[9] = '-';

	Gameboard();
	GamePlay();
}//end of GameSetUp

void GameSetUp::Gameboard(){
	cout << "\n";
	cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "----------" << endl;
	cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "----------" << endl;
	cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "\n";
};//end of Gameboard


int GameSetUp::GameDecision(){
//0 - no win, continue
//1 - win
//-1 - no win, tie
//wins conditions - horizontal/vertical
	if (board[0] == board[1] &&  board[1] == board[2])//row 1
		return 1;
	else if (board[3] == board[4] &&  board[4] == board[5])//row 2
		return 1;
	else if (board[6] == board[7] &&  board[7] == board[8])//row 3
		return 1;
	else if (board[0] == board[3] &&  board[3] == board[6])//vertical 1
		return 1;
	else if (board[1] == board[4] &&  board[4] == board[7])//vertical 2
		return 1;
	else if (board[2] == board[5] &&  board[5] == board[8])//vertical 3
		return 1;
	else if (board[1] == board[5] && board[5] == board[9])//Diagonal 1
		return 1;
	else if (board[3] == board[5] && board[5] == board[7])//Diagonal 2
			return 1;
	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
		return -1;//all spots taken and a tie
	else
		return 0; //no winner or tie so game continues
};//end of GameDecision


void GameSetUp::GamePlay(){
//switching players
   int turns = 9; //maximum turns that can be taken in a game, will decrease after each switch
   int current_turn = 0;
   int current_decision;
   while (current_turn < turns) {
	   if (current_turn % 2 == 0) {
	      HumanPlayer();
       }
	   else {
	      CompPlayer();
	   }
       current_turn++;

	   Gameboard();
	   current_decision = GameDecision();
	   if (current_decision == 1) {
	      if (current_turn % 2 == 0) {
	    	  cout << "Game Complete, Computer Won!";
	      // human player wins, call exit sequence with human winner input
	      } else {
	    	  cout << "Game Complete, Human Won!";
	      // computer player wins, call exit sequence with computer winner input
	      } break;
	   }
	   else if (current_decision == -1) {
		   cout << "Tie Game";
	   // a tie!, call exit sequence with tie input
	      break;
	   }
	   // if current_decision = 0 do nothing, i.e. continue the while loop, no check needed
   }
};//end of GamePlay


int GameSetUp::HumanPlayer(){
//human player decisions
cout << "\n";
cout << "Make a move, Enter a space to place your 'X': "; //asking for input
cin >> playerinput; //player's input
playermarker = 'X'; //marks the human players spaces
//because C++ is 0 index, -1 from input so it matches board number correctly
  bool validInput = false;
  while(!validInput) {
  // first check if the player's input is a valid number between 1 and 9
    if (playerinput < 1 || playerinput > 9) {
      cout << "Invalid Input. Enter a number between 1 and 9: "; //condition if player inputs bad number
      cin >> playerinput;
      continue;
    }
    // if the cell the player chose has a char/number in it, then the space is not taken
  	// isdigit will be true if there is still a number in the cell, false if the cell is marked with an X or O
  	if ( isdigit( board[playerinput - 1] ) )  {
        board[playerinput - 1] = playermarker;
      	validInput = true;
    }
    else {
      cout << "That space is taken, try again: "; //condition if player inputs bad number
      cin >> playerinput;
    }
  }
};//HumanPlayer


int GameSetUp::CompPlayer(){
//computer player decisions
    compmarker = 'O'; //marks the computer player spaces
    compinput = rand() % 10; //throws out a random number between 0 - 9
    //move logic
  	bool validMove = false;
  	while ( !validMove ) {
      	// if the chosen spot still contains a digit/number, then it has not been chosen and is a valid choice
      	if ( isdigit( board[compinput])) {
          board[compinput] = compmarker;
          cout << "Computer's move: " << compinput+1 << endl;
          validMove = true;
        }
        else {
          compinput = rand() % 10;
        }
    };
};//ComputerPlayer

/*
int main(){
	GameSetUp();
	return 0;
};//end of main
*/
