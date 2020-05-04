/*
READ THE PAGES
You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j). You have to assign these N books to M students, such that each student has subsegment of books and the maximum number of pages assigned to a student is minimized.
You have to find the maximum number of pages, a student can have in this assignment of books.

Input Format:
First line contains integers, N and M, denoting the number of books and number of students respectively. Next line contains N integers, denoting the number of pages in N books.

Constraints:
1<=N<=10^5 1<=M<=N 1<=Pi<=10^9

Output Format
Print a single integer, denoting the answer.

Sample Input
4 2
10 20 30 40
Sample Output
60
*/
#include <iostream>
using namespace std;
#define ll long long int

bool isValidConfig(ll *books,ll n,ll k,ll ans){
    ll students = 1;
    ll currentPages = 0;
    for(ll i=0;i<n;i++){
        if(currentPages + books[i] > ans){
            currentPages = books[i];
            students++ ;
            if(students > k){
                return false;
            }
        }
        else {
            currentPages += books[i];
        }
    }
    return true ;
}

ll bookAllocation(ll *books,ll n,ll k){
    ll totalPages = 0;
    ll s = 0 ;
    for(ll i=0;i<n;i++){
        totalPages += books[i];
        s = max(s,books[i]);
    }

    ll e = totalPages ;

    ll finalAns = s;

    while(s <= e){
        ll mid = (s+e)/2;
        if(isValidConfig(books,n,k,mid)){
            finalAns = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return finalAns;
}


int main() {
    ll n ;      //No of books
    cin >> n;
    ll m ;      //No of students
    cin >> m;
    ll a[n];

    for(ll i=0;i<n;i++){
        cin >> a[i];
    }

    cout << bookAllocation(a,n,m) << endl;


    return 0;
}

