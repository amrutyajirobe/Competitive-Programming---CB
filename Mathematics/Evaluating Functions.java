/*
Evaluating functions

Alice is learning mathematical functions. In his assignment, teacher has asked him to evaluate h(x)= f(x)+g(x) where
f(x)=3x2-x+10 and
g(x)=4x3+2x2-5x+4.
As he is weak in mathematics, help him finish this task.

Hint: Since X is large, you need to work with Big Integers!

Input Format
Single line containing an integral value denoting the value of x.

Constraints
0<=x<=10^50

Output Format
Print integral value denoting value of h(x).

Sample Input
1
Sample Output
17
*/
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input;
		input = sc.next();
		BigInteger x = new BigInteger(input);

		// h(x)= f(x)+g(x) where
		// f(x)=3x2-x+10 and
		// g(x)=4x3+2x2-5x+4

		BigInteger f = x.multiply(x).multiply(BigInteger.valueOf(3)) ;	//f = 3x^2
		f = f.subtract(x);												//f = 3x^2 - x
		f = f.add(BigInteger.valueOf(10));								//f = 3x^2 - x +10

		BigInteger g = x.multiply(x).multiply(x).multiply(BigInteger.valueOf(4));//g=4x^3
		g = g.add(x.multiply(x).multiply(BigInteger.valueOf(2)));		//g=4x^3+2x^2
		g = g.subtract(x.multiply(BigInteger.valueOf(5)));			//g=4x^3+2x^2-5x
		g = g.add(BigInteger.valueOf(4));							//g=4x3+2x2-5x+4

		BigInteger h = f.add(g);

		System.out.println(h);
	}
}