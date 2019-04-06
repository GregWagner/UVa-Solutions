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
            int x = input.nextInt();
            int y = input.nextInt();
           
            results.append(((x / 3) * (y / 3)));
            results.append('\n');
        }
        System.out.print(results.toString());
    }
}



