/*
 * Problem 11764 - Jumping Mario
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
            int numberOfWalls = input.nextInt();

            int currentWall = input.nextInt();
            int high = 0;
            int low = 0;
            for (int j = 1; j < numberOfWalls; ++j) {
                int wall = input.nextInt();
                if (currentWall > wall) {
                    ++low;
                } else if (currentWall < wall) {
                    ++high;
                }
                currentWall = wall;
            }
            results.append("Case " + i + ": " + high + " " + low + "\n");
        }
        System.out.print(results.toString());
    }
}

