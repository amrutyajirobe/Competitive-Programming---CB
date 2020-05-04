/*
XOR-4
Mike has got an array A of n numbers where binary representations of two consecutive numbers differ by only one bit. Now, he has a problem for you. He wants you to tell if there exists four numbers A[i1],A[ i2], A[i3],A[ i4] such that xor of these numbers is equal to 0. You can find this problem here.

Input Format
First line contains one integer n. Second line contains n space separated non-negative integers denoting the sequence A.

Constraints
4 <= n <= 100000

Output Format
Output YES if there exist four distinct indices i1, i2, i3, i4 such that A[i1] xor A[i2] xor A[i3] xor A[i4] = 0. Otherwise, output NO.

Sample Input
5
1 0 2 3 7
Sample Output
YES
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n >= 130) {
        cout << "YES";
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                for (int l = k+1; l < n; ++l) {
                    if((a[i]^a[j]^a[k]^a[l]) == 0) {
                        cout << "YES";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO";

    return 0;
}
