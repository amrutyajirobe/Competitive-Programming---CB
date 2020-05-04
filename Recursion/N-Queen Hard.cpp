/*
N-QUEEN HARD
You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.

Input Format:
A single integer N, denoting the size of chess board.

Constraints:
1 = N < 15

Output Format
A single integer denoting the count of solutions.

Sample Input
4
Sample Output
2
*/
#include <iostream>
using namespace std;

int n;
int ans = 0;
int DONE;

void solve(int rowMask, int ld, int rd) {
    if(rowMask == DONE) {
        ans++;
        return ;
    }

    int safe = DONE&(~(rowMask|ld|rd));

    while(safe) {
        int p = safe&(-safe) ;
        safe = safe - p;
        solve(rowMask|p, (ld|p)<<1, (rd|p)>>1);
    }
}

int main() {
    cin >> n;
    DONE = (1<<n) - 1;
    
    solve(0,0,0);

    cout << ans;

    return 0;
}
