/*
MIN QUERY-I
You are given an array A of n elements and Q queries. Each query can be of following types:

1 L R: Print the minimum value in AL, AL+1, AL+2….,AR.
2 X Y: Update the value of Ax with Y.
Input Format
First line contains integers N and Q, denoting the number of elements and number of queries. Next line contains N integers, denoting A1, A2, A3….,AN. Next Q lines contains Q queries.

Constraints
1<=N,Q<=10^5 |Ai|,|Y|<=10^9 1<=L,R,X<=N

Output Format
Answer each query of type 1.

Sample Input
5 5
1 4 3 5 2
1 1 5
2 3 9
1 2 4
1 2 5
1 3 4
Sample Output
1
4
2
5
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
class node {
public:
    T data;
    int lazyValue;
    node(T d = 0) {
        data = d;
        lazyValue = 0;
    }
};

template <class T>
class SegmentTree {
private:
    int n;
    vector < node<T> > tree;

    void makeTree(const vector<T> &v, int index, int s, int e) {
        if(s == e) {
            tree[index].data  = v[e];
            return ;
        }

        int mid = (s+e)/2;
        makeTree(v, 2*index, s, mid);
        makeTree(v, 2*index+1, mid+1, e);

        tree[index].data = min(tree[2*index].data, tree[2*index+1].data);
    }

    T query(int s, int e, int qs, int qe, int index) {
        //Complete overlap
        if(qs <= s && e <= qe) {
            return tree[index].data;
        }

        //No Overlap
        if(qe < s || qs > e) {
            return INT_MAX;
        }

        //Partial Overlap
        int mid = (s+e)/2;

        T leftAns = query(s, mid, qs, qe, 2*index);
        T rightAns = query(mid+1, e, qs, qe, 2*index+1);

        return min(leftAns, rightAns);
    }

    void updateNode(int s, int e, int i, T val, int index) {
        //Out of bounds - No Overlap
        if(i > e || i < s) {
            return;
        }

        //Leaf Node
        if(s == e) {
            tree[index].data = val;
            return;
        }

        //Partial Overlap
        int mid = (s+e)/2;
        updateNode(s, mid, i, val, 2*index);
        updateNode(mid+1, e, i, val, 2*index+1);
        tree[index].data = min(tree[2*index].data, tree[2*index+1].data);

        return;
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.resize(4*n+1);
    }


    void buildTree(const vector<T> &v) {
        makeTree(v, 1, 0, v.size()-1) ;
    }

    void buildTree(T *a, int n) {
        vector<T> v(a,a+n);
        makeTree(v, 1, 0, v.size()-1) ;
    }

    T query(int l, int r) {
        return query(0, n-1, l-1, r-1, 1);
    }

    void updateNode(int i, T val) {
        updateNode(0, n-1, i-1, val, 1);
    }

    void print() {
        for (int i = 0; i < tree.size(); ++i) {
            cout << tree[i].data << " ";
        }
        cout << endl;
    }
};

int main() {
    int n ;
    cin >> n;

    SegmentTree<int> t(n);

    int noOfQueries;
    cin >> noOfQueries;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    t.buildTree(v);

    // t.print();

    while(noOfQueries--) {
        int q;
        cin >> q;
        if(q == 1) {
            //Print min element in L to R
            int l,r;
            cin >> l >> r;
            cout << t.query(l, r) << endl;
        }
        else if(q == 2) {
            int x,y;
            cin >> x >> y;
            t.updateNode(x, y);
        }
    }


    
    return 0;
}
