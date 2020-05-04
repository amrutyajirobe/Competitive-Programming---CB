/*
SUMSUMS - Summing Sums
The N (1 = N = 50,000) cows, conveniently numbered 1, 2, …, N, are trying to learn some encryption algorithms. After studying a few examples, they have decided to make one of their own! However, they are not very experienced at this, so their algorithm is very simple:

Each cow i is given a starting number Ci (0 = Ci < 90,000,000), and then all the cows perform the following process in parallel:

First, each cow finds the sum of the numbers of the other N-1 cows. After all cows are finished, each cow replaces her number with the sum she computed. To avoid very large numbers, the cows will keep track of their numbers modulo 98,765,431. They told Canmuu the moose about it in November; he was quite impressed. Then one foggy Christmas Eve, Canmuu came to say:

"Your algorithm is too easy to break! You should repeat it T (1 = T = 1,414,213,562) times instead." Obviously, the cows were very frustrated with having to perform so many repetitions of the same boring algorithm, so after many hours of arguing, Canmuu and the cows reached a compromise: You are to calculate the numbers after the encryption is performed!

Input Format
Line 1: Two space-separated integers: N and T. Lines 2..N+1: Line i+1 contains a single integer: Ci.

Constraints
Output Format
Lines 1..N: Line i contains a single integer representing the number of cow i (modulo 98,765,431) at the end of the encryption.

Sample Input
3 4
1
0
4
Sample Output
26
25
29
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 98765431
#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

ll k;
vector<ll> b;

//Multiply two matrices
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{

    //third matrix mei result store
    vector<vector<ll>> C(k + 1, vector<ll>(k + 1));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int x = 1; x <= k; x++)
            {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;
            }
        }
    }

    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll p)
{

    //Base case
    if (p == 1)
    {
        return A;
    }
    //Rec Case
    if (p & 1)
    {
        return multiply(A, pow(A, p - 1));
    }
    else
    {

        vector<vector<ll>> X = pow(A, p / 2);
        return multiply(X, X);
    }
}

vector<ll> compute(ll n)
{
    //Base case
    if (n == 0)
    {
        return vector<ll>(k + 1, 0);
    }

    //Suppose n<=k
    if (n <= k)
    {
        return b;
    }

    //Otherwise we use matrix exponentiation, indexing 1 se
    vector<ll> F1(k + 1);

    for (int i = 1; i <= k; i++)
    {
        F1[i] = b[i - 1];
    }

    //2. Transformation matrix
    vector<vector<ll>> T(k + 1, vector<ll>(k + 1, 1));
    // Let init T

    for (int i = 0; i <= k; i++)
    {
        T[i][i] = 0;
    }

    // 3. T^n-1
    T = pow(T, n);

    // 4. multiply by F1
    ll res = 0;
    vector<ll> ans(k + 1, 0);
    for (int i = 1; i <= k; i++)
    {
        res = 0;
        for (int j = 1; j <= k; j++)
        {
            res = (res + (T[i][j] * F1[j]) % MOD) % MOD;
        }
        ans[i] = res;
    }

    return ans;
}

int main()
{
    sync;
    int n, t;
    cin >> n >> t;

    k = n;
    for (size_t i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b.push_back(x % MOD);
    }

    vector<ll> ans = compute(t);
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
