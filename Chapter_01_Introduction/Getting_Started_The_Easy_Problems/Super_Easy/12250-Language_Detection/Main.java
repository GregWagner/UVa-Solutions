/*
 * Problem 12250 - Language Detection
 * Java version 6/10/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    static final Scanner input = new Scanner(System.in);
    static final PrintStream output = System.out;

    public static void main(String[] args) {

        StringBuffer results = new StringBuffer();

        int testCase = 1; 
        while (input.hasNext()) {
            String s = input.nextLine();
            if (s.equals("#")) {
                break;
            }
            results.append("Case " + testCase + ": ");
            ++testCase;

            switch (s) {
                case "HELLO":
                    results.append("ENGLISH");
                    break;
                case "HOLA":
                    results.append("SPANISH");
                    break;
                case "HALLO":
                    results.append("GERMAN");
                    break;
                case "BONJOUR":
                    results.append("FRENCH");
                    break;
                case "CIAO":
                    results.append("ITALIAN");
                    break;
                case "ZDRAVSTVUJTE":
                    results.append("RUSSIAN");
                    break;
                default:
                    results.append("UNKNOWN");
                    break;
            }
            results.append('\n');
        }
        System.out.print(results.toString());
    }
}

