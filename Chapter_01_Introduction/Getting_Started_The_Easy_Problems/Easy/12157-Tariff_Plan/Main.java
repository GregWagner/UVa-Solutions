/*
 * Problem 12157 - Tarrif Plan
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
            int miles = 0;
            int juice = 0;
            int numberOfCalls = input.nextInt();
            for (int j = 0; j < numberOfCalls; ++j) {
                int seconds = input.nextInt();
                miles += seconds / 30;
                ++miles;
                juice += seconds / 60;
                ++juice;
            }
            miles *= 10;
            juice *= 15;
            if (miles < juice) {
                results.append("Case " + i + ": Mile " + miles + "\n");
            } else if (miles > juice) {
                results.append("Case " + i + ": Juice " + juice + "\n");
            } else {
                results.append("Case " + i + ": Mile Juice " + juice + "\n");
            }
        }
        System.out.print(results.toString());
    }
}
