/*
Linear Congruence
Alice has mastered number theory, now he gives you the task of solving linear congruence. You need to print the minimum positive value of x which satisfy the following conditions:
x mod a0 = r0
x mod a1 = r1
.
.
x mod ak-1 = rk-1
Every pair in a0…….ak-1 is co-prime.

Input Format
First line contains single integer k. Second line contains numbers array 'a'. Third line contains remainder array 'r'.

Constraints
The product of all numbers in array 'a' will fit in long long int.

Output Format
Print integral value denoting minimum positive value of x satisfying the equations.

Sample Input
3
3 4 5
2 3 1
Sample Output
11
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

ll x, y;
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


ll modInverse (ll A, ll M)  {
    extendedEuclidAlgo(A, M);
    return (x % M + M) % M; //x may be negative
}

int main() { 
    sync;
    ll k;
    cin >> k;
    vi a(k),r(k);
    ll prod = 1;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        prod *= a[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> r[i];
    }

    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ll pp = prod /  a[i];
        ll inv = modInverse(pp, a[i]);
        ll temp = r[i]*pp*inv;
        ans = (ans+temp)%prod;
    }

    cout << ans;


    return 0;
}
