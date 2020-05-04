/*
Activity Selection Problems
You are given n activities (from 0 to n-1) with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Input Format
The first line consists of an integer T, the number of test cases. For each test case, the first line consists of an integer N, the number of activities. Then the next N lines contain two integers m and n, the start and end time of each activity.

Constraints
1<=t<=50 1<=n<=10000 1<=A[i]<=100

Output Format
For each test case find the maximum number of activities that you can do.

Sample Input
1 
3
10 20
12 15
20 30
Sample Output
2
Explanation
Person only do 0th and 2nd activities.
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool myCompare(pii a, pii b)
{
    return a.ss < b.ss;
}

int main()
{
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        vector<pii> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].ff >> v[i].ss;
        }

        sort(v.begin(), v.end(), myCompare);

        pii current = v[0];
        int c = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i].ff >= current.ss)
            {
                c++;
                current = v[i];
            }
        }

        cout << c << endl;
    }

    return 0;
}
