/*
MAXIMUM SUM QUERY
You are given an array A and Q queries. Each query consists of 2 integers l and r. The answer to each query will be max(Ai + Ai+1 +….+ Aj,l<=i<=j<=r).

Input Format
First line contains an integer N, denoting the number of elements in the array A. Next line contains N integers denoting the elements of the array. Next line contains a single integer Q, denoting the number of queries. Next Q lines contain Q queries, consisting of 3 integers each, L R K.

Constraints
1<=N,Q<=10^5 |Ai|<=10^9

Output Format
Print the answer to each query.

Sample Input
3 
-1 2 3
2
1 3
2 3
Sample Output
5
5
Explanation
In the first query (1,3), possible segments are [-1], [2], [3], [-1,2], [2,3], [-1,2,3].
sum([-1]) = -1, 
sum([2]) = 2, 
sum([3]) = 3, 
sum([-1,2]) = -1+2=1, 
sum([2,3]) = 2+3=5, 
sum([-1,2,3]) = -1+2+3=4, 
answer = max(-1,2,3,1,5,4) = 5.
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class node {
public:
    ll maxPrefixSum ;
    ll maxSuffixSum ;
    ll maxSubarraySum ;
    ll totalSum ;

    node(ll val = INT_MIN) {
        init(val);
    }

    void init(ll val = INT_MIN) {
        maxPrefixSum = maxSuffixSum = maxSubarraySum = totalSum = val;
    }
};

node merge(const node &left, const node &right) {
    node parent;
    
    parent.maxPrefixSum = max(left.maxPrefixSum, right.maxPrefixSum + left.totalSum);

    parent.maxSuffixSum = max(right.maxSuffixSum, left.maxSuffixSum + right.totalSum);

    parent.totalSum = left.totalSum + right.totalSum;

    parent.maxSubarraySum = max( max(left.maxSubarraySum, right.maxSubarraySum), left.maxSuffixSum+right.maxPrefixSum);

    return parent;
}

class SegmentTree {
private:
    int n;
    vector < node > tree;

    void makeTree(const vector<ll> &v, int index, int s, int e) {
        //Leaf Node
        if(s == e) {
            tree[index].init(v[e]);
            return ;
        }

        int mid = (s+e)/2;
        makeTree(v, 2*index, s, mid);
        makeTree(v, 2*index+1, mid+1, e);

        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }

    node query(int s, int e, int qs, int qe, int index) {
        //Complete overlap
        if(qs <= s && e <= qe) {
            return tree[index];
        }

        //No Overlap
        if(qe < s || qs > e) {
            return node();
        }

        //Partial Overlap
        int mid = (s+e)/2;

        node leftAns = query(s, mid, qs, qe, 2*index);
        node rightAns = query(mid+1, e, qs, qe, 2*index+1);

        return merge(leftAns, rightAns);
    }

    
public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.resize(4*n+1);
    }


    void buildTree(const vector<ll> &v) {
        makeTree(v, 1, 0, v.size()-1) ;
    }

    void buildTree(ll *a, int n) {
        vector<ll> v(a,a+n);
        makeTree(v, 1, 0, v.size()-1) ;
    }

    ll query(int l, int r) {
        node res = query(0, n-1, l-1, r-1, 1);
        return res.maxSubarraySum;
    }


    // void print() {
    //     for (int i = 1; i < tree.size(); ++i) {
    //         if(tree[i].size() == 0)
    //             break;
    //         cout << "tree["<<i<<"] = " ;
    //         for (int j = 0; j < tree[i].size(); ++j) {
    //             cout << tree[i][j] << " " ;
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
};

int main() {
    int n ;
    cin >> n;

    SegmentTree t(n);

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int noOfQueries;
    cin >> noOfQueries;

    t.buildTree(v);

    // t.print();

    while(noOfQueries--) {
        int l,r;
        cin >> l >> r ;
        cout << t.query(l,r) << endl;
    }


    
    return 0;
}
