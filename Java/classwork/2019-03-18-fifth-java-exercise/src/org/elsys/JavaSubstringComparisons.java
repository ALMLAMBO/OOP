package org.elsys;

import java.util.Scanner;

public class JavaSubstringComparisons {
    public static String getSmallestAndLargest(String s, int k) {
        String smallest = "";
        String largest = "";
        smallest = s.substring(0, k);
        largest = s.substring(0, k);
        for(int i = 1; i < s.length() - k + 1; i++) {
            String sub = s.substring(i, i + k);
            if(smallest.compareTo(sub) > 0) {
                smallest = sub;
            }
            if(largest.compareTo(sub) < 0) {
                largest = sub;
            }
        }
        return smallest + "\n" + largest;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int k = scanner.nextInt();
        scanner.close();
        System.out.println(getSmallestAndLargest(s, k));
    }
}