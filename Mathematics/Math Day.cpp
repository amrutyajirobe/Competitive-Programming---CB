/*
Math Day

Math Day is being celebrated at Coding Blocks. So Prateek Bhaiya rolled out a contest on Maths Problems. Here goes one.
Given three positive integers A,N,P. Compute AN! %P.


Input Format
The first line of the input gives the number of test cases, T. T lines follow.
Each line contains three integers A, N and P, as described above.

Constraints
1 = T = 100 1 = A = 10^5. 1 = N = 10^5. 1 = P = 10^5.

Output Format
For every test case, print the answer in a new line.

Sample Input
2
2 1 2
3 3 2
Sample Output
0
1
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int

ll fastPow(ll x,ll p,ll mod) {
    if(p == 0) {
        return 1;
    }
    ll smallAns = fastPow(x,p/2,mod);
    smallAns = (smallAns*smallAns)%mod;
    if(p&1)
        return (x*smallAns)%mod;
    return smallAns;
}

int main() {
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll a,n,p;
        cin >> a >> n >> p;
        for (int i = 1; i <= n; ++i) {
            a = fastPow(a,i,p) % p;
        }

        cout << a << endl;
    }
    return 0;
}
