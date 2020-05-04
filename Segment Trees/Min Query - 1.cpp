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
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void buildTree(vector < int > &tree, int index, const vector < int > &v, int s, int e) {
    if(s == e) {
        tree[index]  = v[e];
        return ;
    }

    int mid = (s+e)/2;
    buildTree(tree, 2*index, v, s, mid);
    buildTree(tree, 2*index+1, v, mid+1, e);

    tree[index] = min(tree[2*index], tree[2*index+1]);

    return;
}

int query(const vector < int > &tree, int s, int e, int qs, int qe, int index) {
    //Complete overlap
    if(qs <= s && e <= qe) {
        return tree[index];
    }

    //No Overlap
    if(qe < s || qs > e) {
        return INT_MAX;
    }

    //Partial Overlap
    int mid = (s+e)/2;

    int leftAns = query(tree, s, mid, qs, qe, 2*index);
    int rightAns = query(tree, mid+1, e, qs, qe, 2*index+1);

    return min(leftAns, rightAns);
}

void print(const vector < int > &tree) {
    for (int i = 0; i < tree.size(); ++i) {
        if(tree[i] == INT_MAX) {
            cout << 0 << " ";
        }
        else {
            cout << tree[i] << " ";
        }
    }
    cout << endl;
}

void updateNode(vector < int > &tree, int s, int e, int i, int val, int index) {
    //Out of bounds - No Overlap
    if(i > e || i < s) {
        return;
    }

    //Leaf Node
    if(s == e) {
        tree[index] = val;
        return;
    }

    //Partial Overlap
    int mid = (s+e)/2;
    updateNode(tree, s, mid, i, val, 2*index);
    updateNode(tree, mid+1, e, i, val, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);

    return;
}

int main() {
    int n;
    cin >> n;
    vector < int > v(n);

    int noOfQueries;
    cin >> noOfQueries;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector < int > tree(4*n+1, INT_MAX);

    buildTree(tree, 1, v, 0, n-1);

    // print(tree);

    while(noOfQueries--) {
        int q;
        cin >> q;
        if(q == 1) {
            //Print min element in L to R
            int l,r;
            cin >> l >> r;
            cout << query(tree, 0, n-1, l-1, r-1, 1) << endl;
        }
        else if(q == 2) {
            int x,y;
            cin >> x >> y;
            updateNode(tree, 0, n-1, x-1, y, 1);
        }
    }



    return 0;
}
