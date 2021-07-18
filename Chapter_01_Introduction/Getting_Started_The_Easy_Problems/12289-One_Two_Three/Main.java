/*
 * Problem 12289 - One-Two-Three
 * Java version 6/8/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();
        boolean first = true;

        int testCase = input.nextInt();
        while (testCase-- != 0) {
            String s = input.next();

            if (s.length() == 5) {
                results.append("3\n");
            } else {
                if ((s.charAt(0) == 'o') && (s.charAt(1) == 'n')) {
                    results.append("1\n");
                } else if ((s.charAt(0) == 'o') && (s.charAt(2) == 'e')) {
                    results.append("1\n");
                } else if ((s.charAt(1) == 'n') && (s.charAt(2) == 'e')) {
                    results.append("1\n");
                } else {
                    results.append("2\n");
                }
            }
        }
        System.out.print(results.toString());
    }
}
