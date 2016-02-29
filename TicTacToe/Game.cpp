#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>

using namespace std;

char arr[3][3] = { ' ', ' ', ' ',
' ', ' ', ' ',
' ', ' ', ' ' };
char inp = ' ';
char freeP[3][3] = { '1', '2', '3',
'4', '5', '6',
'7', '8', '9' };

int position = 0;
int positions[9];
char temp = ' ';
string playerOriginalNames(char play, string playerOne, string playerTwo);//Create method for switch names
void drawChartA(); //Function that draws the array to game board the simple way
void drawChartB(); //Function that draws the array to game board the prety way
void drawPositions(); //This functions display the position 1 to 9 that the players need to enter
char switchPlayer(char player); //This function changes the active player to the one that need to makes his/her turn
void insertChar(char player, int position, string first, string second); // This function inserts 'X' or '0' depends on the active player to the corresponding position
char randomizePlayers(char player); // Indicates which players star first
bool isGameFinished(char matrix[3][3], string first, string second); // Indicates whether there is a winner or game is draw
//char XorNull(char inp);// Make decisions what character you'll draw on the chess desk.
void lookingForFreePositions();//Free positions message.
void insertCharComputer();
void drawFreePositions();
void main(){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 3; i++){
		if (i % 2 == 0){
			SetConsoleTextAttribute(hConsole, 15);

			cout << "==================" << endl;
		}
		else{

			cout << "||";
			SetConsoleTextAttribute(hConsole, 9);
			cout << "  TIC TA";
			SetConsoleTextAttribute(hConsole, 12);
			cout << "C TOE ";
			SetConsoleTextAttribute(hConsole, 15);

			cout << "||" << endl;
		}
	}

	string first;
	string second;
	bool opa = false;
	char player = ' ';
	char game_choice = ' ';
	SetConsoleTextAttribute(hConsole, 6);
	cout << "You play against: "<<endl;
	cout << "1.Player" << endl;
	cout << "2.Computer "<<endl;
	cout << "Enter your choice here: ";
	cin >> game_choice;
	if (game_choice=='1'){
		SetConsoleTextAttribute(hConsole, 9);

		cout << "Player one enter your name: ";
		cin >> first;
		SetConsoleTextAttribute(hConsole, 12);

		cout << "Player two enter your name: ";
		cin >> second;
		SetConsoleTextAttribute(hConsole, 9);
		cout << endl << endl << "                 " << first << " v";
		SetConsoleTextAttribute(hConsole, 12);
		cout << "s. " << second << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << freeP[i][j] << " ";
			}
			cout << endl;

		}
		for (int i = 0; i < 9;){
			player = switchPlayer(player);
			insertChar(player, position, first, second);
			drawChartB();
			//lookingForFreePositions();
			opa = isGameFinished(arr, first, second);
			if (opa){

				break;
			}
			i++;
		}
		if (!opa){
			SetConsoleTextAttribute(hConsole, 10);
			cout << "===>Draw game!";
		}
		cout << endl;
	}
	else if (game_choice=='2'){
		SetConsoleTextAttribute(hConsole, 7);
		cout << "You choose to play against the computer: "<<endl;
		insertCharComputer();
	}
	
	system("pause>nul");
}

void drawFreePositions(){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << freeP[i][j] << " ";
		}
		cout << endl;
	}
}
void insertCharComputer(){
	char player=' ';
	char turn = ' ';
	string yavor;
	string who;

	
	//string player = "";
	string computer = "John";
	
		turn = randomizePlayers(player);
		if (turn=='a'){
			cout << "Player please enter your name: ";
			cin >> yavor;
		    who = yavor;
			

		}
		else if (turn=='b'){
			cout << "Computers name is John!";
			who = computer;
		}
		if (who==yavor){
			

		}

		
		turn=switchPlayer(turn);

	
}
void drawChartA(){
	cout << "+-+-+-+" << endl;
	for (int i = 0; i < 3; i++){
		cout << "|";
		for (int j = 0; j < 3; j++){
			cout << arr[i][j] << "|";
		}
		cout << endl;
		cout << "+-+-+-+" << endl;
	}

}
// insert some char. Which player starts first:
void insertChar(char play, int position, string first, string second){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int row, col;
	string player;
	char pointX = 'x';
	char pointY = '0';
	//Who is the player who insert x or 0.
	if (play == 'a'){
		player = first;
		SetConsoleTextAttribute(hConsole, 9);
	}
	else if (play == 'b'){
		player = second;
		SetConsoleTextAttribute(hConsole, 12);
	}
	//Message to the player
	cout << endl << "Your turn " << player << "! Position? : ";
	cin >> position;
	//Check for existing positions
	
	if (position >= 1 && position <= 9){
		row = position / 3;
		col = position % 3;
		//Check for existing free positions
		if (arr[row][col - 1] != 'x' && arr[row][col - 1] != '0'){
			if (play == 'a'){
				arr[row][col - 1] = pointX;
			}
			else{
				arr[row][col - 1] = pointY;
			}
			cout << endl;
		}

		else{
			SetConsoleTextAttribute(hConsole, 14);
			cout << "Huge mistake my son! This position already have character! :D";
			insertChar(play, position, first, second);
		}
	}
	else{
		cout << "Failed!" << endl;
		insertChar(play, position, first, second);

	}
	
}

