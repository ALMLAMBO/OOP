package org.elsys;

import java.util.Scanner;

//link:
//https://www.hackerrank.com/contests/elsys-java-exercise-1-11a/challenges/java-loops

public class JavaLoopsII {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i=0;i<t;i++){
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int n = scanner.nextInt();
            int result = 0;
            for(int j = 0; j < n; j++) {
                if(result == 0) {
                    result = a;
                }
                result += Math.pow(2, j) * b;
                System.out.printf("%d ", result);
            }
            System.out.println();
        }
        scanner.close();
    }
}
