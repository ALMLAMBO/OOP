package org.elsys;

import java.util.Scanner;

public class JavaStringReverse {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        StringBuilder sb = new StringBuilder(s);
        System.out.println(s.equals(sb.reverse()
                .toString()) ? "Yes" : "No");
    }
}