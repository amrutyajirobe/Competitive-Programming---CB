/*
HEAD EXPECTATION
What is the expected number of coin flips for getting N consecutive heads, given N?

Input Format:
An integer n

Constraints:
Output Format
An integer denoting the required answer

Sample Input
1
Sample Output
2
*/

#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long int ans = (1<<(n+1)) - 2;
	cout << ans;
	return 0;
}
