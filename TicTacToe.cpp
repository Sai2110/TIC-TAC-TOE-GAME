#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, col;
int choice;
int draw = false;
string n1, n2;

void drawboard()
{
    cout << endl;
    cout << "   " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "   " << "---------\n";
    cout << "   " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "   " << "---------\n";
    cout << "   " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << endl;
}
void placeMarker(int slot)
{
    row = slot / 3;
    col = (slot % 3) - 1;
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    cout << endl;
}
void player_turn()
{
    if (turn == 'X')
    {
        cout << n1 << "'s turn [X] = ";
    }
    else if (turn == 'O')
    {
        cout << n2 << "'s turn [O] = ";
    }
    cin >> choice;

    switch (choice)
    {
        case 1: row = 0, col = 0;
                break;
        case 2: row = 0, col = 1;
                break;
        case 3: row = 0, col = 2;
                break;
        case 4: row = 1, col = 0;
                break;
        case 5: row = 1, col = 1;
                break;
        case 6: row = 1, col = 2;
                break;
        case 7: row = 2, col = 0;
                break;
        case 8: row = 2, col = 1;
                break;
        case 9: row = 2, col = 2;
                break;
        default: cout << "invalid inputt!!" << endl;
    }

    if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][col] != 'O' && board[row][col] != 'X')
    {
        board[row][col] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "\nPlace is already filled...\nChoose another one !!!\n\n";
        player_turn();
    }
    // drawboard();
}

bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' || board[i][j] != 'O')
                return true;
        }
    }

    draw = true;
    return false;
}
int main()
{
    cout << endl<< "T I C  --  T A C  --  T O E \n";
    cout << "Two Player Game\n"; 

    cout << "\nEnter the name of the player: \n";

    cout << "\nplayer - 1 : ";
    getline(cin, n1);

    cout << "player - 2 : ";
    getline(cin, n2);

    cout << "\n  GAME START !!\n";

    while (gameover())
    {
        drawboard();
        player_turn();
        gameover();
    }

    drawboard();

    if(draw == true)
    {
        cout << "GAME DRAW !!!";
    }
    else if (turn == 'O' && draw == false)
    {
        cout << "CONGRATULATIONS !!!! \n"
             << n1 << " wins the game !!!";
    }
    else if (turn == 'X' && draw == false)
    {
        cout << "CONGRATULATIONS !!!! \n"
             << n2 << " wins the game !!!";
    }
    

    return 0;
}