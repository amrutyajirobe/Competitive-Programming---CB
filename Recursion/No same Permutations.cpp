/*
No same Permutations
Given a collection of numbers containing duplicates, print all possible permutations for the given collection of numbers in a lexicographic manner. Make sure that no two permutations are same.
NOTE: Try doing it without using SET or MAP!

Input Format
The first line will contain the number of elements, N in the array.
The second line will contain N elements of the array, A[i].

Constraints
1<= N <= 10 0 <= A[i] <= 100000

Output Format
Print all unique lexicographic permutations of the array. Each permutation will contain space separated elements. The next permutation should be printed in a new line.

Sample Input
3
1 1 3
Sample Output
1 1 3 
1 3 1 
3 1 1
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    do  {
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
