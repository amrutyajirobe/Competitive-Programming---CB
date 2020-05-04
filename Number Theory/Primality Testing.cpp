/*
Primality Testing

Alice thinks he has mastered number theory. Now Bob gave him some integers to check whether they are prime or not. Alice wants to watch a movie. So he needs your help to finish this task quickly.

Input Format
First line contains an integral value 'n' denoting the number of test cases. Then n lines follows each containing an integral value 'm'.

Constraints
1<=n<=1000 1<=m<=2^63-1

Output Format
Print "YES" or "NO" (without quotes) corresponding to each number whether they are prime or not.

Sample Input
2
1
2
Sample Output
NO
YES
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define vi  vector<ll>

const ll limit = 100000005;
unordered_map<ll,bool> dp;

vi primes;
void precomputePrimes() {
    vector<bool> sieve(limit,true);
    for (int i = 0; i < limit; ++i) {
        sieve[i] = true;
    }

    sieve[0] = sieve[1] = false;

    for (int i = 4; i < limit; i += 2) {
        sieve[i] = false;
    }

    primes.pb(2);
    for (ll i = 3; i < limit; i += 2) {
        if (sieve[i]) {
            primes.pb(i);
            for (ll j = i * i; j  < limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}

bool isPrime(ll n) {
    if(n == 1)  
        return false;
    ll i = 0;
    ll p = primes[0];
    while(i < primes.size()-1 and p*p <= n) {
        if(n%p == 0) {
            return false;
        }
        i++;
        p = primes[i];
    }


    return true;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    precomputePrimes();
    while (testCases--) {
        ll n;
        cin >> n;
        bool ans ;
        if(dp.find(n) == dp.end()) {
            ans = isPrime(n);
            dp[n] = ans ;
        }
        else {
            ans = dp[n];
        }
        if(ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
    }

    return 0;
}


