/*
 * Problem 621 - Secret Research
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

        int testCases = input.nextInt();
        for (int i = 0; i < testCases; ++i) {
            String s = input.next();

            if (s.equals("1") || s.equals("4") || s.equals("78")) {
                results.append("+\n");

            } else if (s.length() >= 2 && s.charAt(s.length() - 1) == '5' &&
                    s.charAt(s.length() - 2) == '3') {
                results.append("-\n");

            } else if (s.length() >= 2 && s.charAt(0) == '9' &&
                    s.charAt(s.length() - 1) == '4') {
                results.append("*\n");
            } else {
                results.append("?\n");
            }
        }
        System.out.print(results.toString());
    }
}

