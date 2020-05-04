/*
Game Theory - 2
You are given N piles of stones.
Each pile has some number of stones Mi.
Two players 1 and 2 play a game in which player 1 always moves first.
The rules are :-
1.Player will randomly choose 1 pile whose height is A and reduce the number of stones in that pile to B such that B is a divisor of A and B != A ( 1<= B < A).
2.Player who cannot make a move looses that is if all the piles are of size 1 the player will loose.
You have to find the winner.

Input Format
First line consists of number of test cases T. Each test case consists of an integer N. Then follow N integers denoting number of stones in ith pile.

Constraints
1 <= T <= 100 1 <= N <= 100 1 <= Mi <= 1000000

Output Format
First line consists of number of test cases T. Each test case consists of two integers N and M.

Sample Input
2
2 
1 2
3 
1 2 3
Sample Output
1
2
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<int> primes[1000005];
vector<bool> sieve(1000005, false);

void precomputeSieve()
{
    int n = 1000004;
    sieve[2] = true;
    for (int i = 3; i * i <= 100; i += 2)
    {
        sieve[i] = true;
    }

    for (ll i = 3; i * i <= 100; i += 2)
    {
        if (sieve[i])
        {
            for (ll j = i * i; j < 100; j += 2 * i)
            {
                sieve[j] = false;
            }
        }
    }

    for (ll i = 1; i < 1000004; i++)
    {
        for (ll j = i; j < 1000004; j += i)
        {
            primes[j].push_back(i);
        }
    }
}

ll mex(unordered_set<ll> &s)
{
    ll ans = 0;
    while (s.find(ans) != s.end())
    {
        ans++;
    }
    return ans;
}

ll grundy[1000005];

ll computeGrundy(ll n)
{
    if (n == 1)
        return 0;
    if (n == 2 || (n % 2 != 0 && sieve[n]))
        return 1;
    if (grundy[n] != -1)
        return grundy[n];
    ll size = primes[n].size();
    unordered_set<ll> Set;
    for (ll i = 0; i < size; i++)
    {
        if (primes[n][i] != n)
        {
            Set.insert(computeGrundy(primes[n][i]));
        }
    }

    return (grundy[n] = mex(Set));
}

int main()
{
    memset(grundy, -1, sizeof(grundy));
    precomputeSieve();
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll n, m;
        cin >> n;
        ll xorr = 0ll;
        for (int i = 0; i < n; ++i)
        {
            cin >> m;
            ll g = computeGrundy(m);
            xorr ^= g;
        }
        if (xorr)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "2" << endl;
        }
    }

    return 0;
}
