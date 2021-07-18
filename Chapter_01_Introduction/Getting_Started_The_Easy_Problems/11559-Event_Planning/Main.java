/*
 * Problem 11559 - Event Planning
 * Java version 6/12/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        while (input.hasNext()) {
            int numberOfParticipants = input.nextInt();
            int budget = input.nextInt();
            int numberOfHotels = input.nextInt();
            int numberOfWeeks = input.nextInt();

            int cost = budget + 1;
            for (int i = 0; i < numberOfHotels; ++i) {
                int totalCost = numberOfParticipants * input.nextInt();
                for (int j = 0; j < numberOfWeeks; ++j) {
                    int beds = input.nextInt();
                    if (beds >= numberOfParticipants) {
                        if (totalCost < budget && totalCost < cost) {
                            cost = totalCost;
                        }
                    }
                }
            }
            if (cost > budget) {
                results.append("stay home\n");
            } else {
                results.append(cost + "\n");
            }
        }
        System.out.print(results.toString());
    }
}
