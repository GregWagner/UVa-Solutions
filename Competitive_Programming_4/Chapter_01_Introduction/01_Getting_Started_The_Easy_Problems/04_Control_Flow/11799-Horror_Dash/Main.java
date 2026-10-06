/*
 * Problem 11799 - Horror Dash
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        int numberOfTestCases = input.nextInt();
        for (int i = 1; i <= numberOfTestCases; ++i) {
            int count = input.nextInt();
            int speed = 0;
            for (int j = 0; j < count; ++j) {
                int x = input.nextInt();
                if (x > speed) {
                    speed = x;
                }
            }
            results.append("Case " + i + ": " + speed + "\n");
        }
        System.out.print(results.toString());
    }
}

