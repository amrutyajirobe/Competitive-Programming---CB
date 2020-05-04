/*
MAX QUERY-I
You are given an array A of N elements and Q queries. Each query consists of 3 integers L R K. For each query, you have to find the number of elements Ax1, Ax2,….,Axj>=K, where L<=x1, x2,…xj<=R.

Input Format
First line contains an integer N, denoting the number of elements in the array A. Next line contains N integers denoting the elements of the array. Next line contains a single integer Q, denoting the number of queries. Next Q lines contains Q queries, consisting of 3 integers each, L R K.

Constraints
1<=N,Q<=10^5 |Ai|, |K|<=10^9 1<=L, R<=N

Output Format
Print Q lines, where ith line contains the answer to the ith query.

Sample Input
5
1 2 3 4 5
5
1 4 1
1 5 2
1 5 3
1 5 4
1 5 5
Sample Output
4
4
3
2
1
*/


#include <bits/stdc++.h>
using namespace std;

#define pii pair < int , int > 
#define ff first
#define ss second
#define mp make_pair

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

            return tree[index].size() - (lower_bound(tree[index].begin(), tree[index].end(), key) - tree[index].begin()) ;
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
