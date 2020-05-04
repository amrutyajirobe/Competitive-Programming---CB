/*
3-D Structure

You are given a 3-D Matrix in which each block contains 0 initially. The first block is defined by the coordinate (1,1,1) and the last block is defined by the coordinate (N,N,N). There are two types of queries.

UPDATE x y z W updates the value of block (x,y,z) to W.

QUERY x1 y1 z1 x2 y2 z2 calculates the sum of the value of blocks whose x coordinate is between x1 and x2 (inclusive), y coordinate between y1 and y2 (inclusive) and z coordinate between z1 and z2 (inclusive). Original Problem :- Hackerrank

Input Format
The first line contains an integer T, the number of test-cases. T testcases follow. For each test case, the first line will contain two integers N and M separated by a single space. N defines the N * N * N matrix. M defines the number of operations. The next M lines will contain either 1. UPDATE x y z W 2. QUERY x1 y1 z1 x2 y2 z2

Constraints
1 <= T <= 50 1 <= N <= 100 1 <= M <= 1000 1 <= x1 <= x2 <= N 1 <= y1 <= y2 <= N 1 <= z1 <= z2 <= N 1 <= x,y,z <= N -10^9 <= W <= 10^9

Output Format
Print the result for each QUERY.

Sample Input
2
4 5
UPDATE 2 2 2 4
QUERY 1 1 1 3 3 3
UPDATE 1 1 1 23
QUERY 2 2 2 4 4 4
QUERY 1 1 1 3 3 3
2 4
UPDATE 2 2 2 1
QUERY 1 1 1 1 1 1
QUERY 1 1 1 2 2 2
QUERY 2 2 2 2 2 2
Sample Output
4
4
27
0
1
1
Explanation
First test case, we are given a cube of 4 * 4 * 4 and 5 queries. Initially all the cells (1,1,1) to (4,4,4) are 0. 
UPDATE 2 2 2 4 makes the cell (2,2,2) = 4 
QUERY 1 1 1 3 3 3. As (2,2,2) is updated to 4 and the rest are all 0. The answer to this query is 4. 
UPDATE 1 1 1 23. updates the cell (1,1,1) to 23. QUERY 2 2 2 4 4 4. Only the cell (1,1,1) and (2,2,2) are non-zero and (1,1,1) is not between (2,2,2) and (4,4,4). So, the answer is 4. 
QUERY 1 1 1 3 3 3. 2 cells are non-zero and their sum is 23
*/
#include <iostream>
#include <cstring>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 110
#define ll long long int

ll BIT[SIZE][SIZE][SIZE];

ll n;

void update(ll x,ll y,ll z,ll val) {
    for (ll i = x ; i <= n; i += i & (-i)) {
        for (ll j = y ; j <= n; j += j & (-j)) {
            for (ll k = z ; k <= n; k += k & (-k)) {
                BIT[i][j][k] +=  val;
            }
        }
    }
}

ll sum(ll x,ll y,ll z) {
    ll sum = 0;
    for (ll i = x; i > 0; i -= i & (-i)) {
        for (ll j = y; j > 0; j -= j & (-j)) {
            for (ll k = z; k > 0; k -= k & (-k)) {
                sum += BIT[i][j][k];
            }
        }
    }
    return sum;
}

ll query(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
    x1--; y1--; z1--;
    ll res = sum(x2,y2,z2) - sum(x1,y2,z2) - sum(x2,y1,z2) - sum(x2,y2,z1) + sum(x1,y1,z2) + sum(x1,y2,z1) + sum(x2,y1,z1) - sum(x1,y1,z1);
    return res;
}



// void prllBIT() {
//     cout << "BIT = " << endl;
//     for (ll i = 0; i < 5; ++i) {

//         cout << "i = " << i <<endl;
//         for (ll j = 0; j < 5; ++j) {
//             for (ll k = 0; k < 5; ++k) {
//                 cout << BIT[i][j][k] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
// }

int main() {
    sync;
    ll testCases;
    cin >> testCases;
    while (testCases--) {
        cin >> n;
        n++;
        
        memset(BIT,0,sizeof(BIT));

        ll last[n][n][n];
        memset(last,0,sizeof(last));

        ll m;
        cin >> m;
        while(m--) {
            string s;
            cin >> s;
            // cout << s << endl;
            if(s == "UPDATE") {
                // cout << "updation";
                ll x,y,z,w;
                cin >> x >> y >> z >> w;
                ll val = w - last[x][y][z];
                last[x][y][z] = w;
                update(x,y,z,val);
                // prllBIT(BIT);
            }
            else if (s == "QUERY") {
                // cout << "query poll";
                ll x1,y1,z1,x2,y2,z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                // x2++;  y2++; z2++;
                
                ll res = query(x1,y1,z1,x2,y2,z2);
                cout << res << endl;
            }
        }
    }

    return 0;
}
