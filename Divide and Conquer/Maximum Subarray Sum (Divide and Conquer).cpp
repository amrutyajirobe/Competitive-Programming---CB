/*
Maximum Subarray Sum (Divide and Conquer)
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7. NOTE:- please solve this problem using Divide and Conquer instead of kadane's algorithm.

Input Format
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints
1 <= N <= 100000 1 <= t <= 20 0 <= A[i] <= 100000000

Output Format
The maximum subarray sum

Sample Input
2
4
1 2 3 4
3
-10 5 10
Sample Output
10
15
*/
#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int arr[], int start, int end) { 
    int sum = 0; 
    int leftSum = INT_MIN; 

    int mid = (start+end)/2;

    for (int i = mid; i >= start; i--) { 
        sum = sum + arr[i]; 
        if (sum > leftSum) {
            leftSum = sum; 
        }
    } 

    // Include elements on right of mid 
    sum = 0; 
    int rightSum = INT_MIN; 
    for (int i = mid+1; i <= end; i++) { 
        sum = sum + arr[i]; 
        if (sum > rightSum) {
            rightSum = sum; 
        }
    } 

    // Return sum of elements on left and right of mid 
    return leftSum + rightSum; 
} 

// Returns sum of maxium sum subarray in aa[l..h] 
int maxSubArraySum(int arr[], int start, int end) { 
    if (start == end) 
        return arr[start]; 

    // Find middle point 
    int mid = (start + end)/2; 

    int leftMaxSum = maxSubArraySum(arr, start, mid);
    int rightMaxSum = maxSubArraySum(arr, mid+1, end);
    int crossingSum = maxCrossingSum(arr, start, end);

    return max(leftMaxSum, max(rightMaxSum, crossingSum));
} 

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << maxSubArraySum(arr, 0, n-1) << endl;
    }

    return 0;
}
