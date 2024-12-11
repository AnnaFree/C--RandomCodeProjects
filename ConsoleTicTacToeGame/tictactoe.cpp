#include <iostream>
using namespace std;

void printBoard(char array[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
int evaluateGame(char array[3][3]) {
	//check row for horizontal win
	for (int row = 0; row < 3; row++) {
		if (array[row][0] == array[row][1] && array[row][1] == array[row][2]) {
			if (array[row][0] == 'X') {
				return 1; //player 1 win
			}
			else if (array[row][0] == 'O') {
				return -1; //AI win or player 2
			}
		}
	}

	//check col for vertical wins
	for (int col = 0; col < 0; col++) {
		if (array[0][col] == array[1][col] && array[1][col] == array[2][col]) {
			if (array[0][col] == 'X') {
				return 1;
			}
			else if (array[0][col] == 'O') {
				return -1;
			}
		}
	}
	//check for the two diagnol conditions for win
	if (array[0][0] == array[1][1] && array[2][2] == array[1][1]) {
		if(array[0][0] == 'X') {
			return 1;
		}
		else if (array[0][0] == 'O') {
			return -1;
		}
	}
	if (array[0][2] == array[1][1] && array[1][1] == array[2][0]) {
		if (array[0][2] == 'X') {
			return 1;
		}
		else if (array[0][2]== 'O') {
			return -1;
		}
	}

	return 0; // draw
}
void userTurn(char array[3][3], char playerLetter) {
	int tempRow, tempCol;
	printBoard(array);
	cout << "Which row would you to place your value in?" << endl;
	cin >> tempRow;
	cout << "Which col would you to place your value in?" << endl;
	cin >> tempCol;
	//assumes the user does not know arrays start at 0
	array[tempRow-1][tempCol-1] = playerLetter;
}

bool isBoardFull(char array[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (array[row][col] == '_') {
				//checks for a single empty spot and if so, is not full
				return false;
			}
		}
	}
	return true;
}

//using minimax with alpha-beta pruning to find best move possible
int minimax(char array[3][3], int depth, bool isAIturn, int alpha, int beta){
	//checks for game win or loss before continueing
	int score = evaluateGame(array);
	if (score == 1 || score == -1) {
		return score;
	}
	else if (isBoardFull(array)) {
		return 0;
	}

	//checks if it is its turn
	if (isAIturn) {
		int best = INT_MIN; //maximizing AI moves
		//checking moves to see the best by testing and pruning
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				if (array[row][col] == '_') {
					array[row][col] = 'X'; //AI move
					best = max(best, minimax(array, depth + 1, false, alpha, beta));
					array[row][col] = '_'; //undo move
					alpha = max(alpha, best);
					if (beta <= alpha) {
						break; //beta prune
					}
				}
			}// end for-loop col
		}// end for-loop row
		return best;
		//end of if turn for AI
	}
	else {
		int best = INT_MAX; // minimizing player moves

		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				if (array[row][col] == '_') {
					array[row][col] = 'O'; //opponent move guess
					best = min(best, minimax(array, depth + 1, true, alpha, beta));
					array[row][col] = '_'; //undo guess move
					beta = min(beta, best);
					if (beta <= alpha) {
						break;
					}
			
				}//outer if end
			}// col for loop end
		}//row for loop end
		return best;
		
	}//end of else
}

//implementation of minimax function
pair<int, int> findBestMoveAI(char array[3][3]) {
	//defualt val initialization
	int bestVal = INT_MIN;
	pair<int, int> bestMove = { -1, -1 };

	//looping through board to find best move
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			//if makes sure available is available before consideration
			if (array[row][col] == '_') {
				array[row][col] = 'X'; //make test move
				//minimax evaluates move
				int moveVal = minimax(array, 0, false, INT_MIN, INT_MAX);
				array[row][col] = '_'; //undo the temp move

				if (moveVal > bestVal) {
					bestMove = { row, col };
					bestVal = moveVal;
				}
			}
		}
	}
	return bestMove;
}
//main game logic - outsources many other functions defined above
void playGame(char array[3][3], bool aiPlayer) {
	int score = 0;
	bool player1Turn = true;

	while (score == 0 && !isBoardFull(array)) {
		printBoard(array);
		if (player1Turn == true) {
			cout << "Player 1's Turn:" << endl;
			userTurn(array, 'X');
			//switch turns
			player1Turn = false;
		}
		else {
			if (aiPlayer == false) {
				cout << "Player 2's Turn:" << endl;
				userTurn(array, 'O');
			}
			else if (aiPlayer == true) {
				//ai logic
				cout << "AI Player's Turn:" << endl;
				pair<int, int> bestMove(findBestMoveAI(array));
				array[bestMove.first][bestMove.second] = 'O';
			}
			else {
				cout << "Error has occured";
			}
			//switch turns
			player1Turn = true;
		}
		score = evaluateGame(array);

	}//end of while

	//final results
	if (score == 1) {
		cout << "Player 1 wins!";
	}
	else if (score == -1) {
		cout << "Player 2 wins!";
	}
	else if (score == 0) {
		cout << "Draw";
	}
	else {
		"Error has occured";
	}
}

	int main() {
		//game is still running and no win condition met
		bool boardActive = true;
		char array[3][3] = {
			{'_', '_', '_'},
			{'_', '_', '_'},
			{'_', '_', '_'}
		};

		//used for multi-player turn counting
		cout << "Will you be playing against another person that is with you?" << endl;
		string ans;
		cin >> ans;
		//making sure the input matches no matter the case
		for (int i = 0; i < ans.length(); i++) {
			ans[i] = tolower(ans[i]);
		}
		bool aiPlayer = false;

		if (ans == "yes" || ans == "y") {
			cout << "Player 1 will be X and Player 2 will be O";
		}
		else if (ans == "no" || ans == "n") {
			//ai match
			cout << "Player will be X and AI will be O" << endl;
			aiPlayer = true;
		}
		else {
			//answer invalid
			cout << "Answer is invalid.";
			//assumes ai for now
			aiPlayer = true;
		}
		playGame(array, aiPlayer);
		cout << "Would you like to play again?" << endl;
		cin >> ans;
		//game loop
		while (ans == "yes" || "y") {
			playGame(array, aiPlayer);
			cout << "Would you like to play again?" << endl;
			cin >> ans;
		}
	}//end main