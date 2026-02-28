#include <bits/stdc++.h>
using namespace std;
void printBoard(const vector<vector<char>> &board) {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}
void insert(vector<vector<char>> &board, unordered_map<int,bool>&mp,
                bool &isX,int position){
                    if(position>=1 || position<=9){
                     int row = (position - 1) / 3;
                int col = (position - 1) % 3;

                if(mp[position] == true)
                cout << "Position is already full--try again" << endl;
                else{
                    if(isX)
                    board[row][col]='X';
                    else
                    board[row][col]='O';

                    mp[position] = true;
                    isX=!isX;
                   
                }
                    }
              else{
                cout<< "Enter the valid position" << endl;
              }



        
}
bool checkWin(vector<vector<char>>& board, char player) {

    // Check Rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player &&
           board[i][1] == player &&
           board[i][2] == player)
            return true;
    }

    // Check Columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == player &&
           board[1][j] == player &&
           board[2][j] == player)
            return true;
    }

    // Main Diagonal
    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player)
        return true;

    // Anti-Diagonal
    if(board[0][2] == player &&
       board[1][1] == player &&
       board[2][0] == player)
        return true;

    return false;
}
int main(){
    int n;
    cout << "Enter the number of rounds you want to play--> " ;
    cin >> n;
        
        bool isX=true;
        bool isY=false;
        bool isFlag =false;
    while(n--){
          vector<vector<char>>board(3,vector<char>(3,' '));

   
 vector<vector<char>> temp = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

    if(!isFlag)
    {
         cout << "Let me introduce both of you with the positions" << endl;
           printBoard(temp);
           isFlag=true;
    }
      unordered_map<int,bool>mp;

    if(isX)
    cout << " <--Player 1 is getting the first chance--> " << endl;
    else
    cout << " <--Player 2 is getting the first chance--> " << endl;
   int a=9;
   bool isWin=false;
   while(a--){
    cout << "Before move status of game " << endl;
    printBoard(board);
    int position;
    if(isX)
    cout << "Player 1 enter the position--> " ;
    else
    cout << "Player 2 enter the position--> ";
    cin >> position;
    insert(board,mp,isX,position);
    cout << "After the move status of game" << endl;
    printBoard(board);

    cout << "Another player turn" << endl;
    char player=isX?'O' : 'X';
    if(checkWin(board,player))
    {
        isWin=true;
        if(player == 'X')
        {
            cout << "Player 1 wins wins the game " << endl;
        }
        else cout << "Player 2 wins the game" << endl;
        
        break;
    }
   }
   if(!isWin)
   cout << "No one wins the game" << endl;
    }
    isX=!isX;
 
}