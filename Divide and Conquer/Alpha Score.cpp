/*
Alpha Score
You are climbing up using stairs where a number is written on each stair. At each step we define the alpha score as sum of all the numbers previously seen on the stairs which are smaller than the present number. Alpha score of the whole journey is defined as the sum of all the alpha scores at each step. Print the alpha score of whole journey modulus 1000000007.

Input Format
First line contains a single integer n denoting the number of stairs. Next line contains n space separated integers denoting the numbers written on stairs.

Constraints
1 <= n <= 10^5 Every number written on stair lies between [0,10^9]

Output Format
Single integer denoting the alpha score of the journey modulus 1000000007.

Sample Input
5
1 5 3 6 4
Sample Output
15
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int

ll merge(ll a[], ll s, ll e) {
    if(s >= e) {
        return 0;
    }


    ll mid = (s+e)/2;

    ll i = s;
    ll j = mid+1;

    ll score = 0;
    ll leftCumSum = 0;

    ll temp[100005];
    ll k = 0;

    while(i<=mid && j<=e) {
        if(a[i] < a[j]) {
            leftCumSum += a[i];
            temp[k++] = a[i++];
        }
        else {
            score += leftCumSum;
            temp[k++] = a[j++];
        }
    }

    while(i<=mid) {
        temp[k++] = a[i++];
    }

    while(j<=e) {
        score += leftCumSum;
        temp[k++] = a[j++];
    }

    j = 0;
    for (int i = s; i <= e; ++i) {
        a[i] = temp[j++];
    }

    return score;
}

ll alphaScore(ll a[], ll s, ll e) {
    if(s >= e) {
        return 0;
    }

    ll mid = (s+e)/2;

    ll leftScore = alphaScore(a, s, mid);
    ll rightScore = alphaScore(a, mid+1, e);

    ll currentScore = merge(a, s, e);

    return ((leftScore + rightScore) % MOD + currentScore) % MOD;
}

int main() { 
    sync;
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << alphaScore(a, 0, n-1) ;

    return 0;
}
