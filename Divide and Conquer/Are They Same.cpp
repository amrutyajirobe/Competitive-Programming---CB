/*
Are They Same
This year when tourist visited India for snackdown 2017. He and Rajat started discussing few problems on divide and conquer. tourist asked Rajat that if you have 2 strings s1 and s2 can you find if they are equivalent. Rajat then asked the condition for being equivalent to which tourist replied

Two strings a and b of equal length are called equivalent in one of the two cases:

They are equal. 2 .If we split string a into two halves of the same size a1 and a2, and string b into two halves of the same size b1 and b2, then one of the following is correct: 1 . a1 is equivalent to b1, and a2 is equivalent to b2 2 . a1 is equivalent to b2, and a2 is equivalent to b1
Rajat quickly solved the problem can you?

Input Format
First line is number of test cases t Then follow two strings each of same length

Constraints
1 <= test cases <= 10 1 <= string length <= 50000

Output Format
print "YES" if they are "equivalent" and "NO" if they are not

Sample Input
2
ababa
baaba
ab
ba
abc
abc
Sample Output
NO
YES
YES
Explanation
test case 1 : - you cannot split the string into two halves of same size and s1 != s2 hence they are not same
test case 2 :-  split ab as a and b and ba as b and a then conditon is fulfilled
test case 3 :-  they are already same
*/
#include <bits/stdc++.h>
using namespace std;

bool checkEquivalant(string s1, string s2) {
    if(s1 == s2) {
        // cout << s1 << " " << s2 << " true \n"; 
        return true;
    }

    if(s1.size() % 2 == 1) {
        //Odd length cannot be divided into two equal halves
        // cout << s1 << " " << s2 << " false \n";
        return false;
    }
    // cout << endl;

    int length = s1.size();

    string a1 = s1.substr(0,length/2);
    string a2 = s1.substr(length/2);

    string b1 = s2.substr(0,length/2);
    string b2 = s2.substr(length/2);

    bool x1 = checkEquivalant(a1, b1);
    bool x2 = checkEquivalant(a1, b2);
    bool x3 = checkEquivalant(a2, b1);
    bool x4 = checkEquivalant(a2, b2);

    // cout << s1 << " " << s2 << " " <<  x1 << x2 << x3 << x4 << endl;

    return (x1&&x4)||(x2&&x3);
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        string s1,s2;
        cin >> s1 >> s2;
        
        bool ans = checkEquivalant(s1,s2);

        if(ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
