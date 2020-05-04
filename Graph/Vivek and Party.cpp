/*
Vivek has just finished college and decided to go out with friends. Vivek has some strange habits and thus he decided to celebrate this important moment of his life drinking a lot. He will start drinking beverages with low alcohol content, like beer, and then will move to a beverage that contains more alcohol, like wine, until there are no more available beverages. Once Vivek starts to drink wine he will not drink beer again, so the alcohol content of the beverages never decreases with the time.

You should help Vivek by indicating an order in which he can drink the beverages in the way he wishes.

Input Format
Each test case starts with 1 <= N <= 100, the number of available beverage. Then will follow N lines, informing the name of each beverage, a name has less than 51 characters and has no white space .

Then next M (less than 200) lines contains two Strings B1 and B2, names of the beverages which states that the B2 contains more alcohol than B1 , and Vivek has to drink B1 before B2.

There is a blank line after each test case .In the case there is no relation between two beverages Dilbert should start drinking the one that appears first in the input. The input is terminated by end of line (EOF).

Constraints
1 <= N <= 100 1 <= M <= 200 1 <= length of Bi <= 60

Output Format
For each test case you must print the message: 'Case #C: Vivek should drink beverages in this order: B1 B2 …… Bn.'

where C is the number of the test case, starting from 1, and B1 B2…Bn is a list of the beverages such that the alcohol content of beverage B(i+1) should not less than B(i).After each test case you must print a blank line.

Sample Input
8
a
b
c
d
e
f
s
t
6
a e
a b
c d
e f
s t
a t

8
s
a
b
e
f
c
d
t
6
a e
a b
c d
e f
s t
a t

Sample Output
Case #1: Vivek should drink beverages in this order: a b c d e f s t.

Case #2: Vivek should drink beverages in this order: s a b e f c d t.
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

class Functor {
public:
    bool operator()(string a,string b) {
        return mp[a]<mp[b];
    }
};


class Graph
{
private:
    map<string, list<string>> adjList;
    int V;

public:
    Graph(int n) { 
		V = n; 
        mp.clear();
	}

    void init(const vector<string> v)
    {
        for (int i = 0; i < V; i++)
        {
            adjList[v[i]];
            mp[v[i]]=i;
        }
    }

    void addEdge(const string &u, const string &v)
    {
        // adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfsHelper(string node, map<string, bool> &visited, list<string> &ordering)
    {
        visited[node] = true;
        for (auto x : adjList[node])
        {
            if (!visited[x])
            {
                dfsHelper(x, visited, ordering);
            }
        }

        ordering.push_back(node);
    }

    void dfsTopologicalSort(const vector<string> &v)
    {
        map<string, bool> visited;
        list<string> ordering;
        for (auto it : v)
        {
            if (!visited[it])
            {
                dfsHelper(it, visited, ordering);
            }
        }

        for (auto it : ordering)
        {
            cout << it << " ";
        }
    }

    void bfsTopologicalSort(const vector<string> &v)
    {
        priority_queue<string, vector<string>, Functor> q;
        map<string, bool> visited;
        map<string, int> indegree;
        for (auto it : v)
        {
            visited[it] = false;
            indegree[it] = 0;
        }

        for (auto it : adjList)
        {
            auto u = it.first;
            for (auto v : adjList[u])
            {
                indegree[v]++;
            }
        }

        for (auto i : adjList)
        {
            auto node = i.first;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        vector<string> order;

        int i = 0;
        while (!q.empty())
        {
            auto node = q.top();
            q.pop();
            order.push_back(node);
            i++;
            for (string x : adjList[node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }

        reverse(order.begin(), order.end());

        for (int i = 0; i < order.size(); i++)
        {
            cout << " " << order[i];
        }
        cout<<".";

        cout << endl;
    }

    ~Graph() {}
};

int main()
{
    int c = 1;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Graph g(n);
        vector<string> beverages(n);
        for (int i = 0; i < n; i++)
        {
            cin >> beverages[i];
        }

        g.init(beverages);

        int m;
        cin >> m;
        while (m--)
        {
            string a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }

        // cout <<"BFS = \n" ;

        cout << "Case #" << c++ << ": Vivek should drink beverages in this order:";
        g.bfsTopologicalSort(beverages);
        // g.dfsTopologicalSort(beverages);

        cout << endl;
    }

    return 0;
}
