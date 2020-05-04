/*
Big GCD

Alice recently learnt calculating greatest common divisor. Now Bob wants to test his knowledge and gives him two numbers (one of them being extremely large) to calculate gcd. Alice needs your help to finish this task.

Input Format
Single line containing two integral values (N and M).

Constraints
0<=N<=10000000 and N <= M < 10^250

Output Format
Print the Greatest Common Divisor of two numbers.

Sample Input
3 9
Sample Output
3
*/

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        BigInteger n = new BigInteger(s);
        s = sc.next();
        BigInteger m = new BigInteger(s);
        BigInteger ans = n.gcd(m);
        System.out.println(ans);
    }
}

