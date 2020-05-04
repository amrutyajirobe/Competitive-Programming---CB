/*
Count Number of Binary Strings
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints:
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
*/
#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ll fib[90];
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < 90; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        cout << fib[n] << endl; 
    }


    return 0;
}
