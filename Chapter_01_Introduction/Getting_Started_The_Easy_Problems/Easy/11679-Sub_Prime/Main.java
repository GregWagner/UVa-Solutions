/*
 * Problem 11679 - Sub-prime
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        while (true) {
            int numberOfBanks = input.nextInt();
            int numberOfDebentures = input.nextInt();

            if (numberOfBanks == 0 && numberOfDebentures == 0) {
                break;
            }

            int[] a = new int[numberOfBanks];
            for (int i = 0; i < a.length; ++i) {
                a[i] = input.nextInt();
            }

            for (int i = 0; i < numberOfDebentures; ++i) {
                int debtor = input.nextInt() - 1;
                int creditor = input.nextInt() - 1;
                int value = input.nextInt();

                a[debtor] -= value;
                a[creditor] += value;
            }

            boolean solvant = true;
            for (int i = 0; i < a.length; ++i) {
                if (a[i] < 0) {
                    solvant = false;
                    break;
                }
            }
            if (solvant) {
                results.append("S\n");
            } else {
                results.append("N\n");
            }

        }
        System.out.print(results.toString());
    }
}

