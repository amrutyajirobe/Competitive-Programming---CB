/*
Sakshi and Art
Sakshi is an artist. She is given a task to draw a figure with some basic specifications on a sheet. Specifications of the figure is given by m lines. Each line contains four integers, x1, y1, x2, y2, denoting that there is a line to be drawn between points (x1, y1), (x2, y2). She can add some more specifications according to her needs. Sakshi wants to draw it in a creative manner. She wants to draw the whole figure in one stroke of her pen, i.e. if the pen is at point (x1, y1) and she wants to reach point (x2, y2), then there must be a series of lines(or a single line) connecting points (x1, y1) and (x2, y2).
Origin is the bottom left corner of the sheet. Find out the minimum number of lines to be added in the specifications of the figure in order to draw the figure in a single stroke of her pen.
Note: Drawing a line which is already drawn, doubles the width of line and thus it can be added to specifications, i.e. if a line is drawn again, it is treated as a distinct line in the specifications. Also, in the given specifications, no three points are collinear.

Input Format
First line contains contains a single integer m, denoting the number of basic specifications. Next m lines contains four integers, x1, y1, x2, y2 each, denoting that there is a line between points (x1, y1), (x2, y2).

Constraints
1<=m<=10^5 1<=x1,y1,x2,y2<=10^9

Output Format
Print a single integer denoting the minimum number of lines to be added in the specifications of the figure.

Sample Input
2
1 1 2 1
2 2 1 2
Sample Output
1
Explanation
Sakshi can add the line between point (2,2) and (1,1). Sakshi will now start at point (2,1). She will draw lines in the following way: (2,1)->(1,1) (1,1)->(2,2) (2,2)->(1,2) In this way figure is complete.

*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll long long int
#define pii pair<ll, ll>
#define vi vector<ll>

class Graph
{
private:
    map<pii, list<pii>> adjList;

public:
    Graph() {}

    void addEdge(pii u, pii v)
    {
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    //Returns odd degree count
    ll dfsHelper(pii node, map<pii, bool> &visited, map<pii, int> &degree)
    {
        visited[node] = true;

        ll ans = 0;
        if (degree[node] & 1)
        {
            ans++;
        }

        for (auto it : adjList[node])
        {
            if (!visited[it])
            {
                ans += dfsHelper(it, visited, degree);
            }
        }

        return ans;
    }

    ll dfs()
    {
        int component = 0;
        map<pii, bool> visited;
        map<pii, int> degree;

        for (auto it : adjList)
        {
            for (auto child : adjList[it.first])
            {
                degree[child]++;
            }
        }

        ll totalOddDegreeCount = 0;

        for (auto it : adjList)
        {
            auto node = it.first;
            if (!visited[node])
            {
                ll oddDegreeCount = dfsHelper(node, visited, degree);
                if (oddDegreeCount == 0)
                    oddDegreeCount = 2;

                totalOddDegreeCount += oddDegreeCount;
                component++;
            }
        }

        return (totalOddDegreeCount - 2) / 2;
    }

    ~Graph() {}
};

int main()
{
    sync;

    Graph g;

    int e;
    cin >> e;
    while (e--)
    {
        pii u;
        cin >> u.ff >> u.ss;
        pii v;
        cin >> v.ff >> v.ss;
        g.addEdge(u, v);
    }

    ll ans = g.dfs();

    cout << ans << endl;

    return 0;
}
