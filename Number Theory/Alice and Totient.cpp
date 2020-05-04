/*
Alice and Totient
Alice is given the task of finding totient f of a positive integer n (the number of positive integers less than or equal to n that are co-prime to n). As Alice is going on a date, he asks you to write a program for this.

Input Format
First line of input of consists of an integer 't' denoting the number of test cases. Then 't' lines follow each containing integer values 'n' to calculate totient.

Constraints
1<=t<=50000 1<=n<=10^6

Output Format
Print 't' lines

Sample Input
2
2
3
Sample Output
1
2
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

vi primes;
void precomputePrimes() {
    vector<bool> sieve(1000005,true);
    for (int i = 0; i < 1000001; ++i) {
        sieve[i] = true;
    }

    sieve[0] = sieve[1] = false;

    for (int i = 4; i < 1000001; i += 2) {
        sieve[i] = false;
    }

    primes.pb(2);
    for (ll i = 3; i < 1000001; i += 2) {
        if (sieve[i]) {
            primes.pb(i);
            for (ll j = i * i; j  < 1000001; j += i) {
                sieve[j] = false;
            }
        }
    }
}

vi primeFactorise(ll n) {
    vi factors;
    ll p = primes[0];
    ll i = 0;
    while(p*p <= n) {
        if(n % p == 0) {
            factors.pb(p);
            while(n % p == 0) {
                n /= p;
            }
        }
        i++;
        p = primes[i];
    }
    if(n != 1) {
        factors.pb(n);
    }

    return factors;
}

ll totient(ll n) {
    vi factors = primeFactorise(n) ;
    // cout << "Primes factorisation of " << n << " - " ;
    // for (int i = 0; i < factors.size(); ++i) {
    //     cout << factors[i] << " ," ;
    // }
    // cout << endl;
    double ans = n;
    for (int i = 0; i < factors.size(); ++i) {
        ans = ans * (1.0 - (1/(double)(factors[i])));
    }
    return ans;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;

    precomputePrimes();

    while (testCases--) {
        ll n;
        cin >> n;
        cout << totient(n) << endl;
    }

    return 0;
}
