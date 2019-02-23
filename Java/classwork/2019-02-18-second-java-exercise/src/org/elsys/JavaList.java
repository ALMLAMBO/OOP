package org.elsys;

import java.util.LinkedList;
import java.util.Scanner;

public class JavaList {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfElements = Integer.parseInt(scanner.nextLine());
        LinkedList<Integer> numbers = new LinkedList<>();
        String [] line = scanner.nextLine().split("\\s+");

        for (int i = 0; i < numberOfElements; i++) {
            int num = Integer.parseInt(line[i]);
            numbers.add(num);
        }

        int numberOfQueries = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < numberOfQueries; i++) {
            String queryType = scanner.nextLine();
            if(queryType.equals("Insert")) {
                String [] lineArgs = scanner.nextLine().split("\\s+");
                int indexToInsert = Integer.parseInt(lineArgs[0]);
                int valueToInsert = Integer.parseInt(lineArgs[1]);
                numbers.add(indexToInsert, valueToInsert);
            }
            else if(queryType.equals("Delete")) {
                int indexToDelete = Integer.parseInt(scanner.nextLine());
                numbers.remove(indexToDelete);
            }
        }

        for (Integer number : numbers) {
            System.out.printf("%d ", number);
        }
    }
}