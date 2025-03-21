/*
 * Problem 10550 - Combination Lock
 * Java version 6/11/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();
        boolean first = true;

        while (true) {
            int start = input.nextInt();
            int a = input.nextInt();
            int b = input.nextInt();
            int c = input.nextInt();

            if (start == 0 && a == 0 && b == 0 && c == 0) {
                break;
            }

            // clockwise from the start
            int ticks = start - a;
            if (ticks < 0) {
                ticks += 40;
            }
            int totalTicks = ticks;
    
            // counter clockwise
            ticks = b - a;
            if (ticks < 0) {
                ticks += 40;
            }
            totalTicks += ticks;

            // clockwise
            ticks = b - c;
            if (ticks < 0) {
                ticks += 40;
            }
            totalTicks += ticks;

            results.append(1080 + (totalTicks * 9) + "\n");
        }
        System.out.print(results.toString());
    }
}

