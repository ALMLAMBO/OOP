package org.elsys;

import java.util.Scanner;

public class DataTypes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < t; i++) {
            try {
                long x = scanner.nextLong();
                System.out.printf("%d can be fitted in:\n", x);
                if (x >= -128 && x <= 127) {
                    System.out.println("* byte");
                }
                if (x >= -32768 && x <= 32767) {
                    System.out.println("* short");
                }
                if (x >= -2147483648l && x <= 2147483647l) {
                    System.out.println("* int");
                }
                if (x >= -9223372036854775808l
                        && x <= 9223372036854775807l) {
                    System.out.println("* long");
                }
            } catch (Exception e) {
                System.out.printf("%s can't be fitted anywhere.\n",
                        scanner.next());
            }
        }
    }
}