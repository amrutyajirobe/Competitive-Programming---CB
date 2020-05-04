/*
Multiplicative Inverse


Given a number n. Print the multiplicative inverse of “n modulo 1000000007” .

Input Format
Single line containing an integer value.

Constraints
1<=n<=1000000

Output Format
Integral value representing the multiplicative inverse.

Sample Input
3
Sample Output
333333336
{...} Code Editor
*/

#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll  long long int


ll x,y;
void extendedEuclidAlgo(ll a,ll b) {
    if(b == 0) {
        x = 1;
        y = 0;
        return ;
    }
    extendedEuclidAlgo(b, a%b);
    ll cX = y;
    ll cY = x - (a/b)*y;
    x = cX;
    y = cY;
}

ll inverseModulo(ll a,ll m) {
    extendedEuclidAlgo(a,m);
    return (x+m)%m;
}

int main() { 
    sync;
    ll n;
    cin >> n;
    ll MOD = 1000000007;

    cout << inverseModulo(n,MOD) << endl;



    return 0;
}
