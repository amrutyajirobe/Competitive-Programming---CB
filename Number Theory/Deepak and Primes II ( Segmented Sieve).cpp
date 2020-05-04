/*
Deepak and Primes II

After learning sieve of Eratosthenes, Deepak wants to play more with the primes. This time he is trying to print primes between two integers. Help him in this task.

Input Format
First line contains a single integer 'T' denoting number of test cases. Then 'T' lines follow each containing two integers 'm' and 'n'.

Constraints
1<=T<=10 1<=m<=n<=1000000000, n-m<=100000

Output Format
Print the prime numbers from 'm' till 'n' (both inclusive), one number per line and each test case is separated by an empty line.

Sample Input
2
5 10
11 20
Sample Output
5
7

11
13
17
19
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool sieve[1000001];

void precompute()
{
    for (int i = 0; i < 1000001; ++i)
    {
        sieve[i] = true;
    }

    sieve[0] = sieve[1] = false;

    for (int i = 4; i < 1000001; i += 2)
    {
        sieve[i] = false;
    }

    for (ll i = 3; i < 1000001; i += 2)
    {
        if (sieve[i])
        {
            for (ll j = i * i; j  < 1000001; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

void segmentedSieve (ll a, ll b)
{

    bool segSieve[b - a + 1];
    fill (segSieve, segSieve + b - a + 1, 1);

    for (int i = 2; i * i <= b; i++)
    {
        if (sieve[i])
        {
            for (int j = a; j <= b; j++)
            {
                if (j % i == 0 && j != i)
                {
                    segSieve[j - a] = 0;
                }
            }
        }
    }

    if (a != 1)
    {
        for (ll i = a; i <= b; i++)
        {
            if (segSieve[i - a])
            {
                cout << i << endl;
            }
        }
    }
    else
    {
        for (ll i = 2; i <= b; i++)
        {
            if (segSieve[i - a])
            {
                cout << i << endl;
            }
        }
    }

}


int main()
{
    int testCases;
    cin >> testCases;
    precompute();

    while (testCases--)
    {
        ll a;
        cin >> a;
        ll b;
        cin >> b;
        segmentedSieve (a, b);
        cout << endl;
    }

    return 0;
}

