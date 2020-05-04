/*
Virat and nCr
Virat is learning to calculate nCr. Dhoni gave him some n and r values to solve for nCr. As the result can be large, he asked him to print (nCr % 1000000007).

Input Format
Single line containing two integers 'n' and 'r'.

Constraints
1<=n,r<=1000000 1<=r<=n

Output Format
Print the required output.

Sample Input
3 2
Sample Output
3
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

ll fact(ll n) {
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        res = (res*i)%MOD;
    }
    return res;
}

int main() { 
    sync;
    ll n,r;
    cin >> n >> r;
    ll x = fact(n);
    ll y = fact(r);
    ll z = fact(n-r);
    y = (y*z)%MOD;

    ll q = modInverse(y,MOD);

    ll ans = (x*q)%MOD;

    cout << ans;

    return 0;
}
