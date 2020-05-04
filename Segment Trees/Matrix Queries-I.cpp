/*
Matrix Queries-I
Mike has N 2*2 matrices, M1, M2, …, Mn. Elements of matrices are in range [0,r-1], where r is an integer. Mike considers an operation, o, such that A2x2 o B2x2 = (A2x2 * B2x2)%r (each value in the product of 2 matrices is stored modulo r). Mike gives you q queries, each of the form L,R. For each query, you have to find ML o ML+1 o … o MR.
Note that it is not necessary, that all the input matrices are invertible. For eg. a matrix, A2x2=[[0,0],[0,0]] can be present in input.

Input Format
The first line of the input file contains r, n and q.
Next n blocks of two lines, containing two integer numbers ranging from 0 to r.
Blocks are separated with blank lines.
They are followed by q pairs of integers L and R.

Constraints
1<=n,q<=100000 1<=r<=10000

Output Format
Print q blocks containing two lines each. Each line should contain two integer numbers ranging from 0 to r.
Separate blocks with an empty line.

Sample Input
3 4 4
0 1
0 0

2 1
1 2

0 0
0 2

1 0
0 2

1 4
2 3
1 3
2 2
Sample Output
0 2
0 0

0 2
0 1

0 1
0 0

2 1
1 2
*/

#include <bits/stdc++.h>
using namespace std;

int MOD;

vector< vector<int> > operator *(const vector< vector<int> > &x, const vector< vector<int> > &y) {
    vector< vector<int> > v(2, vector<int> (2,0));
    v[0][0] = ((x[0][0]*y[0][0])%MOD + (x[0][1]*y[1][0])%MOD)%MOD;
    v[0][1] = ((x[0][0]*y[0][1])%MOD + (x[0][1]*y[1][1])%MOD)%MOD;
    v[1][0] = ((x[1][0]*y[0][0])%MOD + (x[1][1]*y[1][0])%MOD)%MOD;
    v[1][1] = ((x[1][0]*y[0][1])%MOD + (x[1][1]*y[1][1])%MOD)%MOD;

    return v;
}

class SegmentTree {
private:
    int n;
    vector < vector< vector<int> > >tree;

    void makeTree(const vector< vector< vector<int> > > &v, int index, int s, int e) {

        if(s == e) {
            tree[index]  = v[e];
            return ;
        }

        int mid = (s+e)/2;
        makeTree(v, 2*index, s, mid);
        makeTree(v, 2*index+1, mid+1, e);

        tree[index] = (tree[2*index] * tree[2*index+1]);
    }

    vector< vector<int> > query(int s, int e, int qs, int qe, int index) {
        // cout << "s = " << s << "    e = " << e << "     index = " << index << endl;
        //Complete overlap
        if(qs <= s && e <= qe) {
            // cout << "complete overlap\n";
            return tree[index];
        }

        //No Overlap
        if(qe < s || qs > e) {
            vector< vector<int> > identityMatrix (2, vector<int> (2,1));
            identityMatrix[0][1] = identityMatrix[1][0] = 0;
            // cout << "no overlap\n";
            return identityMatrix;
        }

        //Partial Overlap
        // cout << "partial overlap\n";
        int mid = (s+e)/2;

        vector< vector<int> > leftAns = query(s, mid, qs, qe, 2*index);
        vector< vector<int> > rightAns = query(mid+1, e, qs, qe, 2*index+1);

        vector< vector<int> > res = leftAns*rightAns;

        return res;
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.resize(4*n+1);
    }


    void buildTree(const vector<vector< vector<int> > > &v) {
        makeTree(v, 1, 0, v.size()-1) ;
    }

    void buildTree(vector< vector<int> > *a, int n) {
        vector<vector< vector<int> > > v(a,a+n);
        makeTree(v, 1, 0, v.size()-1) ;
    }

    vector< vector<int> > query(int l, int r) {
        // cout << "Calling query for " << l-1 << " " << r-1 << endl;
        return query(0, n-1, l-1, r-1, 1);
    }


    void print() {
        for (int i = 1; i < tree.size(); ++i) {
            cout << "tree["<<i<<"] = \n" << tree[i][0][0] << " " << tree[i][0][1] << '\n' << tree[i][1][0] << " " << tree[i][1][1] << "\n\n";
        }
    }
};

int main() {
    int n,noOfQueries;
    cin >> MOD >> n >> noOfQueries;

    vector < vector < vector < int > > > v(n, vector < vector < int > > (2, vector < int > (2,1)));

    for (int i = 0; i < n; ++i) {
        cin >> v[i][0][0] >> v[i][0][1] >> v[i][1][0] >> v[i][1][1];
    }

    SegmentTree t(n);

    t.buildTree(v);

    // t.print();

    while(noOfQueries--) {
        int l,r;
        cin >> l >> r;
        vector < vector < int > > res = t.query(l,r);
        cout << res[0][0] << " " << res[0][1] << '\n' << res[1][0] << " " << res[1][1] << "\n\n";
    } 

    
    return 0;
}
