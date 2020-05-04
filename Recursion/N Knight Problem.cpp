/*
N_Knight Problem
Take as input N, the size of a chess board. We are asked to place N number of Knights in it, so that no knight can kill other.

a. Write a recursive function which returns the count of different distinct ways the knights can be placed across the board. Print the value returned.

b.Write a recursive function which prints all valid configurations (void is the return type for function).

Input Format
Enter the size of the chessboard N

Constraints
None

Output Format
Display the number of ways a knight can be placed and print all the possible arrangements in a space separated manner

Sample Input
2
Sample Output
{0-0} {0-1}  {0-0} {1-0}  {0-0} {1-1}  {0-1} {1-0}  {0-1} {1-1}  {1-0} {1-1} 
6
*/

#include <iostream>
using namespace std;

int totalCount = 0;

bool isSafe(int board[][100],int n,int r,int c) {
    if(r>=2 && c>=1 && board[r-2][c-1] == 1) {
        return false;
    }
    if(r>=2 && c+1<n && board[r-2][c+1] == 1) {
        return false;
    }
    if(r>=1 && c>=2 && board[r-1][c-2] == 1) {
        return false;
    }
    if(r>=1 && c+2<n && board[r-1][c+2] == 1) {
        return false;
    }
    if(r+2<n && c>=1 && board[r+2][c-1] == 1) {
        return false;
    }
    if(r+2<n && c+1<n && board[r+2][c+1] == 1) {
        return false;
    }
    if(r+1<n && c>=2 && board[r+1][c-2] == 1) {
        return false;
    }
    if(r+1<n && c+2<n && board[r+1][c+2] == 1) {
        return false;
    }

    return true;
}

void printBoard(int board[][100], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(board[i][j] == 1) {
                cout << "{" << i << "-" << j << "} ";
            }
            // cout << board[i][j] << " " ;
        }
        // cout << " " ;
        // cout << endl;
    }
    // cout << endl;
}

bool flag = false;

void knight(int n, int board[][100], int knightsPlaced, int r=0, int c=0) {
    // cout << "r = " << r << "    c = " << c << "     placed = " << knightsPlaced << endl;
    if(r==n && c==0) {
        // cout << "   End of board\n";
        return ;
    }

    if(knightsPlaced == n) {
        // cout << "totalCount = " << totalCount << endl; 
        // Print the configuration
        if(flag)
            cout << " ";
        flag = true;
        printBoard(board,n);
        totalCount++;
        return ;
    }

    if(c==n) {
        // cout << "   Row shift\n";
        return knight(n,board,knightsPlaced,r+1,0);
    }

    

    if(r<0 || c<0 || r>=n || c>=n || board[r][c] == 1) {
        // cout << "Invalid\n";
        return ;
    }

    if(!isSafe(board,n,r,c)) {
        // cout << "Unsafe\n";
        return knight(n, board, knightsPlaced, r, c+1);
    }

    board[r][c] = 1;
    knight(n, board, knightsPlaced+1, r, c+1);
    board[r][c] = 0;
    knight(n, board, knightsPlaced, r, c+1);
}

int main() {
    int n;
    cin >> n;


    int board[100][100] = {0};

    knight(n, board, 0);

    cout << endl << totalCount ;


    return 0;
}
