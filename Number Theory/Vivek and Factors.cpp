/*
Vivek and Factors

Vivek loves to play number games with his friend Ujjawal. One day they were playing a game where one of them will speak out a positive number and the other have to tell the sum of its factors. The first one to say it correctly wins. After a while they got bored and wanted to try out a different game. Vivek then suggested about trying the reverse. That is, given a positive number 'S' , they have to find a number whose factors add up to 'S'. Realizing that this task is tougher than the original task, Vivek came to you for help. Luckily Vivek owns a portable programmable device and you have decided to burn a program to this device. Given the value of 'S' as input to the program, it will output a number whose sum of factors equal to 'S' .

Input Format
There are several cases . Each case of input will consist of a positive integer 'S'<= 100000 . The last case is followed by a value of 0 .

Constraints
0 < S <= 10000

Output Format
print the integer whose factors sum is equal to 'S'. Print the largest Integer whose factors sum is 'S' . If no such number exists, output '-1' .

Sample Input
1
102
1000
0
Sample Output
1
101
-1
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll  long long int
#define vi  vector<ll>

ll factorSum(ll n) { 
    ll res = 1; 
    for (ll i = 2; i*i <= n; i++) { 
        ll currentSum = 1; 
        ll currentTerm = 1; 
        while (n % i == 0) { 
            n = n / i; 
  
            currentTerm *= i; 
            currentSum += currentTerm; 
        } 
  
        res *= currentSum; 
    } 
  
    // This condition is to handle the case when n is a prime number greater than 2. 
    if (n >= 2) 
        res *= (1 + n); 
  
    return res; 
} 

int main() { 
    sync;

    unordered_map<ll,ll> m;
    for (ll i = 1; i <= 100000; ++i) {
        ll x = factorSum(i);
        if((m.find(x) == m.end()) || (m[x] < i)) 
            m[x] = i;
    }
    
    ll n = 1;
    while(n != 0) {
        cin >> n;
        if(n == 0)
            break;
        if(m.find(n) == m.end()) {
            cout << -1 << endl;
        }
        else { 
            cout << m[n] << endl;   
        }
    }


    

    
    return 0;
}
