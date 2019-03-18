package org.elsys;

import java.util.Scanner;

public class JavaAnagrams {
    static boolean isAnagram(String a, String b) {
        char [] arr1 = a.toLowerCase().toCharArray();
        char [] arr2 = b.toLowerCase().toCharArray();
        if(a.length() != b.length()) {
            return false;
        }
        java.util.Arrays.sort(arr1);
        java.util.Arrays.sort(arr2);
        for(int i = 0; i < arr1.length; i++) {
            if(arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.next();
        String b = scanner.next();
        scanner.close();
        boolean ret = isAnagram(a, b);
        System.out.println((ret) ? "Anagrams" : "Not Anagrams");
    }
}
