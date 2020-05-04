/*
Simple Enough
For a given number n, form a list and insert the following pattern into the list at the same position sequentially.
{floor(n/2) , n%2 , floor(n/2) }
Until every element in the list is either 1 or 0. Now, calculate number of 1s in from l to r (1-indexed).

EXPLAINATION: Start from n. Then make a list with the following elements.i.e. {floor(n/2) , n%2 , floor(n/2) }. Now this list has three elements. Now further break down each of those 3 elements considering the new n to be floor(n/2) , n%2 and floor(n/2) respectively for those three elements respectively INPLACE. And this process will go on until the n reduces down to 1 or 0. So it will basically form a tree with 3 branches coming out of every node at every level starting from 1 node (n) at the root.
Input Format
Three integers n , l , r

Constraints
0?=?n?<?10^12, 0?=?r?-?l?=?10^6, 1 = l = r

Output Format
Single line containing number of 1s in the given range.

Sample Input
9 6 9
Sample Output
3
Explanation
9 will have the sequence :
101010111010101
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int

ll sizeCount(ll n){
    if(n <= 1)
        return 1;
    
    return (sizeCount(n/2)*2)+1;
}

ll breakDown(ll n, ll start, ll end, ll left, ll right) {
    if(start > right || end < left || start > end) {
        return 0;
    }

    ll ans = 0;
    ll mid = (start+end)/2;

    if(mid >= left && mid <= right && n%2==1) {
        ans ++;
    }

    ans += breakDown(n/2, mid+1, end, left, right);
    ans += breakDown(n/2 ,start, mid-1, left, right);

    return ans;
}


int main() { 
    sync;
    ll n,l,r;
    cin >> n >> l >> r;

    cout << breakDown(n,1,sizeCount(n),l,r);

    return 0;
}
