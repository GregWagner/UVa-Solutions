/*
 * 12554 - A Special Happy Birthday
 * Java version 6/13/2016
 */

import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer results = new StringBuffer();

        String[] s = {"Happy", "birthday", "to", "you",
            "Happy", "birthday", "to", "you",
            "Happy", "birthday", "to", "Rujia",
            "Happy", "birthday", "to", "you"};
        String[] names = new String[110];

        int count = input.nextInt();
        for (int i = 0; i < count; ++i) {
            names[i] = input.next();
        }

        if (count <= 16) {
            for (int i = 0; i < 16; ++i) {
                results.append(names[i % count] + ": " + s[i] + "\n");
            }
        } 

        int loopCount = 0;
        int nameCount = 0;
        int nameCounter = 0;
        int songCounter = 0;
        while (true) {
            results.append(names[nameCounter] + ": " +
                    s[songCounter] + "\n");
            ++nameCounter;
            ++songCounter;
            if (nameCounter > count) {
                nameCounter = 0;
                ++nameCount;
                if (songCounter > 0) {
                    break;
                }
            }
            if (songCounter >= 16) {
                ++loopCount;
                songCounter = 0;
                if (nameCounter > 0) {
                    break;
                }
            }
        }
        System.out.print(results.toString());
    }
}

