/*
Query Bits
You are given an n-bit integer (initially 0). There are Q queries. Each query is of following type:

0 L R: Set all the bits from Lth bit to Rth bit to zero.
1 L R: Set all the bits from Lth bit to Rth bit to one.
2 L R: Find the integer formed by the bits in range [L, R]. Answer all the queries of type 2. Indexing is 0-based. See the sample test case for clarity.
Input Format
First line contains two integers, nand q. Next Q lines contains Q queries.

Constraints
1<=n,q<=200000 0<=L,R<n

Output Format
For each query of type 2, print the integer(in decimal) formed by it modulo 109+7.

Sample Input
3 6
1 0 1
2 0 2
0 1 1
2 1 1
1 2 2
2 0 2
Sample Output
6
0
5
Explanation
Initially the integer in binary is "000". After first query, it becomes, 110(=6). Answer to next query comes out to be 6, i.e. "110" in decimal. After 3rd query, it becomes "100". Answer to 4th query is 0,i.e. decimal of "0". After 5th query, it becomes, "101" and thus answer to the last query comes out to be 5, i.e. "101" i decimal

*/
#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007ll

using namespace std;

#define SIZE 200100

ll pow(ll a, ll p, ll m = MOD)
{
    ll res = 1;
    while (p > 0)
    {
        if (p & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

ll segTree[SIZE << 2], lazy[SIZE << 2];

void lazyUpdate(int node, int start, int end)
{
    if (lazy[node] != -1)
    {
        segTree[node] = (pow(2, end - start + 1, MOD) - 1) * lazy[node];
        if (start != end)
        {
            lazy[(node << 1) + 1] = lazy[node];
            lazy[(node << 1) + 2] = lazy[node];
        }
        lazy[node] = -1;
    }
}

void update(int node, int start, int end, int l, int r, int x)
{
    lazyUpdate(node, start, end); //updating pendding lazy updates.
    if (start > r || end < l)
    {
        return;
    }
    if (start >= l && end <= r)
    {
        segTree[node] = (pow(2, end - start + 1, MOD) - 1) * x;
        if (start != end)
        {
            lazy[(node << 1) + 1] = x;
            lazy[(node << 1) + 2] = x;
        }
        return;
    }
    int mid = (start + end) >> 1;
    update((node << 1) + 1, start, mid, l, r, x);
    update((node << 1) + 2, mid + 1, end, l, r, x);
    segTree[node] = (segTree[(node << 1) + 1] * pow(2, end - mid, MOD) % MOD + segTree[(node << 1) + 2]) % MOD; //merging childrend to form parendt
}

ll query(int node, int start, int end, int l, int r)
{
    lazyUpdate(node, start, end); //updating pendding lazy updates.
    if (start > r || end < l)
    {
        return 0;
    }
    if (start >= l && end <= r)
    {
        return segTree[node];
    }
    int mid = (start + end) >> 1;
    int leftAns = query((node << 1) + 1, start, mid, l, r);
    int rightAns = query((node << 1) + 2, mid + 1, end, l, r);
    if (r <= mid)
        return leftAns;
    return (leftAns * pow(2, min(end, r) - mid, MOD) % MOD + rightAns) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;

    while (q--)
    {
        int x, l, r;
        cin >> x >> l >> r;
        if (x < 2)
        {
            update(0, 0, n - 1, l, r, x);
        }
        else
        {
            ll ans = query(0, 0, n - 1, l, r);
            cout << ans << endl;
        }
    }

    return 0;
}
