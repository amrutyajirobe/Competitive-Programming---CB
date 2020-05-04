/*
https://codeforces.com/problemset/problem/535/B

Tavas and SaDDas

Once again Tavas started eating coffee mix without water! Keione told him that it smells awful, but he didn't stop doing that. That's why Keione told his smart friend, SaDDas to punish him! SaDDas took Tavas' headphones and told him: "If you solve the following problem, I'll return it to you."


The problem is:

You are given a lucky number n. Lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

If we sort all lucky numbers in increasing order, what's the 1-based index of n?

Tavas is not as smart as SaDDas, so he asked you to do him a favor and solve this problem so he can have his headphones back.

Input
The first and only line of input contains a lucky number n (1?=?n?=?109).

Output
Print the index of n among all lucky numbers.

Examples
inputCopy
4
outputCopy
1
inputCopy
7
outputCopy
2
inputCopy
77
outputCopy
6
*/
#include <bits/stdc++.h>
using namespace std;

#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int tavvas(const string &s)
{
    int N = s.length();
    int ans = (1 << N) - 2;
    int pos = 0, i = N - 1;
    while (i >= 0)
    {
        if (s[i] == '7')
        {
            ans += (1 << pos);
        }
        i--;
        pos++;
    }
    return (ans + 1);
}

int main()
{
    sync;
    string s;
    cin >> s;

    cout << tavvas(s) << endl;

    return 0;
}
