/*
LIS Modified!
You are given a sequence of N integers A denoted by A[1] , A[2]…..A[N].
Each integer in the sequence has a value associated with it W[1],W[2]…. W[N].
You have to select a subsequence of given array A such that all the elements in A are in strictly increasing order and sum of values of elements in this selected subsequence is maximum. You have to print this maximum value.

Input Format
The first line of input contains a single integer T. T test-cases follow. The first line of each test-case contains an integer N. The next line contains a1, a2 ,… , aN separated by a single space. The next line contains w1, w2, …, wN separated by a single space.

Constraints
1 <= T <= 5 1 <= N <= 200000 1 <= a[i] <= 10^9, where i ? [1..N] 1 <= w[i] <= 10^9, where i ? [1..N]

Output Format
For each test-case output a single integer: The maximum sum of values of increasing subsequences of the given sequence.

Sample Input
2
4
1 2 3 4
100 200 300 400
3
4 2 3
100 30 20
Sample Output
1000
100
Explanation
In the first test case we will take the sequence as whole array hence answer is 1000. In the second test case if we take only first element we get sum as 100.
*/
#include <bits/stdc++.h>
using namespace std;

#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long int

const ll N = 155000;
ll BIT[N];

long long f[N];
ll a[N], w[N];

void update(ll i, ll val)
{
    i++;
    while (i <= N - 1)
    {
        BIT[i] = max(BIT[i], val);
        i = i + (i & (-i));
    }
}

ll query(ll i)
{
    ll res = 0;
    i++;
    while (i > 0)
    {
        res = max(res, BIT[i]);
        i = i - (i & (-i));
    }
    return res;
}

void coordinateCompress(ll *a, ll n)
{
    ll temp[200005];
    for (ll i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }

    sort(temp, temp + n);
    ll m = unique(temp, temp + n) - temp;

    for (ll i = 0; i < n; i++)
        a[i] = lower_bound(temp, temp + m, a[i]) - temp;
}

int main()
{
    sync;
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        memset(f, 0, sizeof(f));
        memset(BIT, 0, sizeof(BIT));

        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        coordinateCompress(a, n);

        // cout << "Compressed array = ";
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        for (ll i = 0; i < n; i++)
            cin >> w[i];

        long long ans = 0;
        for (ll i = 0; i < n; i++)
        {
            // cout << "i = " << i << endl;
            f[i] = query(a[i] - 1) + w[i];
            ans = max(ans, f[i]);
            update(a[i], f[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
