/*
Murthal Parantha
The coding blocks members went to the success party of their first ever online boot-camp at Murthal. They ordered P number of paranthas. The stall has L cooks and each cook has a rank R. A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). Calculate the minimum time needed to cook all the paranthas.

Input Format
First line contains P, the number of pratha ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the Next line each denoting the rank of a cook.

Constraints
P <= 1000 L <= 50 1 <= R <= 8

Output Format
Print an integer which tells the number of minutes needed to get the order done.

Sample Input
10
4 
1 2 3 4
Sample Output
12
*/
#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int> &v, int p, int val) {
    int count = 0 ;
    for (int i = 0; i < v.size(); ++i) {
        int temp = 2*val/v[i];
        int j = 0;
        for (j = 0; j*j + j <= temp; ++j) ;
        count += j-1;

        if(count >= p) {
            return true;
        }
        // if(val == 3) {
        //     cout << count << endl;
        // }
    }
    

    return false;
}

int murthalPranthas(const vector<int> &v, int p) {
    int n = v.size();
    int start = 0;
    int end = p*p;
    int ans = end;

    while(start <= end) {
        int mid = (start+end)/2;
        if(isPossible(v,p,mid)) {
            ans = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }

    return ans;
}

int main() {
    int p;  //No of pranthas
    cin >> p;

    int n;  //No of cooks
    cin >> n;

    vector<int> v(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // sort(v.begin(), v.end());

    cout << murthalPranthas(v,p);

    return 0;
}
