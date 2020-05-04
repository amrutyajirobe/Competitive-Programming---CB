/*
MARBLES
Hänschen dreams he is in a shop with an infinite amount of marbles. He is allowed to select n marbles. There are marbles of k different colors. From each color, there are also infinitely many marbles. Hänschen wants to have at least one marble of each color, but still there are a lot of possibilities for his selection. In his effort to make a decision he wakes up. Now he asks you how many possibilities for his selection he would have had. Assume that marbles of equal color can't be distinguished, and the order of the marbles is irrelevant.

Input Format
The first line of input contains a number 'T' that indicates the number of test cases to follow. Each test case consists of one line containing n and k, where n is the number of marbles Hänschen selects and k is the number of different colors of the marbles.

Constraints
1<=T<=100 1<=k<=n<=1000000

Output Format
For each test case print the number of possibilities that Hänschen would have had. You can assume that this number exceeds the limit of a signed 64-bit integer.

Sample Input
2
10 10
30 7
Sample Output
1
475020
*/
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            BigInteger ans = new BigInteger("1");
            for(int i=n-1;i>=n-r+1;i--) {
                ans = ans.multiply(BigInteger.valueOf(i));
                ans = ans.divide(BigInteger.valueOf(n-i));
            }
            System.out.println(ans);
        }
    }
}