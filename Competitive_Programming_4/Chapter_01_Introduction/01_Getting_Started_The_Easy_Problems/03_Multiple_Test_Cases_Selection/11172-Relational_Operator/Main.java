/*
 * 11172 - Relational Operators
 * Take in 2 numbers and output the relation that is appropriate
 * for the given numbers.
 * Java version 6/8/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();

        int numberOfSets = input.nextInt();

        for (int i = 0; i < numberOfSets; ++i) {
            int a = input.nextInt();
            int b = input.nextInt();

            if (a < b) {
                results.append("<\n");
            } else if (a > b) {
                results.append(">\n");
            } else {
                results.append("=\n");
            }
        }
        System.out.print(results.toString());
    }
}
