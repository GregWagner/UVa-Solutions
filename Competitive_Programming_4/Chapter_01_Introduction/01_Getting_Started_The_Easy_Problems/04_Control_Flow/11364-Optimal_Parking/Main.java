/*
 * Problem 11044 - Searching for Nessy
 * Java version 6/8/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {
        StringBuffer results = new StringBuffer();

        int numberOfCases = input.nextInt();
        for (int i = 0; i < numberOfCases; ++i) {
            int numberOfStores = input.nextInt();
            int max = -1;
            int min = 100;
            for (int j = 0; j < numberOfStores; ++j) {
                int store = input.nextInt();
                min = Math.min(min, store);
                max = Math.max(max, store);
            }
            int parkingSpot = (min + max) / 2;
            int total = (parkingSpot - min) + (max - parkingSpot) +
                (max - min);
            results.append(total);
            results.append('\n');
        }
        System.out.print(results.toString());
    }
}




