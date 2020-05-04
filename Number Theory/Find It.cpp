/*
FIND IT
You are given N numbers.
Now you have Q queries.
For each query you will be given an integer K.
You have to find out the number of multiples of K among the given N numbers.

Input Format:
The first line consists of number N.
Next N line contains N numbers. Next line contains number of queries Q. Next Q lines contains Integer K for each query

Constraints:
1 <= N <= 10^5 1 <= numbers <= 10^5 1 <= Q <= 10^5 1 <= K <= 10^5

Output Format
Output Q lines the answer for every query.

Sample Input
4
5
8
10
8
1
2
Sample Output
3
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define vi  vector<ll>

int main() { 
    sync;
    ll n;
    cin >> n;
    vector<int> v(100005,0);

    ll x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v[x]++;
    }

    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll k;
        cin >> k;
        ll count = 0;
        for (int i = 1; i*k < 100005; ++i) {
            if(v[i*k]) {
                // cout << i*k << endl;
                count += v[i*k];
            }
        }
        cout << count << endl; 
    }

    return 0;
}
