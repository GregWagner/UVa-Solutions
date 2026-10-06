/*
 * Problem 12015 - Google is Feeling Lucky
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        int[] a = new int[10];
        String[] s = new String[10];

        int numberOfTestCases = input.nextInt();
        for (int j = 1; j <= numberOfTestCases; ++j) {
            int max = -1;
            results.append("Case #" + j + ":\n");
            for (int i = 0; i < a.length; ++i) {
                s[i] = input.next();
                a[i] = input.nextInt();
                if (a[i] > max) {
                    max = a[i];
                }
            }
            for (int i = 0; i < a.length; ++i) {
                if (a[i] == max) {
                    results.append(s[i] + "\n");
                }
            }
        }
        System.out.print(results.toString());
    }
}
