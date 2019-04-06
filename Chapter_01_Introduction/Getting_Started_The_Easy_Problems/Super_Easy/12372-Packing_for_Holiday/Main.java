/*
 * Problem 12372 - Packing for Holiday
 * Java version 6/10/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();
        int testCases = input.nextInt();
        for (int i = 0; i < testCases; ++i) {
            int length = input.nextInt();
            int width = input.nextInt();
            int height = input.nextInt();

            results.append("Case " + (i + 1) + ": ");
            if (length <= 20 && width <= 20 && height <= 20) {
                results.append("good\n");
            } else {
                results.append("bad\n");
            }
        }
        System.out.print(results.toString());
    }
}
