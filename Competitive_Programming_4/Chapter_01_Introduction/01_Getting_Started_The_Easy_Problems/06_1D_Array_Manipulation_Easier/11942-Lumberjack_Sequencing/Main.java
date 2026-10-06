/*
 * 11942 - Lumberjack Sequencing
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();
        int[] a = new int[10];
        results.append("Lumberjacks:\n");

        int numberOfTestCases = input.nextInt();
        for (int i = 0; i < numberOfTestCases; ++i) {
            for (int j = 0; j < a.length; ++j) {
                a[j] = input.nextInt();
            }

            boolean sorted = false;
            if (a[0] > a[1]) {
                sorted = sortDown(a);
            } else {
                sorted = sortUp(a);
            }
            results.append(sorted ? "Ordered\n" : "Unordered\n");
        }
        System.out.print(results.toString());
    }

    private static boolean sortDown(int[] a) {
        for (int i = 1; i < a.length; ++i) {
            if (a[i - 1] < a[i]) {
                return false;
            }
        }
        return true;
    }

    private static boolean sortUp(int[] a) {
        for (int i = 1; i < a.length; ++i) {
            if (a[i - 1] > a[i]) {
                return false;
            }
        }
        return true;
    }
}
