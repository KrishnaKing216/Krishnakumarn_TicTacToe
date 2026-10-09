/*
Nandan Krishnakumar
TicTacToe - Galbraith C++/Data Structures
10/08/26 9:37 PM
Citations: Used ClaudeAI to debug on 10/8/26
*/
#include <iostream>

using namespace std;

void printBoard (char board[][3]); //Prototyping Functions
bool fullGrid(char board[][3]);
bool gameIsOver(char board[][3]);
int getValidRow();
char getValidColumn();

int main()
{
  char playerBoard[3][3] =
  {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };
  char turn = 'x';
  while (!gameIsOver(playerBoard))
  {
    printBoard(playerBoard);
    cout << "It's " << turn << "'s turn" << endl;
    int row = getValidRow();
    char colLetter = getValidColumn();
    int col;
    if (colLetter == 'a')
    {
        col = 0;
    }
    else if (colLetter == 'b')
    {
        col = 1;
    }
    else
    {
        col = 2;
    }
    
    if (turn == 'x')
    {
        playerBoard[row-1][col] = 'X';
        turn = 'o';
    }
    else
    {
        playerBoard[row-1][col] = 'O';
        turn = 'x';
    }
    
  }
  return 0;
}

void printBoard(char board[][3]) //printBoard function that reads each row of the board and makes a cstring out of the chars in each row with space in between
{
  cout << "  a b c" << endl;
  char rowString[6];
  int count = 0;
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
        {
          rowString[count] = board[i][j];
          rowString[count+1] = ' ';
          count += 2;
        }
      rowString[5] = '\0';
      cout << (char) ((i+1) +'0') << ' ' << rowString << endl;
      count = 0;
    }
}

bool fullGrid(char board[][3]) //function to checkif the board is full to check for a tie
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    
    return true;
}

bool gameIsOver(char board[][3]) //function to check win conditions
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && //Checks cols
        board[0][i] != ' ')
        {
            printBoard(board);
            cout << "Player " << board[0][i] << " wins!";
            return true;
        }
        
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && //checks rows
        board[i][0] != ' ')
        {
            cout << "Player " << board[i][0] << " wins!";
            return true;
        }
    }
    
    //Checks diagonals
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && 
    (board[0][0] != ' '))
    {
        printBoard(board);
        cout << "Player " << board[0][0] << " wins";
        return true;
    }
    
    if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && 
    (board[2][0] != ' '))
    {
        printBoard(board);
        cout << "Player " << board[2][0] << " wins";
        return true;
    }
    
    //checks tie
    if (fullGrid(board))
    {
        printBoard(board);
        cout << "Tie Game!";
        return true;
    }
    
    return false; //none of the win conditions are satisfied!
}

int getValidRow() //gets a valid input from the user for the row they wish to mark with their character
{
    while (true)
    {
        int row;
        cout << "Enter row (1-3)" << endl;
        cin >> row;
        if (cin.fail())
        {
            cout << "Enter a valid number" << endl;
            cin.clear();
        	cin.ignore(1000, '\n');
        	continue;
        }
        
        if (row >= 1 && row <= 3)
        {
            cin.clear();
        	cin.ignore(1000, '\n');
            return row;
        }
        cout << "Must be 1-3 inclusive!" << endl;
        
    }
}

char getValidColumn() //gets a valid input from the user for the col they wish to mark with their character
{
    while (true)
    {
        char column;
        cout << "Enter column (a-c)" << endl;
        cin >> column;
        if (cin.fail())
        {
            cout << "Enter a valid column letter" << endl;
            cin.clear();
        	cin.ignore(1000, '\n');
        	continue;
        }
        
        if (column >= 'a' && column <= 'c')
        {
            cin.clear();
        	cin.ignore(1000, '\n');
            return column;
        }
        cout << "Must be a-c inclusive and lowercase!" << endl;
        
    }
}