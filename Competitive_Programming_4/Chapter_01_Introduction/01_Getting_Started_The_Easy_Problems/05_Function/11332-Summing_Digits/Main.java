/*
 * Problem 11332 - Summing Digits
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        while (true) {
            long number = input.nextLong();
            if (number == 0) {
                break;
            }

            while (number >= 10) {
                number = sum(number);
            }
            results.append(number + "\n");
        }
        System.out.print(results.toString());
    }

    private static long sum(long n) {
        long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
}
