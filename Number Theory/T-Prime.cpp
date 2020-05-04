/*
T-Prime

We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t ?-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is ?-prime or not.

Input Format
First Line : n , Number of elements in an array Second Line : xi ( i from 1 to n)

Constraints
n <= 10^5 xi <= 10^12

Output Format
YES if its T-Prime NO if its not a T-Prime

Sample Input
3
4 5 6
Sample Output
YES
NO
NO
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<ll>

const ll limit = 1000005;
bool sieve[limit];

void precompute() {
    memset(sieve,true,sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for (int i = 4; i < limit; i+=2) {
        sieve[i] = false;
    }

    for (ll i = 3; i < limit; i+=2) {
        if(sieve[i]) {
            for (ll j = i*i; j  < limit; j+=i) {
                sieve[j] = false;       
            }
        }
    }
}

bool isTPrime(ll x) {
    //Number is t-prime if it is a square of a prime number
    ll sq = sqrt(x);
    if(sq*sq != x) {
        return false;
    }
    if(sieve[sq]) {
        return true;
    }
    return false;
}

int main() { 
    sync;

    precompute();


    ll n;
    cin >> n;

    ll x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        bool ans = isTPrime(x);
        if(ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }



    return 0;
}
