package org.elsys;

import java.util.HashSet;
import java.util.Scanner;

public class JavaHashSet {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());
        String[] pair_left = new String[t];
        String[] pair_right = new String[t];

        for (int i = 0; i < t; i++) {
            pair_left[i] = scanner.next();
            pair_right[i] = scanner.next();
        }

        HashSet<String> hashData = new HashSet<>();
        for (int i = 0; i < t; i++) {
            String data = pair_left[i] + " " + pair_right[i];
            hashData.add(data);
            System.out.println(hashData.size());
        }
    }
}