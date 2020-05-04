/*
Siddharth and Permutations
Siddharth has discovered a new way to encode permutations. If he has a permutation P?=?[p1,?p2,?…,?pn], he will encode it in the following way:

Denote by A?=?[a1,?a2,?…,?an] a sequence of length n which will represent the code of the permutation. For each i from 1 to n sequentially, he will choose the smallest unmarked j (1?=?j?=?n) such that pi?<?pj and will assign to ai the number j (in other words he performs ai?=?j) and will mark j. If there is no such j, he'll assign to ai the number ?-?1 (he performs ai?=??-?1).

Siddharth forgot his original permutation but he remembers its code. Your task is simple: find any permutation such that its code is the same as the code of Siddharth's original permutation.

You may assume that there will always be at least one valid permutation.

Input Format
The first line contains single integer n (1?=?n?=?500?000) — length of permutation.

The second line contains n space-separated integers a1,?a2,?…,?an (1?=?ai?=?n or ai?=??-?1) — the code of Mike's permutation.

You may assume that all positive values from A are different.

Constraints
Present in Problem Statement

Output Format
In first and only line print n numbers p1,?p2,?…,?pn (1?=?pi?=?n) — a permutation P which has the same code as the given one. Note that numbers in permutation are distinct.

Sample Input
6
2 -1 1 5 -1 4
Sample Output
2 6 1 4 5 3
Explanation
Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair

const int MAXN = 500005;
pair<int, int> segmentTree[MAXN << 2];
int a[MAXN], b[MAXN], ans[MAXN];
bool visited[MAXN];
int n;
vector<int> sv;

void build(int l, int r, int index)
{
    if (l == r)
    {
        segmentTree[index] = mp(b[l], l);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, index << 1);
    build(mid + 1, r, (index << 1) + 1);
    segmentTree[index] = max(segmentTree[index << 1], segmentTree[(index << 1) + 1]);
}

void update(int pos, int val, int l, int r, int index)
{
    if (l == r)
    {
        segmentTree[index] = mp(val, segmentTree[index].ss);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        update(pos, val, l, mid, index << 1);
    }
    else
    {
        update(pos, val, mid + 1, r, (index << 1) + 1);
    }
    segmentTree[index] = max(segmentTree[index << 1], segmentTree[(index << 1) + 1]);
}

pair<int, int> query(int L, int R, int l, int r, int index)
{
    pair<int, int> ret;
    if (L > R)
    {
        return mp(0, 0);
    }
    if (L <= l && r <= R)
    {
        return segmentTree[index];
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
    {
        ret = max(ret, query(L, R, l, mid, index << 1));
    }
    if (R > mid)
    {
        ret = max(ret, query(L, R, mid + 1, r, (index << 1) + 1));
    }
    return ret;
}

void dfs(int node)
{
    visited[node] = true;
    update(node, 0, 1, n, 1);
    if (b[node] != n + 1 && !visited[b[node]])
    {
        dfs(b[node]);
    }
    while (1)
    {
        pair<int, int> mx = query(1, a[node] - 1, 1, n, 1);
        if (mx.ff > node)
        {
            dfs(mx.ss);
        }
        else
        {
            break;
        }
    }
    sv.push_back(node);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = n + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            b[a[i]] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
        {
            a[i] = n + 1;
        }
    }
    build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    for (int i = 0; i < sv.size(); i++)
    {
        ans[sv[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
