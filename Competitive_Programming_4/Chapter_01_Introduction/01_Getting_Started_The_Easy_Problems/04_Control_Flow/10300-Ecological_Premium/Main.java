/*
 * Problem 10300 - Ecological Premium
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        int numberOfTestCases = input.nextInt();
        for (int i = 0; i < numberOfTestCases; ++i) {
            int numberOfFarmers = input.nextInt();
            int amount = 0;
            for (int j = 0; j < numberOfFarmers; ++j) {
                int size = input.nextInt();
                int numberOfAnimals = input.nextInt();
                int friendliness = input.nextInt();
        
                double premium = size * friendliness;
                amount += premium;
            }
            results.append(amount + "\n");
        }
        System.out.print(results.toString());
    }
}
