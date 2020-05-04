/*
MAX XOR ARRAY
You are given an array containing n elements. Xor of an array is defined as the xor of all the elements present in the array. You can remove atmost one element from the array to maximize the value of XOR of array. Find the maximum XOR value you can get for the resulting array.

Input Format:
First line of input contains an integer n denoting the size of the array. After that n lines follow, where the i th line contains the i'th element of the array.

Constraints:
1 <= n <= 1000000 0 <= elements of array <= 10^18

Output Format
You have to print a single integer denoting the maximum xor you can get for the resulting array.

Sample Input
3
1
2
3
Sample Output
3
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<ll>

int main() {
    ll n;
    cin >> n;
    vi v(n);
    ll x = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        x = x^v[i];
    }

    ll maxXor = x;
    for (int i = 0; i < n; ++i) {
        maxXor = max(maxXor, x^v[i]);
    }

    cout << maxXor ;

    return 0;
}
