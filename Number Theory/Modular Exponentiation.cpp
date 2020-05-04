/*
Modular Exponentiation
Given three numbers a,b,c. Calculate (a^b)mod c.

Input Format
Single line containing three integers a,b,c separated by space.

Constraints
1<=a,b,c<=100000

Output Format
Print (a^b)mod c.

Sample Input
2 2 3
Sample Output
1
*/

//Both functions are working fine

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll modPowRecursive(ll a,ll b,ll m) {
    if(b == 0) {
        return 1;
    }
    ll smallAns = modPowRecursive(a,b/2,m);
    smallAns = (smallAns*smallAns)%m;

    if(b&1) {
        return (a*smallAns)%m;
    }
    return smallAns%m;
}

ll modPowBitmasking(ll a,ll b,ll m) {
    ll res = 1;
    while(b) {
        if(b&1) {
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b >> 1;
    }
    return res;
}

int main() {
    ll a,b,c;
    cin >> a >> b >> c;

    cout << modPowRecursive(a,b,c) ;

    //cout << modPowBitmasking(a,b,c) ;

    return 0;
}
