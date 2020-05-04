/*
CHICAGO - 106 miles to Chicago
In the movie "Blues Brothers", the orphanage where Elwood and Jake were raised may be sold to the Board of Education if they do not pay 5000 dollars in taxes at the Cook County Assessor's Office in Chicago. After playing a gig in the Palace Hotel ballroom to earn these 5000 dollars, they have to find a way to Chicago. However, this is not so easy as it sounds, since they are chased by the Police, a country band and a group of Nazis. Moreover, it is 106 miles to Chicago, it is dark and they are wearing sunglasses.
As they are on a mission from God, you should help them find the safest way to Chicago. In this problem, the safest way is considered to be the route which maximises the probability that they are not caught.

Input Specification
The input file contains several test cases.
Each test case starts with two integers n and m (2 = n = 100 , 1 = m = n*(n-1)/2). n is the number of intersections, m is the number of streets to be considered.
The next m lines contain the description of the streets. Each street is described by a line containing 3 integers a, b and p (1 = a, b = n , a ? b, 1 = p = 100): a and b are the two end points of the street and p is the probability in percent that the Blues Brothers will manage to use this street without being caught. Each street can be used in both directions. You may assume that there is at most one street between two end points.
The last test case is followed by a zero.

Output Specification
For each test case, calculate the probability of the safest path from intersection 1 (the Palace Hotel) to intersection n (the Honorable Richard J. Daley Plaza in Chicago). You can assume that there is at least one path between intersection 1 and n.
Print the probability as a percentage with exactly 6 digits after the decimal point. The percentage value is considered correct if it differs by at most 10-6 from the judge output. Adhere to the format shown below and print one line for each test case.

Sample Input
5 7
5 2 100
3 5 80
2 3 70
2 1 50
3 4 90
4 1 85
3 1 70
0
Sample Output
61.200000 percent
The safest path for the sample input is 1 -> 4 -> 3 -> 5
*/
#include <bits/stdc++.h>
using namespace std;

#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    sync;
    double graph[105][105];
    int n, e;

    while (cin >> n && n)
    {
        cin >> e;
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < e; i++)
        {
            int u, v;
            double c;
            cin >> u >> v >> c;
            graph[u][v] = graph[v][u] = c / 100.0;
        }

        //Using Bellman Ford Algo
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    graph[i][j] = max(graph[i][j], graph[i][k] * graph[k][j]);
                }
            }
        }

        cout << setprecision(6) << fixed << graph[1][n] * 100 << " percent" << endl;
    }

    return 0;
}
