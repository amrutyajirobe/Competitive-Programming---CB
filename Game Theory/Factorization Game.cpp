/*
Factorization Game
Mancunian and his arch-enemy Liverbird are playing a game. They have a multiset of positive integers available and they alternate turns. Mancunian always starts.

Each move consists of choosing some prime number p and then choosing a non-empty subset of the multiset such that each element of the subset is divisible by p. Then, the player divides each member of the subset by some non-zero power of p.

Note that the element must be divisible by pa if you are performing division by pa For example, if the chosen prime is 3 then 18 is divisible by 9 but not by 27 Also, it is not necessary to divide each element of the subset with the same power of p.

Input Format
The first line contains a single integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the number of elements in the multiset S The second line of each test case contains N integers denoting the elements of the multiset.

Constraints
1=T=20 1=N=10000 1 <= each element <= 10^6

Output Format
For each test case, print the name of the winning player in a new line.

Sample Input
2
4
1 2 3 5
4
3 18 2 2
Sample Output
Mancunian
Liverbird
Explanation
Consider the first case. In the first move, Mancunian chooses one prime from the set {2, 3, 5}. If he chooses 2, then he has to choose the subset containing only the value 2 from the array and divide it by 2. In the next move, Liverbird chooses one of the primes {3, 5}. If he chooses 3, then he has to choose the subset containing only the value 3 from the array and divide it by 3. In the last move, Mancunian repeats the same with the prime 5. Liverbird cannot make a move and he loses. All other possible paths of the game are analogous to this one.

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

ll factor[2000006], freq[2000006];
void sieve()
{
    for (ll i = 3; i <= 1000006; i += 2)
    {
        if (factor[i] == 0)
        {
            factor[i] = i;
            for (ll j = i * i; j <= 1000006; j += 2 * i)
            {
                if (factor[j] == 0)
                {
                    //debug(j);
                    factor[j] = i;
                }
            }
        }
    }
}

int main()
{
    sync;
    sieve();
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        memset(freq, 0, sizeof(freq));
        ll n;
        cin >> n;
        ll xorr = 0;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            while (x > 1 && x % 2 == 0)
            {
                x /= 2;
                freq[2]++;
            }
            while (x > 1)
            {
                ll p = factor[x];
                while (x > 1 && x % p == 0)
                {
                    freq[p]++;
                    x /= p;
                }
            }
        }

        for (int i = 2; i <= 1000006; i++)
        {
            xorr = xorr ^ freq[i];
        }
        if (xorr)
            cout << "Mancunian";
        else
            cout << "Liverbird";
        cout << endl;
    }
    return 0;
}
