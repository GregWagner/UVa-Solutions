/*
 * Problem 10963 - The Swallowing Ground
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();
        boolean first = true;

        int numberOfTestCases = input.nextInt();
        for (int i = 0; i < numberOfTestCases; ++i) {
            int numberOfColumns = input.nextInt();
            boolean closeable = true;
            int gap = -1;
            for (int j = 0; j < numberOfColumns; ++j) {
                int x = input.nextInt();
                int y = input.nextInt();
                int currentGap = Math.abs(x - y);
                if (gap == -1) {
                    gap = currentGap;
                }
                if (gap != currentGap) {
                    closeable = false;
                }
            }
            if (first) {
                first = false;
            } else {
                results.append("\n");
            }
            results.append(closeable ? "yes\n" : "no\n");
        }

        System.out.print(results.toString());
    }
}

