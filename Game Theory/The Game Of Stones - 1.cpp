/*
The Game Of Stones - 1
Two players (numbered 1 and 2) are playing a game with stones. Player 1 always plays first, and the two players move in alternating turns. The game's rules are as follows:

In a single move, a player can remove either 2,3,or 5 stones from the game board. If a player is unable to make a move, that player loses the game. Given the number of stones, find and print the name of the winner (i.e.,First or Second) on a new line. Each player plays optimally, meaning they will not make a move that causes them to lose the game if some better, winning move exists.

NOTE :- Try solving the problem using property of Grundy numbers to learn the concept. Original Problem :- Hackerrank

Input Format
The first line contains an integer T, denoting the number of test cases. Each of the subsequent lines contains a single integer n , denoting the number of stones in a test case.

Constraints
1 <= T <= 100 1 <= N <= 100

Output Format
On a new line for each test case, print First if the first player is the winner; otherwise, print Second.

Sample Input
8
1
2
3
4
5
6
7
10
Sample Output
Second
First
First
First
First
First
Second
First
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll grundyDP[105];

ll mex(ll a,ll b,ll c) {
    ll ans = 0;
    while(ans==a || ans==b||ans==c) {
        ans++;
    }
    return ans;
}

ll grundy(ll n) {
    if(n<=1) {
        return 0;
    }

    if(grundyDP[n]!=-1) {
        return grundyDP[n];
    }

    grundyDP[n] = mex(grundy(n - 2), grundy(n - 3), grundy(n - 5));
    return grundyDP[n];
}

int main() {
    memset(grundyDP, -1, sizeof(grundyDP));
    int testCases;
    cin >> testCases;
    while(testCases--) {
        ll n;
        cin >> n;
        ll ans = grundy(n);
        if(ans==0){
            cout << "Second\n";
        }
        else{
            cout << "First\n";
        }
    }

    return 0;
}
