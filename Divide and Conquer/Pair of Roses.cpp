/*
Pair of Roses
Deepak has limited amount of money which he can spend on his girlfriend. So he decided to buy two roses for her. Since roses are of varying sizes, their prices are different. Deepak wishes to completely spend that fixed amount of money on buying roses. As he wishes to spend all the money, he should choose a pair of roses whose prices when summed up are equal to the money that he has. Help Deepak choose such a pair of roses for his girlfriend.
NOTE: If there are multiple solutions print the solution that minimizes the difference between the prices i and j. After each test case you must print a blank line.

Input Format
First line indicates the number of test cases. Then, in the next line, the number of available roses, N is given. Next line will have N integers, representing the price of each rose, a rose costs less than 1000001. Then there is another line with an integer M, representing how much money Deepak has. There is a blank line after each test case.

Constraints
1= T =100 2 = N = 10000 Price[i]<1000001

Output Format
For each test case you must print the message: ‘Deepak should buy roses whose prices are i and j.’, where i and j are the prices of the roses whose sum is equal do M and i = j. You can consider that it is always possible to find a solution, if there are multiple solutions print the solution that minimizes the difference between the prices i and j.

Sample Input
2
2
40 40
80

5
10 2 6 8 4
10
Sample Output
Deepak should buy roses whose prices are 40 and 40.
Deepak should buy roses whose prices are 4 and 6.
Explanation
Find two such kind of price of roses which has sum up equal to Deepak's Money
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

pii pairOfRoses(ll *a, ll n, ll target) {
    ll i = 0;
    ll j = n-1;

    pii ans ;

    while(i<j) {
        if(a[i] + a[j] == target) {
            ans = mp(a[i],a[j]);
            i++;
        }
        else if(a[i] + a[j] < target) {
            i++;
        }
        else {
            j--;
        }
    }

    return ans;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a,a+n);

        ll target;
        cin >> target;

        pii ans =  pairOfRoses(a,n,target) ;


        cout << "Deepak should buy roses whose prices are " << ans.ff << " and " << ans.ss << ".\n";
    }

    return 0;
}
