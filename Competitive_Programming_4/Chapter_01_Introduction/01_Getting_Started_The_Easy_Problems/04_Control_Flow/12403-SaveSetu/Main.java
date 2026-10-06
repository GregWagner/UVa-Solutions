/*
 * Problem 12403 Save Setu
 * Java version 6/8/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();

        int amount = 0;
        int operations = input.nextInt();
        while (operations > 0) {
            String s = input.next();

            if (s.equals("report")) {
                System.out.println(amount);
            } else {
                amount += input.nextInt();
            }
            --operations;
        }
    }
}

