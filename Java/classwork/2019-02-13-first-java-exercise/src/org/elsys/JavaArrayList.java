package org.elsys;

import java.util.ArrayList;
import java.util.Scanner;

//link:
//https://www.hackerrank.com/contests/elsys-java-exercise-1-11a/challenges/java-arraylist

public class JavaArrayList {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfElementsInArrayList = Integer.parseInt(scanner.nextLine());
        ArrayList<ArrayList<Integer>> coordinates = new ArrayList<>();

        for (int i = 0; i < numberOfElementsInArrayList; i++) {
            String [] commandLineArgs =
                    scanner.nextLine().split("\\s+");

            ArrayList<Integer> data = new ArrayList<>();
            for (int j = 0; j < commandLineArgs.length; j++) {
                data.add(Integer.parseInt(commandLineArgs[j]));
            }
            coordinates.add(data);
        }

        int queries = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < queries; i++) {
            String [] commandLineArgs =
                    scanner.nextLine().split("\\s+");

            int x = Integer.parseInt(commandLineArgs[1]);
            int y = Integer.parseInt(commandLineArgs[0]) - 1;

            if(x < coordinates.get(y).size()) {
                System.out.println(coordinates.get(y).get(x));
            }
            else {
                System.out.println("ERROR!");
            }
        }
    }
}
