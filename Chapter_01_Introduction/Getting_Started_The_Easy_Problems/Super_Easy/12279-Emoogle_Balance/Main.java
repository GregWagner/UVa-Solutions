/*
 * Problem 12279 - Emoogle Balance
 * Java version 6/10/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();
        boolean first = true;

        int testCase = 1;
        while (input.hasNext()) {
            int numberOfEvents = input.nextInt();
            if (numberOfEvents == 0) {
                break;
            }
            int balance = 0;
            for (int i = 0; i < numberOfEvents; ++i) {
                int event = input.nextInt();
                if (event == 0) {
                    --balance;
                } else {
                    ++balance;
                }
            }
            results.append("Case " + testCase + ": ");
            ++testCase;
            results.append(balance + "\n");
        }
        System.out.print(results.toString());
    }
}

