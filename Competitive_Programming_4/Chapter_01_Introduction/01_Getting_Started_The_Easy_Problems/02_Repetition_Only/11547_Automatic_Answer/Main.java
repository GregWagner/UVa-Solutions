/*
 * Problem 11547 -Automatic Answer
 * Java version 6/10/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {
        StringBuffer results = new StringBuffer();

        int numberOfCases = input.nextInt();
        for (int i = 0; i < numberOfCases; ++i) {
            int n = input.nextInt();
            int total = (((n * 63) + 7492) * 5) - 498;
            results.append(Math.abs((total / 10) % 10));
            results.append('\n');
        }
        System.out.print(results.toString());
    }
}




