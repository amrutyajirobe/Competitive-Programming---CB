/*
Boston Numbers

A Boston number is a composite number, the sum of whose digits is the sum of the digits of its prime factors obtained as a result of prime factorization (excluding 1 ). The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. Write a program to check whether a given integer is a Boston number.

Input Format
There will be only one line of input:N , the number which needs to be checked.

Constraints
1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)

Output Format
1 if the number is a Boston number. 0 if the number is a not Boston number.

Sample Input
378
Sample Output
1
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

const ll limit = 10000005;
vector<bool> sieve(limit,true);
vi primes ; 

void precomputePrimes() {
    for (int i = 0; i < limit; ++i) {
        sieve[i] = true;
    }

    sieve[0] = sieve[1] = false;
    primes.pb(2);

    for (int i = 4; i < limit; i += 2) {
        sieve[i] = false;
    }

    for (ll i = 3; i < limit; i += 2) {
        if (sieve[i]) {
            primes.pb(i);
            for (ll j = i * i; j  < limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}
vi factorise(ll n) {
    vi v;
    for (int i = 0; i < primes.size(); ++i) {
        while(n%primes[i]==0) {
            v.pb(primes[i]);
            n/=primes[i];
        }
    }
    if(n!=1) {
        v.pb(n);
    }
    return v;
}

ll sumOfDigits(ll n) {
    ll s = 0;
    while(n) {
        ll r = n%10;
        s += r;
        n /= 10;
    }
    return s;
}

ll sumOfDigitsOfArray(vi &v) {
    ll sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        while(v[i]) {
            int r = v[i]%10;
            sum += r;
            v[i] /= 10;
        }
    }
    return sum;
}

int main() { 
    sync;
    precomputePrimes();
    ll n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    vi primeFactors = factorise(n);

    // for (int i = 0; i < primeFactors.size(); ++i) {
    //     cout << primeFactors[i] << " ";
    // }

    ll primeSum = sumOfDigitsOfArray(primeFactors);

    ll digitSum = sumOfDigits(n);

    // cout << endl << primeSum << endl << digitSum << endl;

    cout << (primeSum==digitSum) ;

    return 0;
}
