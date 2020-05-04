/*
FIBOSUM

The Fibonacci sequence is defined by the following relation:

F(0) = 0
F(1) = 1
F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M, you have to calculate the sum (F(N) + F(N + 1) + … + F(M)) mod 1000000007.
Source: FIBOSUM (SPOJ)

Input Format
The first line contains an integer T (the number of test cases). Then, T lines follow. Each test case consists of a single line with two non-negative integers N and M.

Constraints
1<=T<=1000 0<=N<=M<=10^9

Output Format
For each test case you have to output a single line containing the answer for the task.

Sample Input
3
0 3
3 5
10 19
Sample Output
4
10
10857
*/

#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MOD 1000000007
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

int main() {
    
    ll t,n,num;
    
    k = 2;
    //Init Vector F1
    b.pb(0);
    b.pb(1);
    
    //Coefficients
    c.pb(1);
    c.pb(1);

    cin>>t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        cout<< (compute(b+3) - compute(a+2) + MOD) % MOD << endl;
    }
    
    return 0;
    
}
