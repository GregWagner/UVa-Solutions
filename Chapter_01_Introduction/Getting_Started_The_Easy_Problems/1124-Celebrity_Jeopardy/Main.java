/*
 * Problem 1124 - Celebrity Jeopardy
 * Java version 6/8/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();

        while (input.hasNext()) {
            String s = input.nextLine();
            results.append(s + "\n");
        }
        System.out.print(results.toString());
    }
}


