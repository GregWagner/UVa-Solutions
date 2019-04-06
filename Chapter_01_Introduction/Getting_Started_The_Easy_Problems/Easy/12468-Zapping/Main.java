/*
 * Problem 12468 - Zapping
 * Java version 6/13/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        while (true) {
            int a = input.nextInt();
            int b = input.nextInt();

            if (a < 0 && b < 0) {
                break;
            }

            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }

            int c = a - b;
            int d = (100 - a) + b;
            if (c > d) {
                results.append(d + "\n");
            } else {
                results.append(c + "\n");
            }
        }
        System.out.print(results.toString());
    }
}

