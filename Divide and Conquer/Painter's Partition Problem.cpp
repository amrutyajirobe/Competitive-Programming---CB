/*
Painter's Partition Problem
Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.

Note that:

Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.
Input Format
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.

Constraints
1 <= K <= 10 1 <= N <= 10 1<= Length Of Each Board <= 10^8

Output Format
Output the minimum time required to paint the board.

Sample Input
2
2
1 10
Sample Output
10
*/

#include <iostream>
using namespace std;
#define ll long long int
#define MOD 1000000007

bool isValidConfig(ll *walls,ll n,ll k,ll ans){
    ll painters = 1;
    ll timeTaken = 0;
    for(ll i=0;i<n;i++){
        if(timeTaken + walls[i] > ans){
            timeTaken = walls[i];
            painters++ ;
            if(painters > k){
                return false;
            }
        }
        else {
            timeTaken += walls[i];
        }
    }
    return true ;
}

ll painterProblem(ll *walls,ll n,ll k){
    ll totalTime = 0;           //Time taken if all walls are painted by a single painter
    ll s = 0 ;
    for(ll i=0;i<n;i++){
        totalTime += walls[i];
        s = max(s,walls[i]);
    }

    ll e = totalTime ;

    ll finalAns = s;

    while(s <= e){
        ll mid = (s+e)/2;
        if(isValidConfig(walls,n,k,mid)){
            finalAns = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return finalAns % MOD;
}


int main() {
    ll k ;      //No of painters
    cin >> k;
    ll n ;      //No of walls
    cin >> n;

    ll a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }

    cout << painterProblem(a,n,k);


    return 0;
}
