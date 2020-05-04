/*
Fibonacci meets GCD
Let Fib(x) denote the value of fibonacci of x. For example F(1) =1 , F(2) = 1, F(3) = 2 and so on for all x.
Let GCD(a,b) denote the greatest common divisor of two numbers a and b.
You are given an array A of N integers.
You will be given Q queries of the form L R.
For each query you have to find out the value of GCD ( F(A[L] , FA[L+1]….. FA[R] ) % mod.
mod = 10^9+7.

Input Format
First line : Two integers N and Q. Second line : N space separated integers denoting array A. Next Q lines : Two space separated integers L and R.

Constraints
1 <= N,Q <= 10^5 1 <= A[i] <= 10^9 1 <= L , R <= N

Output Format
Output the result of each query in a separate line.

Sample Input
3 2
2 4 8
1 3
2 3
Sample Output
1
3
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define ll long long int
#define pb push_back

ll k;
vector<ll> a,b,c;

//Multiply two matrices
vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B ){
    
    //third matrix mei result store
    vector<vector<ll> > C(k+1,vector<ll>(k+1));
    
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1;x<=k;x++){
                
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }   
            
        }
    }
    
    
    return C;
}


vector<vector<ll> >  pow(vector<vector<ll> > A,ll p){
    
    //Base case
    if(p==1){
        return A;
    }
    //Rec Case
    if(p&1){
        return multiply(A, pow(A,p-1));
    }
    else{
        
        vector<vector<ll> > X = pow(A,p/2);
        return multiply(X,X);
    }
    
}


ll compute(ll n){
    //Base case
    if(n==0){
        return 0;
    }
    
    //Suppose n<=k
    if(n<=k){
        return b[n-1];
    }
    
    //Otherwise we use matrix exponentiation, indexing 1 se
    vector<ll> F1(k+1);
    
    for(int i=1;i<=k;i++){
        F1[i] = b[i-1];
    }
    
    //2. Transformation matrix
    vector<vector<ll> > T(k+1,vector<ll>(k+1));
    // Let init T 
    
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            
            if(i<k){
                if(j==i+1){
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
                continue;
            }    
            //Last Row - store the Coefficients in reverse order
            T[i][j] = c[k-j];
            
        }
        
    }
    
    // 3. T^n-1
    T = pow(T,n-1);
    
    // 4. multiply by F1
    ll res = 0;
    for(int i=1;i<=k;i++){
        res = (res + (T[1][i]*F1[i])%MOD)%MOD;
    }
    
    return res;
    
}

ll fibo(ll n) {
    k = 2;
    //Init Vector F1
    b.pb(0);
    b.pb(1);
    
    //Coefficients
    c.pb(1);
    c.pb(1);

    return compute(n+1);
}

// Code till here is basic Matrix Exponentiation to compute nth fibo term
// Call fibo(n) function to get the result

ll gcd(ll a,ll b) {
    if(b == 0) 
        return a;
    return gcd(b, a%b);
}

class SegmentTree {
private:
    int n;
    vector < ll > tree;

    void makeTree(const vector<ll> &v, int index, int s, int e) {
        if(s == e) {
            tree[index]  = v[e];
            return ;
        }

        int mid = (s+e)/2;
        makeTree(v, 2*index, s, mid);
        makeTree(v, 2*index+1, mid+1, e);

        tree[index] = gcd(tree[2*index], tree[2*index+1]);
    }

    ll query(int s, int e, int qs, int qe, int index) {
        //Complete overlap
        if(qs <= s && e <= qe) {
            return tree[index];
        }

        //No Overlap
        if(qe < s || qs > e) {
            return 0;
        }

        //Partial Overlap
        int mid = (s+e)/2;

        ll leftAns = query(s, mid, qs, qe, 2*index);
        ll rightAns = query(mid+1, e, qs, qe, 2*index+1);

        return gcd(leftAns, rightAns);
    }

public:
    SegmentTree(int n = 0) {
        this->n = n;
        tree.resize(4*n+1);
    }


    void buildTree(const vector<ll> &v) {
        makeTree(v, 1, 0, v.size()-1) ;
    }

    ll query(int l, int r) {
        ll x = query(0, n-1, l-1, r-1, 1);
        return fibo(x);
    }

    void print() {
        for (int i = 1; i < tree.size(); ++i) {
            if(tree[i] == 0)    
                break;
            cout << "tree["<<i<<"] = " << tree[i] << "\n";
        }
        cout << endl;
    }
};

int main() {
    // Approach - Mathematical Property 
    // gcd( f(a), f(b) ) = f( gcd(a,b))
    // First compute the gcd of the numbers then get the nth fibonacci using matrix exponentiation
    sync;
    int n ;
    cin >> n; 

    // cout << fibo(10) << endl;

    SegmentTree t(n);

    int noOfQueries;
    cin >> noOfQueries;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    t.buildTree(v);

    // t.print();

    while(noOfQueries--) {
        int l,r;
        cin >> l >> r;
        cout << t.query(l, r) << endl;
    }


    
    return 0;
}
