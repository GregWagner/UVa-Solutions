/*
 * Problem 12577 - Hajj-e-Akbar
 * Java version 6/10/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();

        int i = 1;
        while (true) {
            String s = input.next();
            if (s.equals("*")) {
                break;
            }

            results.append("Case " + i++ + ": ");
            if (s.equals("Hajj")) {
                results.append("Hajj-e-Akbar\n");
            } else {
                results.append("Hajj-e-Asghar\n");
            }
        }
        System.out.print(results.toString());
    }
}

