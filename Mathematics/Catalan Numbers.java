/*
Catalan Numbers

Print nth Catalan Number. The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14,.. .

Input Format
One integer n

Constraints
1 <= N <= 100

Output Format
Print the catalan number at position N.

Sample Input
10
Sample Output
16796
*/
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		BigInteger ans = new BigInteger("1");
		int k = n;
		for (int i = 2*n; i >= n+2; i--) {
			 ans = ans.multiply(BigInteger.valueOf(i));
			// ans = ans.divide(BigInteger.valueOf(k));
			// k--;
		}
		BigInteger f = new BigInteger("1");
		for (int i = 1; i <= n; ++i) {
			f = f.multiply(BigInteger.valueOf(i));
		}

		ans = ans.divide(f);

		System.out.println(ans);
	}
}