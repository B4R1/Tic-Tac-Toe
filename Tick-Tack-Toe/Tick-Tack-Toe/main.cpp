//Tic Tac Toe Game in C++

//Importing the inbuild libraries in CPP
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
//Array for the board
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
//Variable Declaration
int choice;
int row, column;
string player1;
string player2;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board

void player_name() {

    // Getting the player name
    cout << "Enter Player 1 Name" << endl;
    cin >> player1;
    cout << "Enter Player 2 Name" << endl;
    cin >> player2;

}

void display_board() {

    //Render Game Board LAYOUT

    cout << "Player[X]: " << player1 << " || ";
    cout << "Player[O]: " << player2 << endl;
    cout << "Make by TheLibrarian" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}

//Function to get the player input and update the board

void player_turn() {
    if (turn == 'X') {
        cout << "Player - " << player1 << " [X] turn : ";
    }
    else if (turn == 'O') {
        cout << "Player - " << player2 << " [O] turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin >> choice;

    //switch case to get which row and column will be update

    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        //if input position already filled
        cout << "Box already filled! Please choose another!";
        player_turn();
    }
    /* Ends */
    display_board();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover() {
    //checking the win for Simple Rows and Simple Column
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    //checking the win for both diagonal

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking the game is in continue mode or not
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout << "T I C K -- T A C -- T O E -- G A M E" << std::endl;
    cout << "FOR 2 PLAYERS" << std::endl;
    while (gameover()) {
        static bool initialized;
        if (!initialized) {
            initialized = true;
            player_name();
        }
        system("CLS");
        display_board();
        player_turn();
        system("CLS");
        gameover();
    }
    if (turn == 'O' && draw == false) {
        cout << "Congratulations!" << endl;
        cout << "Player " << player1 << " has won the game" << endl;
    }
    else if (turn == 'X' && draw == false) {
        cout << "Congratulations!" << endl;
        cout << "Player " << player2 << " has won the game" << endl;

    }
    else
        cout << "GAME DRAW!!" << std::endl;
    system("pause");
}