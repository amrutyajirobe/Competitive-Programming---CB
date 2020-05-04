/*
FAVDICE - Coupon Collector Problem
BuggyD loves to carry his favorite die around. Perhaps you wonder why it's his favorite? Well, his die is magical and can be transformed into an N-sided unbiased die with the push of a button. Now BuggyD wants to learn more about his die, so he raises a question:

What is the expected number of throws of his die while it has N sides so that each number is rolled at least once?

Input Format
The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of a single line containing a single integer N - the number of sides on BuggyD's die

Constraints
1 <= T <= 15 1 <= N <= 1000

Output Format
For each test case, print one line containing the expected number of times BuggyD needs to throw his N-sided die so that each number appears at least once. The expected number must be accurate to 2 decimal digits.

Sample Input
2
1
12
Sample Output
1.00
37.24
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll  long long int

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin >> n;
        double ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += (n/(double)(i));
        }
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}
