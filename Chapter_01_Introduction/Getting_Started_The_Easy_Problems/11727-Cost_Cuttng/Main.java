/*
 * Problem 11727 - Cost Cutting
 * Java version 6/8/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();

        int numberOfQueries = input.nextInt();
        for (int i = 0; i < numberOfQueries; ++i) {
            int a = input.nextInt();
            int b = input.nextInt();
            int c = input.nextInt();

            int min = Math.min(a, Math.min(b, c));
            int max = Math.max(a, Math.max(b, c));

            results.append("Case " + (i + 1) + ": " +
                    (a + b + c - min - max) + "\n");
        }
        System.out.print(results.toString());
    }
}
