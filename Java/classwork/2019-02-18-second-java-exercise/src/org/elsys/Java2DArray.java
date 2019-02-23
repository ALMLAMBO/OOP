package org.elsys;

import java.util.Scanner;

public class Java2DArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] commandLineArgs =
                    scanner.nextLine().split("\\s+");

            for (int j = 0; j < 6; j++) {
                arr[i][j] = Integer.parseInt(commandLineArgs[j]);
            }
        }

        int maxValue = Integer.MIN_VALUE;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int result = (
                        arr[i][j] + arr[i][j + 1] + arr[i][j + 2]
                        + arr[i + 1][j + 1]
                        + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]);
                if(result > maxValue) {
                    maxValue = result;
                }
            }
        }
        System.out.println(maxValue);
    }
}