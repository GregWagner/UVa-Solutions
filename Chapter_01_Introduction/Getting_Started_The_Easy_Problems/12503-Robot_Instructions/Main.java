/*
 * Problem 12503 - Robot Instructions
 * Java version 6/13/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();
        char[] a = new char[101];

        int numberOfTestCases = input.nextInt();
        for (int i = 0; i < numberOfTestCases; ++i) {
            int position = 0;
            int numberOfInstructions = input.nextInt();
            for (int j = 1; j <= numberOfInstructions; ++j) {
                String instruction = input.next();
                
                switch (instruction) {
                    case "LEFT":
                        a[j] = 'L';
                        break;

                    case "RIGHT":
                        a[j] = 'R';
                        break;

                    default:
                        instruction = input.next();     // read in AS
                        int sameAs = input.nextInt();
                        a[j] = a[sameAs];
                        break;

                }

                if (a[j] == 'L') {
                    --position;
                } else if (a[j] == 'R') {
                    ++position;
                }
            }
            results.append(position + "\n");
        }
        System.out.print(results.toString());
    }
}

