/*
Robot Collect Points
A robot is moving in two dimensional grid. The width of the grid has a fixed value of 5 while the height of the grid will be given. Robot starts to move from the middle of the width and just below the grid. It can move only in three directions.

1.) Left Upward

2.) Upward

3.) Right Upward

Imgur

Each cell of the grid is filled with a number (-1 or 0 or 1). When the Robot traverse from that cell, he will collect that number and sum up. The Robot has some power to make the value of all the cell of first 5 * 5 subgrids from -1 to 0. He can use that power only once. Can you help the Robot to get the maximum score?

Input Format
First line contains number t as number of test cases. Each test case contains a integer h as height of grid. Next h lines contains 5 space separated integer which is the value cell of the grid from top to bottom.

Constraints
• 1 = t = 10 • 1 = h = 12

Output Format
Print the maximum score collected by the robot durung traversing.

Sample Input
1
5
0 0 -1 1 0
0 0 0 1 0
0 -1 -1 -1 0
-1 0 1 0 0
0 1 -1 0 0
Sample Output
4
Explanation
Robot can use his power in the begining and collect number
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dp[20][20] ;

void robotPower(vector < vector < int > > &v, int r) {
    for(int i=r;i<r+5;i++) {
        for(int j=0;j<5;j++) {
            if(v[i][j] == -1) {
                v[i][j] = 0;
            }
        }
    }
    for(int i=0;i<20;i++) {
        for(int j=0;j<20;j++) {
            dp[i][j] = -1;
        }
    }
}

int robotCollect(int i,int j,const vector < vector < int > > &v) {
    // cout << "i = " << i << "    j = " << j << endl;
    if(i == -1) {
        // cout << "0 ret";
        return 0;
    }
    // if(i<0 ||j<0 || i>=v.size() || j>=v[0].size()){
    //     cout << i <<  " " << j << " " ;
    //     cout << "shit"; 
    //     return -1;
    // }

    // cout << "thik hai ";

    if(dp[i][j] != -1) {
        // cout << "dp value returned" ; 
        return dp[i][j];
    }

    int ans = -100;

    // cout << "ok so far";

    ans = max(ans, v[i][j] + robotCollect(i-1,j,v));

    // cout << "yha bhi shi ";
    if(j > 0) {
        ans = max(ans, v[i][j] + robotCollect(i-1,j-1,v));
    }
    if(j < 4) {
        ans = max(ans, v[i][j] + robotCollect(i-1,j+1,v));
    }

    dp[i][j] = ans; 

    return ans;
}

int main() {
    sync;
    int testCases;
    cin >> testCases;
    while(testCases--) {
        int n;
        cin >> n;
        vector < vector < int > > v(n+1, vector < int > (5,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<5;j++) {
                cin >> v[i][j];
            }
        }

        // cout << "ok";

        int finalAns = 0;
        for(int i=0;i<n-4;i++) {
            vector < vector < int > > temp = v;
            robotPower(temp,i);
            // for(int i=0;i<n;i++) {
            //     for(int j=0;j<5;j++) {
            //         cout << temp[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            int currentAns = robotCollect(n,2,temp);
            finalAns = max(finalAns, currentAns);
        }

        cout << finalAns << endl;
    
    }



    return 0;
}

