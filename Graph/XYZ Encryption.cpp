/*
XYZ Encryption
Mike has a string, s of length n and it consists of only 3 characters 'x', 'y' and 'z'. Now he wants to encrypt the string in the form of a graph. To convert the string into a graph, he considers n nodes numbered from 1 to n. There is an edge between node u and node v, if and only if:

*su* and *sv* are same.
*su* and *sv* are neighboring characters, i.e. "x"-"y" or "y"-"z".
Now he has lost the string, but he has a graph. He wants to check whether there is a string corresponding to this graph or not.
You can observe that a string will form only one graph, but a graph can represent multiple strings.

Input Format
First line contains two integers, n and m, denoting the number of nodes and the number of edges in the graph. Next m lines contains two integers each, u and v, denoting that there is an edge between them.

Constraints
1<=n<=500 0<=m<=n(n-1)/2 1<=u,v<=n, u is not equal to v. All the edges are unique.

Output Format
Print "Yes" if the given graph can represent a string(or strings). Print "No" otherwise.

Sample Input
3 1
1 2
Sample Output
Yes
Explanation
String "xxz" is one of the strings that will form the given graph
*/
#include <bits/stdc++.h>
using namespace std;

#define x 1
#define y 2
#define z 3

class Graph
{
private:
    vector<vector<bool>> adjMatrix;
    int V;

public:
    Graph(int n)
    {
        V = n;
        adjMatrix.resize(n+1);
        for (int i = 0; i < n+1; i++)
        {
            adjMatrix[i].resize(n+1);
        }
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }

    bool checkEncyption()
    {
        int u = -1;
        int v = -1;

        vector<int> val(V+1);

        for (int i = 1; i <= V && u == -1; i++)
        {
            for (int j = i + 1; j <= V; j++)
            {
                if (!adjMatrix[i][j])
                {
                    u = i;
                    v = j;
                    val[u] = x;
                    val[v] = z;
                    break;
                }
            }
        }

        if (u == -1)
        {
            return true;
        }

        for (int i = 1; i <= V; i++)
        {
            if (i == u || i == v)
            {
                continue;
            }

            if (adjMatrix[i][u] && adjMatrix[i][v])
            {
                val[i] = y;
            }
            else if (adjMatrix[i][u])
            {
                val[i] = x;
            }
            else if (adjMatrix[i][v])
            {
                val[i] = z;
            }
            else
            {
                return false;
            }
        }

        for (int i = 1; i <= V; i++)
        {
            for (int j = i + 1; j <= V; j++)
            {
                if (abs(val[i] - val[j]) <= 1 && !adjMatrix[i][j])
                {
                    return false;
                }
                if (abs(val[i] - val[j]) > 1 && adjMatrix[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    ~Graph() {}
};

int main()
{
    int V, E;
    cin >> V >> E;
    Graph g(V);
    while (E--)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    bool ans = g.checkEncyption();
    if (ans)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
