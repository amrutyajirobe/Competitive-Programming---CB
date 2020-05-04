/*
Counting In Byteland
For once, lets assume Byteland to be a 3 dimensional space of size N X N X N. The Lolympics Committee has decided that every contingent representing a country will stay in a hotel at a particular coordinate denoted by its x-axis, y-axis and z-axis. Now, the Players Welfare Association(PWA) has to answer some queries as well as give accommodation to the Lolympic players. There will be Q number of queries which can be of two types:- 1. 1 x y z val - A contingent consisting of val number of players have been alloted a hotel in the coordinate (x,y,z).
2. 2 x y z X Y Z- Calculate the total number of players who are not residing in the coordinates ranging from (x <= xi <= X, y <= yi <= Y, z <= zi <= Z)
For stricter evaluation submit here .

Input Format
The first line consists of two numbers N and Q. Next Q lines consists of queries of the two forms mentioned above.

Constraints
1 <= N <= 100 1 <= Q <= 100000 0 <= x,y,z <= X,Y,Z <= N 1 <= val <= 1000000000

Output Format
Print the answer for query 2 in a single line.

Sample Input
10 6
1 0 0 6 6
1 9 9 9 10
1 8 5 9 5
2 3 4 5 9 10 9
1 6 6 1 23
2 0 0 0 8 9 10
Sample Output
6
10
Explanation
For the first query of type 2, the number of players residing in the coordinates ranging from (3,4,5) to (9,10,9) is 15. So answer is 21 - 15 = 6.
For the second query of type 2, the number of players residing in the coordinates ranging from (0,0,0) to (8,9,10) is 34. So answer is 44 - 34 = 10.
*/
#include <iostream>
#include <cstring>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 105
#define ll long long int

ll BIT[SIZE][SIZE][SIZE];

ll n;

void update(ll x,ll y,ll z,ll inc) {
    x++;    y++;    z++;
    for (ll i = x ; i <= n; i += (i & (-i)) ) {
        for (ll j = y ; j <= n; j += (j & (-j)) ) {
            for (ll k = z ; k <= n; k = k + (k&(-k)) ) {
                BIT[i][j][k] +=  inc;
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
    x2++; y2++; z2++;
    ll res = sum(x2,y2,z2) - sum(x1,y2,z2) - sum(x2,y1,z2) - sum(x2,y2,z1) + sum(x1,y1,z2) + sum(x1,y2,z1) + sum(x2,y1,z1) - sum(x1,y1,z1);
    return res;
}



// void printBIT() {
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
    
    cin >> n;
    n++;

    // cout << "n = " << n << endl;
    
    memset(BIT,0,sizeof(BIT));

    // ll last[n][n][n];
    // memset(last,0,sizeof(last));

    // cout << "ok";

    ll currentlyResiding = 0 ;

    ll m;
    cin >> m;
    while(m--) {
        int q;
        cin >> q;
        if(q == 1) {
            ll x,y,z,w;
            cin >> x >> y >> z >> w;
            // ll val = w - last[x][y][z];
            // last[x][y][z] = w;
            currentlyResiding += w;
            update(x,y,z,w);
    //         // printBIT(BIT);
        }
        else {
            ll x1,y1,z1,x2,y2,z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            
            ll res = currentlyResiding - query(x1,y1,z1,x2,y2,z2);
            cout << res << endl;
        }
    }

    return 0;
}
