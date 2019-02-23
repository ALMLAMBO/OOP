package org.elsys;

import java.util.Scanner;

public class JavaStdinStdoutII {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = Integer.parseInt(scanner.nextLine());
        double d = Double.parseDouble(scanner.nextLine());
        String s = scanner.nextLine();

        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    }
}