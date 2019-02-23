package org.elsys;

import java.util.Scanner;

public class EndOfFile {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int index = 1;
        while (scanner.hasNext()) {
            String consoleArgs = scanner.nextLine();
            System.out.printf("%d %s\n",
                    index, consoleArgs);
            index++;
        }
    }
}