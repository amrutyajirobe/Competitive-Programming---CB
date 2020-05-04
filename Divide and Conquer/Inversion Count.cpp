/*
Inversion Count
You are given an array A find out number of pairs (i,j) in array A such that A[i] > A[j] and i < j.

Input Format
The first line consists of number of test cases t. Each test case consists of integer N followed by N space separated integers.

Constraints
1 <= N <= 100000 1 <= t <= 20 0 <= A[i] <= 100000000

Output Format
The number of inversions in array

Sample Input
2
4
1 2 4 3
3
3 2 1
Sample Output
1
3
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll  long long int

void print(ll a[], ll start, ll end) {
    for (int i = start; i <= end; ++i) {
        cout << a[i] << " " ;
    }
    cout << endl;
}

ll merge(ll a[], ll start, ll end) {
    if(start > end) {
        return 0;
    }

    ll mid = (start+end)/2;

    ll count = 0;

    ll i = start;
    ll j = mid + 1;
    ll k = 0 ;

    ll temp[100000] = {0};

    while(i <= mid && j <= end) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            count += (mid - i + 1);
        }
    }

    while(i <= mid) {
        temp[k++] = a[i++];
    }

    while(j <= end) {
        temp[k++] = a[j++];
        count += (mid - i + 1);
    }

    j = 0;
    for (int i = start; i <= end; ++i) {
        a[i] = temp[j++];
    }

    return count;
}

ll inversionCount(ll a[], ll start, ll end) {
    if(start >= end) {
        return 0;
    }

    ll ans = 0;

    ll mid = (start+end)/2;

    ans += inversionCount(a, start, mid);
    ans += inversionCount(a, mid+1, end);

    //CROSS
    ans += merge(a, start, end);

    // cout << "s = " << start << "   e = " << end << "    ans = " << ans << endl;
    // print(a,start,end);

    return ans;
}

int main() { 
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin >> n;

        ll a[100000];

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << inversionCount(a, 0, n-1) << endl;
    }

    return 0;
}