//Use method for switch players:
char switchPlayer(char play){
	// We use this function after every players input. Use switch-case to switch the players
	switch (play){
	case 'a':
		play = 'b';
		break;
	case 'b':
		play = 'a';
		break;
	case ' ':
		//This option is when we start: then the play variable has an empty value.
		play = randomizePlayers(play);
		break;
	}

	return play;
}
bool isGameFinished(char matrix[3][3], string first, string second){
	bool lookingForFinish;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, 12);
	//First case: Compare all first colon elements.

	if (matrix[0][0] == 'x' && matrix[1][0] == 'x' && matrix[2][0] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		lookingForFinish = true;
		cout << "===> " << first << " wins!";

	}
	else if (matrix[0][0] == '0' && matrix[1][0] == '0' && matrix[2][0] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins!";
		lookingForFinish = true;
	}
	else if (matrix[0][1] == 'x' && matrix[1][1] == 'x' && matrix[2][1] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		lookingForFinish = true;
		cout << "===> " << first << " wins!";
	}
	else if (matrix[0][1] == '0' && matrix[1][1] == '0' && matrix[2][1] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins!";
		lookingForFinish = true;
	}
	else if (matrix[0][2] == 'x' && matrix[1][2] == 'x' && matrix[2][2] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		cout << "===> " << first << " wins!";
		lookingForFinish = true;
	}
	else if (matrix[0][2] == '0' && matrix[1][2] == '0' && matrix[2][2] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins!";
		lookingForFinish = true;
	}
	//Fourth case: First row.
	else if (matrix[0][0] == 'x' && matrix[0][1] == 'x' && matrix[0][2] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		cout << "===> " << first << " wins!" << endl;
		lookingForFinish = true;
	}
	else if (matrix[0][0] == '0' && matrix[0][1] == '0' && matrix[0][2] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins!" << endl;
		lookingForFinish = true;
	}
	//Fifth case:Checking secondRow;
	else if (matrix[1][0] == 'x' && matrix[1][1] == 'x' && matrix[1][2] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		cout << "===> " << first << " wins!" << endl;
		lookingForFinish = true;
	}
	else if (matrix[1][0] == '0' && matrix[1][1] == '0' && matrix[1][2] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins!" << endl;
		lookingForFinish = true;
	}
	//Sixth Case: The last row:
	else if (matrix[2][0] == 'x' && matrix[2][1] == 'x' && matrix[2][2] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		cout << "===> " << first << " wins!" << endl;
		lookingForFinish = true;
	}
	else if (matrix[2][0] == '0' && matrix[2][1] == '0' && matrix[2][2] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins!" << endl;
		lookingForFinish = true;
	}
	//Case seven: Left diagonal!

	else if (matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		cout << "===> " << first << " wins!" << endl;
		lookingForFinish = true;
	}
	else if (matrix[0][0] == '0' && matrix[1][1] == '0' && matrix[2][2] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins!" << endl;
		lookingForFinish = true;
	}
	//Case eight: Right diagonal
	else if (matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x'){
		SetConsoleTextAttribute(hConsole, 9);
		cout << "===> " << first << " wins !" << endl;
		lookingForFinish = true;
	}
	else if (matrix[0][2] == '0' && matrix[1][1] == '0' && matrix[2][0] == '0'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << "===> " << second << " wins !" << endl;
		lookingForFinish = true;
	}
	else{
		lookingForFinish = false;
	}
	return lookingForFinish;

}

// Use method for make decissions who starts first.
char randomizePlayers(char play){
	srand(time(NULL));
	//We have a random number between 0 and 100. Condition 
	//if the number is odd player one starts first. Else player b.
	int variable = rand() % 100;
	if (variable % 2 == 0){
		play = 'a';

	}
	else{

		play = 'b';
	}
	return play;
}
// Comparssion and looking for finish the game

void drawChartB(){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int row = 0;
	char testChar = (char)186;
	SetConsoleTextAttribute(hConsole, 15);

	cout << (char)201 << (char)205 << (char)203 << (char)205 << (char)203 << (char)205 << (char)187 << endl;

	for (int i = 0; i < 5; i++){

		if (i % 2 == 0){
			cout << (char)186;

			for (int j = 0; j < 3; j++){
				if (arr[row][j] == 'x'){
					SetConsoleTextAttribute(hConsole, 9);
					cout << arr[row][j];
				}
				else if (arr[row][j] == '0'){
					SetConsoleTextAttribute(hConsole, 12);
					cout << arr[row][j];
				}
				else {
					SetConsoleTextAttribute(hConsole, 15);
					cout << arr[row][j];
				}
				SetConsoleTextAttribute(hConsole, 15);
				cout << (char)186;
			}
			cout << "                          ";
			for (int k = 0; k < 3; k++){
				cout << freeP[row][k] << " ";
			}
		}
		else{
			row++;
			cout << (char)204 << (char)205 << (char)206 << (char)205 << (char)206 << (char)205 << (char)185;
		}
		cout << endl;

	}
	cout << (char)200 << (char)205 << (char)202 << (char)205 << (char)202 << (char)205 << (char)188 << endl;


}
// Draw the desk with free positions: drawPositions():
void drawPositions(){

	for (int i = 0; i < 3; i++){

		for (int j = 0; j < 3; j++){
			cout << freeP[i][j] << " ";
		}
		cout << endl;

	}

}




