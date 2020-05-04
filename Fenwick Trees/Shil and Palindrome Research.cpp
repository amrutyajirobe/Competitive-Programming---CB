/*
Shil and Palindrome Research
Shil got interested in palindrome research. For that he needs some research data for a particular string S. To obtain this data he has some queries of following type:

1 L x - update Lth character of string to x
2 L R - find if all the character of string from index L to R can be rearranged such that they can form a palindrome. If they can print "yes", else print "no".
Since you decided to help Shil with his research, its your responsibililty to make this data available as soon as possible. The original problem can be found here

Input Format
First line of input consists of two integers N and Q denoting length of string S and total number of queries. Next line consists of N lowercase english characters ('a' - 'z') . Next Q lines consists of queries. If the query is 1st type, then it will consists of two integers and a character x and if its of the 2nd type, it will consist of three integers.

Constraints
1 <= N <= 100000 1 <= Q <= 100000 1 <= L,R <= N All the characters in string S will be lowercase english letters ('a'-'z').

Output Format
For each query of 2nd type, output "yes" or "no" without the quotes.

Sample Input
5 4
ababb
2 2 3
1 3 b
2 1 4
2 1 5
Sample Output
no
no
yes
Explanation
For 1st query , 'b' and 'a' can't be rearranged to form the palindrome.
For 3rd query , 'a' , 'b' , 'b' , 'b' can't be rearranged to form the palindrome.
For 4th query , all the characters can be rearranged like 
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll BIT[100005][26];
int n;

void update(int i,char ch,int inc) {
    while(i <= n) {
        BIT[i][ch-'a'] += inc;
        i += (i&(-i));
    }
}

ll query(int i,char ch) {
    ll sum = 0 ;
    while(i > 0) {
        sum += BIT[i][ch-'a'];
        i -= (i&(-i));
    }
    return sum;
}



int main() {
    sync;

    memset(BIT,0,sizeof(BIT));

    cin >> n;

    int noOfQueries;
    cin >> noOfQueries;

    string v;
    cin >> v;

    for(int i=0;i<v.size();i++) {
        update(i+1,v[i],1);
    }

    // cout << v;

    while(noOfQueries--) {
        int q;
        cin >> q;
        if(q == 1) {
            int index;
            char ch;
            cin >> index >> ch;
            
            update(index,v[index-1],-1);
            update(index,ch,1);
            v[index-1] = ch;
            // cout << v << endl;
        }
        else {
            int l,r;
            cin >> l >> r;
            int oddCount = 0;
            // if((r - l + 1) % 2 == 0) {
            //     oddCount = 1;
            // }
            // else {
            //     oddCount = 2;
            // }
            bool ans = true;
            for(char ch='a';ch <= 'z' ; ch++) {
                ll val = query(r,ch) - query(l-1,ch);
                
                // cout << "ch - " << ch << "      freq = " << val <<  endl;
                if(val&1) {
                    oddCount++;
                    if(oddCount >= 2) {
                        ans = false;
                        break;
                    }
                }
            }

            if(ans) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
    }

    return 0;
}

