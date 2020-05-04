/*
Friends Pairing Problem
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Input Format:
First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.

Constraints:
1<= n < 30

Output Format
Output t lines each line describing the answer.

Sample Input
1
3
Sample Output
4
*/
#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ll arr[90];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i < 90; ++i) {
        arr[i] = arr[i-1] + (i-1)*arr[i-2];
    }

    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        cout << arr[n] << endl; 
    }


    return 0;
}
