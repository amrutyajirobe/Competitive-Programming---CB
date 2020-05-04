/*
RANDOM QUERY
You are given an array a consisting of n positive integers. You pick two integer numbers l and r from 1 to n, inclusive (numbers are picked randomly, equiprobably and independently). If l?> r, then you swap values of l and r. You have to calculate the expected value of the number of unique elements in segment of the array from index l to index r, inclusive (1-indexed).

Input Format:
The first line contains one integer number The first line contains one integer number n . The second line contains n integer numbers a1, a2, … an — elements of the array. (1?=?ai?=?106)

Constraints:
1?=?n?=?10^6

Output Format
Print one number — the expected number of unique elements in chosen segment.
NOTE: Print your answer upto the precision of 6 decimal places.

Sample Input
2
1 2
Sample Output
1.500000
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX 10000006

ll a[MAX] = {0};
ll lastOcc[MAX] = {0};
ll ans[MAX] = {0};

int main() {
    int n ;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ans[0] = 0;
    double sum = 0;

    memset(lastOcc,0,sizeof(lastOcc));
    memset(ans,0,sizeof(ans));

    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i-1] + i - lastOcc[a[i]];
        lastOcc[a[i]] = i;
        sum += ans[i];
    }
   
    double finalAns = 0.0;
    finalAns = (double)(2*(sum-n)+n)/(double)(n*n*1.0);

    cout << fixed << setprecision(6) << finalAns << endl;


    return 0;
}
