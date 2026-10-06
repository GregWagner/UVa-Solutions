/*
 * 10114 Loansome Car Buyer
 * Java version 6/11/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();
        double[] a = new double[200];

        while (true) {
            int duration = input.nextInt();     // in months
            double downPayment = input.nextDouble();
            double amount = input.nextDouble();
            int numberOfRecords = input.nextInt();

            if (duration < 0) {
                break;
            }

            double payment = amount / duration;

            for (int i = 0; i < numberOfRecords; ++i) {
                int month = input.nextInt();
                double rate = input.nextDouble();
                for (int index = month; index < duration; ++index) {
                    a[index] = rate;
                }
            }

            // calculate the starting amount due and worth
            double amountOwed = amount + downPayment;
            double worth = amountOwed - (amountOwed * a[0]);

            int month = 0;
            while (worth <= amount) {
                ++month;
                if (month > a.length) {
                    break;
                }
                amount -= payment;
                worth = worth - (worth * a[month]);
            }
            System.out.println(month == 1 ? ("1 month") :
                    (month + " months"));
        }
    }
}
