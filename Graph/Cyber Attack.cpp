/*
Cyber Attack
A group of hackers want hack a network connecting n cities. The network is such that there may or may not be a direct communication between two cities. But there is always a way to communicate from any city u to any other city v through a series of connections(For example, if the city 1 is directly connected to city 2 and city 2 is directly connected to city 3, then city 1 can communicate with city 3 through city 2). There is a hacker in each of the n cities. They wanted to block some of the connections for hacking, also they want to remain connected through network, i.e. after blocking some connections, still there should be a way of communication from every city of every other city so that hackers can communicate.
Hackers know that there is a cost associated with each direct connection. Since they have a limited amount of money, s, they want block as many connections as they can. Help them find the number of connections they can block.

Input Format
First line contains n, m and s, denoting the number of cities, number of direct connections, and the amount of money hackers have. Next m lines contains 3 integers each, u, v and c, denoting that there is a direct connection between node u and node v and the cost of breaking this connection is c.

Constraints
1<=s, c<=10^12 1<=n<=50000 1<=m<=100000 1<=u,v<=n, edges are unique, and there is no self loop.

Output Format
On the first line, print the number of connections hackers can block, w and the minimum cost of blocking, c. Note that there can be multiple possible sets of w connections, which can be removed within the sum of costs, s. Consider that set, S, such that the total cost of blocking is minimum.

Sample Input
6 7 10
1 2 3
1 3 3
2 3 3
3 4 1
4 5 5
5 6 4
4 6 5
Sample Output
2 7
Explanation
After blocking the edge between node 1 and node 2, and node 5 and node 6, the cities are still connected, and the cost of blocking is minimum and less than the value of s.
*/

/*
Approach : To find Maximum Spanning tree , use Kruskal Algorithm to find Minimum Spanning Tree first. Obtain the edges that have been discarded from it. Now sort these edges and try to put them into the tree one by one in reverse order until the total of discarded edges does not exceed the given cost.
*/
#include <bits/stdc++.h>
using namespace std;

#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define ll long long int

class Edge
{
public:
    ll src;
    ll dest;
    ll wt;
};

class Set
{
public:
    ll rank;
    ll parent;
};

ll find(Set *set, ll i)
{
    if (set[i].parent != i)
        set[i].parent = find(set, set[i].parent);

    return set[i].parent;
}

void Union(Set *set, ll u, ll v)
{
    ll uRoot = find(set, u);
    ll vRoot = find(set, v);
    if (set[uRoot].rank < set[vRoot].rank)
    {
        set[uRoot].parent = vRoot;
    }
    else if (set[uRoot].rank > set[vRoot].rank)
    {
        set[vRoot].parent = uRoot;
    }
    else
    {
        set[vRoot].parent = uRoot;
        set[uRoot].rank++;
    }
}

bool myCompare(Edge a, Edge b)
{
    return a.wt > b.wt;
}

void Kruskals(Edge *inp, ll n, ll e, ll s)
{
    sort(inp, inp + e, myCompare);
    Edge *out = new Edge[n - 1];
    Set *set = new Set[n];
    for (ll i = 0; i < n; i++)
    {
        set[i].rank = 0;
        set[i].parent = i;
    }

    ll counter = 0;
    ll i = 0;

    vector<Edge> discarded;
    // ll discardedEdgesWeight = 0;

    while (i < e)
    {
        Edge currentEdge = inp[i];
        ll srcParent = find(set, currentEdge.src);
        ll destParent = find(set, currentEdge.dest);
        if (srcParent == destParent)
        {
            discarded.push_back(currentEdge);
        }
        else {
        	Union(set, srcParent, destParent);
        }
        i++;
    }

    // ll totalWeight = 0;
    // for (ll j = 0; j < n - 1; j++)
    // {
    //     // cout << out[j].src << "->" << out[j].dest << " with weight =" << out[j].wt << endl;
    //     totalWeight += out[j].wt;
    // }

    sort(discarded.rbegin(), discarded.rend(), myCompare);

    ll discardedCostSoFar = 0;
    ll discardedCount = 0;
    for (auto it = discarded.begin(); it != discarded.end(); it++) {
        if(discardedCostSoFar + it->wt > s) {
            break;
        }
        discardedCostSoFar += it->wt;
        discardedCount++;
    }

    cout << discardedCount << " " << discardedCostSoFar << endl;

    // cout << "Total Weight = " << totalWeight << endl;

    // return totalWeight;
}

int main()
{
    sync;
    // cout << "No of vertices = ";
    ll V;
    cin >> V;

    // cout << "No of edges =";
    ll e;
    cin >> e;

    ll s;
    cin >> s;

    Edge *edge = new Edge[e];

    ll totalWeight = 0;

    for (ll i = 0; i < e; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edge[i].src = u;
        edge[i].dest = v;
        edge[i].wt = w;
        totalWeight += w;
    }

    Kruskals(edge, V, e, s);

    // cout << ans << endl;

    return 0;
}
