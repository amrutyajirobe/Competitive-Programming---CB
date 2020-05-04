/*
Recursion-Codes of the string
Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format
Enter a number

Constraints
None

Output Format
Display all the possible codes

Sample Input
1125
Sample Output
[aabe, aay, ale, kbe, ky]
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<string> v;

void mappedStrings(string inp, string out) {
    if(inp.length() == 0) {
        v.push_back(out);
        return ;
    }

    char ch = inp[0] - '1' + 'a';
    string ros = inp.substr(1);

    mappedStrings(ros, out+ch);

    if(inp.length() >= 2) {
        int digit1 = inp[0] -'0';
        int digit2 = ros[0] -'0';
        int num = digit1*10 + digit2;
        ch = num + 'a' - 1;
        if(ch >= 'a' && ch <= 'z') {
            ros = inp.substr(2);
            mappedStrings(ros, out+ch);
        }
    }

}

int main() {
    string inp;
    cin >> inp;

    mappedStrings(inp,"");

    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] ;
        if(i < v.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}

