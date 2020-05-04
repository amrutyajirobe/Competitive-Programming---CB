/*
Game Theory - 1
You are given N piles of stones.
Each pile has same number of stones M.
Two players 1 and 2 play a game in which player 1 always moves first.
The rules are :-
1.Player will randomly choose 1 pile whose height is A and reduce the number of stones in that pile to B such that B is a divisor of A and B != A ( 1<= B < A).
2.Player who cannot make a move looses that is if all the piles are of size 1 the player will loose.
You have to find the winner.

Input Format
First line consists of number of test cases T. Each test case consists of two integers N and M.

Constraints
1 <= T <= 100 1 <= N,M <= 1000000

Output Format
Print 1 if player 1 wins else print 2.

Sample Input
2
2 2
1 4
Sample Output
2
1
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
    for (int i = 3; i*i <= 100; i += 2)
    {
        sieve[i] = true;
    }

    for (ll i = 3; i*i <= 100; i +=2)
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
        int n, m;
        cin >> n >> m;
        ll g = computeGrundy(m);
        if (g == 0) // if grundy is 0 then player cannot win at any condition
            cout << "2" << endl;
        else if (n & 1) // if g is the grundy number greater than 0 then xorring it odd times is g
            cout << "1" << endl;
        else
            cout << "2" << endl; // xorring even times is 0
    }

    return 0;
}
