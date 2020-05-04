/*
Let's Play Game

Alice is fond of playing mathematical games. This time he comes up with a unique game. He takes a number 'N' and calls magic fraction of N as:

It is a proper fraction (The value is < 1)
It cannot be reduced further
The product of the numerator and the denominator is factorial of N. i.e. if a/b is the fraction, then a*b = N!
For example magic fractions for 3 are 2/3 and 1/6.

Now given a number N, you need to print the total number of magic fractions that exist, for all numbers from 1 till N (both inclusive).
Input Format
Single line containing integral value 'N'.

Constraints
1<=N<=500

Output Format
Print integral value denoting total number of magic fractions.

Sample Input
3
Sample Output
3
*/
#include <iostream>
#include <vector>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define vi  vector<ll>

const ll limit = 1005;
vector<bool> sieve(limit,true);

void precomputePrimes() {
    for (int i = 0; i < limit; ++i) {
        sieve[i] = true;
    }

    sieve[0] = sieve[1] = false;

    for (int i = 4; i < limit; i += 2) {
        sieve[i] = false;
    }

    for (ll i = 3; i < limit; i += 2) {
        if (sieve[i]) {
            for (ll j = i * i; j  < limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() { 
    sync;
    ll n;
    cin >> n;
    precomputePrimes();
    if(n == 0 || n == 1) {
        cout << 0 ;
    }
    else if(n == 2) {
        cout << 1;
    }
    else {
        //Prime numbers increase contribution to answer by a factor of double
        ll term = 1;
        ll res = 1;
        for (int i = 3; i <= n; ++i) {
            if(sieve[i]) {
                term *= 2;
            }
            res += term;
            cout << res << endl;
        }

    }

    return 0;
}


