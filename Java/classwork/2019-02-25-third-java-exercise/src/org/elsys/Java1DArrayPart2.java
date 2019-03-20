package org.elsys;

import java.util.Scanner;

public class Java1DArrayPart2 {
    public static boolean canWin(int leap, int[] game) {
        boolean win = false;
        for (int i = 0; i < game.length; i += leap) {
            if(game[i] == 0) {
                win = true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int queries = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < queries; i++) {
            int size = scanner.nextInt();
            int leap = scanner.nextInt();

            int []game = new int[size];
            for (int j = 0; j < size; j++) {
                game[j] = scanner.nextInt();
            }
            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
    }
}