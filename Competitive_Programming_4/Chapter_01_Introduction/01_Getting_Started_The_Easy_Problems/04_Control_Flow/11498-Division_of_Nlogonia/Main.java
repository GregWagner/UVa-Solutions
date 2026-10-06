/*
 * Problem 11498 Division of Nlogonia
 * Java version 6/8/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();

        while (true) {
            int numberOfQueries = input.nextInt();
            if (numberOfQueries == 0) {
                break;
            }

            int n = input.nextInt();
            int m = input.nextInt();

            for (int i = 0; i < numberOfQueries; ++i) {
                int x = input.nextInt();
                int y = input.nextInt();

                if (x == n || y == m) {
                    results.append("divisa\n");
                } else if (x > n) {
                    if (y > m) {
                        results.append("NE\n");
                    } else {
                        results.append("SE\n");
                    }
                } else {
                    if (y > m) {
                        results.append("NO\n");
                    } else {
                        results.append("SO\n");
                    }
                }
            }
        }
        System.out.print(results.toString());
    }
}

