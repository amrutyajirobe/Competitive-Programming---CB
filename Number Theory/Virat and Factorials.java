/*
Virat and Factorials

Virat Kohli now wants to learn coding. So Dhoni gave him a simple task of calculating factorial of a number. Help him finish this task.

Input Format
Single line containing an integral value N.

Constraints
1<=N<=100

Output Format
Print the integral value denoting factorial of 'N'.

Sample Input
3
Sample Output
6
*/

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        BigInteger f = BigInteger.ONE;
        for (int i = 1; i <= n; ++i) {
            f = f.multiply(BigInteger.valueOf(i));
        }
        System.out.println(f);
    }
}
