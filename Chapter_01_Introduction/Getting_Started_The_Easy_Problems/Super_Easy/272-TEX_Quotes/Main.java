/*
 * Problem 272 - TeX Quotes
 *
 * Replaces the first quote with `` and the second with ''
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

        while (input.hasNext()) {
            String s = input.nextLine();
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) == '\"') {
                    if (first) {
                        results.append("``");
                        first = false;
                    } else {
                        results.append("''");
                        first = true;
                    }
                } else {
                    results.append(s.charAt(i));
                }
            }
            results.append('\n');
        }
        System.out.print(results.toString());
    }
}

