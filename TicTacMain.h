#ifndef TICTACMAIN_H_
#define TICTACMAIN_H_

class GameSetUp
{

public:
	//to initalize varibales
	GameSetUp();//constructor
	char board[10]; //board
	int playerinput; //spot indicated by the player
	char playermarker;
	int compinput;//random value that will act as the input for the computer
	char compmarker;
	int turns;//player turns taken (human + computer)

	void Gameboard();


	 int GameDecision();

	void GamePlay();

private:
	int HumanPlayer();

	int CompPlayer();
};//end of GameSetUp

#endif /* TICTACMAIN_H_ */

