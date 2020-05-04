/*
KQUERY
Given a sequence of N numbers a1, …, an and a number of K- queries.
A k-query is a triple (i, j, k) (1 = i, j = n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subarray ai, ai+1, …, aj.
The original problem can be found here

Input Format
Line 1: n (1 = n = 30000).

Line 2: n numbers a1, a2, …, an (1 = ai = 10^9).

Line 3: q (1 = q = 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 = i, j = 10^9, 1 = k = 10^9).

if i > j or i,j is greater than n than answer is 0.

Constraints
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subarray ai, ai+1, …, aj in a single line.

Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3
*/
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector < vector <int> > tree;

    void makeTree(const vector<int> &v, int index, int s, int e) {
        //Leaf Node
        if(s == e) {
            tree[index].push_back(v[e]);
            return ;
        }

        int mid = (s+e)/2;
        makeTree(v, 2*index, s, mid);
        makeTree(v, 2*index+1, mid+1, e);

        tree[index].resize(tree[2*index].size() + tree[2*index+1].size());

        int i = 0;
        int j = 0;
        int k = 0;

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

    int query(int s, int e, int qs, int qe, int index, int key) {
        //Complete overlap
        if(qs <= s && e <= qe) {
            if(key < tree[index][0]) {
                return tree[index].size();
            }
            else if(key > tree[index].back()) {
                return 0;
            }

            return tree[index].size() - (lower_bound(tree[index].begin(), tree[index].end(), key) - tree[index].begin()) - 1;
        }

        //No Overlap
        if(qe < s || qs > e) {
            return 0;
        }

        //Partial Overlap
        int mid = (s+e)/2;

        int leftAns = query(s, mid, qs, qe, 2*index, key);
        int rightAns = query(mid+1, e, qs, qe, 2*index+1, key);

        return leftAns+rightAns;
    }

    
public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.resize(4*n+1);
    }


    void buildTree(const vector<int> &v) {
        makeTree(v, 1, 0, v.size()-1) ;
    }

    void buildTree(int *a, int n) {
        vector<int> v(a,a+n);
        makeTree(v, 1, 0, v.size()-1) ;
    }

    int query(int l, int r, int key) {
        return query(0, n-1, l-1, r-1, 1, key);
    }

    

    void print() {
        for (int i = 0; i < tree.size(); ++i) {
            cout << "tree["<<i<<"] = " ;
            for (int j = 0; j < tree[i].size(); ++j) {
                cout << tree[i][j] << " " ;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int n ;
    cin >> n;

    SegmentTree t(n);

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int noOfQueries;
    cin >> noOfQueries;

    t.buildTree(v);

    // t.print();

    while(noOfQueries--) {
        int l,r,key;
        cin >> l >> r >> key;
        cout << t.query(l,r,key) << endl;
    }


    
    return 0;
}
