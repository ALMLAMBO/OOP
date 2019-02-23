package org.elsys;

import java.util.Scanner;

public class Java1DArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        int []a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(scanner.nextLine());
        }

        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
}