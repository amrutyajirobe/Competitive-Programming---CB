/*
KQUERYO
Given a sequence of N numbers a1, …, an and a number of K- queries.
A k-query is a triple (i, j, k) (1 = i, j = n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subarray ai, ai+1, …, aj.
The original problem can be found here

Input Format
Line 1: n (1 = n = 30000).

Line 2: n numbers a1, a2, …, an (1 = ai = 10^9).

Line 3: q (1 = q = 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers a, b, c representing a k-query (1 = a, b , c = 10^9.

You should do the following:

i = a xor last_ans

j = b xor last_ans

k = c xor last_ans

Where last_ans = the answer to the last query (for the first query it's 0).

if i > j answer is 0.

if i < 1 take i =1.

if j > n take j = n.

Constraints
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subarray ai, ai+1, …, aj in a single line.

Sample Input
6
8 9 3 5 1 9
5
2 3 5
3 3 7
0 0 11
0 0 2
3 7 4
Sample Output
1
1
0
0
2
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int

ll prevAns = 0;

class SegmentTree {
private:
    ll n;
    vector < vector <ll> > tree;

    void makeTree(const vector<ll> &v, ll index, ll s, ll e) {
        //Leaf Node
        if(s == e) {
            tree[index].push_back(v[e]);
            return ;
        }

        ll mid = (s+e)/2;
        makeTree(v, 2*index, s, mid);
        makeTree(v, 2*index+1, mid+1, e);

        tree[index].resize(tree[2*index].size() + tree[2*index+1].size());

        ll i = 0;
        ll j = 0;
        ll k = 0;

        while(i < tree[2*index].size() && j < tree[2*index+1].size()) {
            if(tree[2*index][i] < tree[2*index+1][j]) {
                tree[index][k++] = tree[2*index][i++];
            }
            else {
                tree[index][k++] = tree[2*index+1][j++];
            }
        }

        while(i < tree[2*index].size()) {
            tree[index][k++] = tree[2*index][i++];
        }

        while(j < tree[2*index+1].size()) {
            tree[index][k++] = tree[2*index+1][j++];
        }
    }

    ll query(ll s, ll e, ll qs, ll qe, ll index, ll key) {
        //Complete overlap
        if(qs <= s && e <= qe) {
            if(key < tree[index][0]) {
                return tree[index].size();
            }
            else if(key > tree[index].back()) {
                return 0;
            }

            return tree[index].size() - (upper_bound(tree[index].begin(), tree[index].end(), key) - tree[index].begin()) ;//- binary_search(tree[index].begin(), tree[index].end(), key);
        }

        //No Overlap
        if(qe < s || qs > e) {
            return 0;
        }

        //Partial Overlap
        ll mid = (s+e)/2;

        ll leftAns = query(s, mid, qs, qe, 2*index, key);
        ll rightAns = query(mid+1, e, qs, qe, 2*index+1, key);

        return leftAns+rightAns;
    }

    
public:
    SegmentTree(ll n = 0) {
        this->n = n;
        tree.resize(4*n+1);
    }


    void buildTree(const vector<ll> &v) {
        makeTree(v, 1, 0, v.size()-1) ;
    }

    void buildTree(ll *a, ll n) {
        vector<ll> v(a,a+n);
        makeTree(v, 1, 0, v.size()-1) ;
    }

    ll query(ll a, ll b, ll c) {
        ll l = (a^prevAns);
        ll r = (b^prevAns);
        ll key = (c^prevAns);

        // if(l > r) {
        //     prevAns = 0;
        //     return 0;
        // }
        

        if(l < 1) {
            l = 1;
        }

        if(r > n) {
            r = n;
        }

        // cout << "l = " << l << "    r = " << r << "      key = " << key << endl;

        prevAns = query(0, n-1, l-1, r-1, 1, key);
        return prevAns;
    }

    

    void print() {
        for (ll i = 0; i < tree.size(); ++i) {
            cout << "tree["<<i<<"] = " ;
            for (ll j = 0; j < tree[i].size(); ++j) {
                cout << tree[i][j] << " " ;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    sync;
    ll n ;
    cin >> n;

    SegmentTree t(n);

    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll noOfQueries;
    cin >> noOfQueries;

    t.buildTree(v);

    // t.print();

    while(noOfQueries--) {
        ll a,b,c;
        cin >> a >> b >> c;
        cout << t.query(a,b,c) << endl;
    }


    
    return 0;
}
