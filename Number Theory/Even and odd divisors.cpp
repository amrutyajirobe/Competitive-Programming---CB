/*
Even and odd divisors
Vivek likes to solve mathematical problems. So, Dheer tries to challenge him with a problem. But Vivek is quite busy these days, So he asks for your help.

The problem is as follows: You are given an integer q which denotes the number of queries. For each query, You are given an integer n. You have to find the result of number n.

The result of a number n is defined as the sum of even divisors of n minus the sum of odd divisors of n.

More Formally, result = (Sum of even divisors of n) - (Sum of odd divisors of n)

A divisor of a number n is defined as a positive integer i such that n is divisible by i.

Input Format
First line of input contains an integer q denoting the number of queries. After that q lines follow, Each line consists an integer n for which you have to find the value of result.

Note: Use fast input output as input is quite large;

Constraints
1 <= q <= 100000 1 <= n <= 100000

Output Format
You have to print q lines, where the output of the ith line is the result of the ith query.

Sample Input
2
3
6
Sample Output
-4
4
*/
#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ll long long int
#define vi vector<ll>

ll sumofoddFactors(ll n) { 
    ll res = 1; 
  
    // ignore even factors by removing all powers of 2 
    while (n % 2 == 0) 
        n = n / 2; 
  
    for (ll i = 3; i*i <= n; i++) { 
        ll count = 0, currentSum = 1 ;
        ll currentTerm = 1; 
        while (n % i == 0) { 
            count++; 
  
            n = n / i; 
  
            currentTerm *= i; 
            currentSum += currentTerm; 
        } 
  
        res *= currentSum; 
    } 
  
    if (n >= 2) 
        res *= (1 + n); 
  
    return res; 
} 

ll sumofEvenFactors(ll n) { 
    // If n is odd, then there are no even factors. 
    if (n % 2 != 0) 
       return 0;  
  
    // Traversing through all prime factors. 
    ll res = 1; 
    for (ll i = 2; i*i <= n; i++) { 
  
        // While i divides n, print i and divide n 
        ll count = 0, currentSum = 1, currentTerm = 1; 
        while (n % i == 0) { 
            count++; 
  
            n = n / i; 
  
            // here we remove the 2^0 that is 1. 
            if (i == 2 && count == 1) 
                currentSum = 0; 
  
            currentTerm *= i; 
            currentSum += currentTerm; 
        } 
  
        res *= currentSum; 
    } 
  
    if (n >= 2) 
        res *= (1 + n); 
  
    return res; 
}

ll oddEvenFactorSum(ll n) {
    return sumofEvenFactors(n)-sumofoddFactors(n);
}

int main() { 
    sync;

    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin >> n;
        cout << oddEvenFactorSum(n) << endl;
    }


    return 0;
}
