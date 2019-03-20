package org.elsys;

import java.util.LinkedHashMap;
import java.util.Scanner;

public class JavaMap {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfQueries = Integer.parseInt(scanner.nextLine());
        LinkedHashMap<String, Integer> phoneBook = new LinkedHashMap<>();

        for (int i = 0; i < numberOfQueries; i++) {
            String personNames = scanner.nextLine();
            int phoneNumber = scanner.nextInt();
            phoneBook.put(personNames, phoneNumber);
        }

        while (scanner.hasNext()) {
            String namesToSearch = scanner.nextLine();
            if (phoneBook.containsKey(namesToSearch)) {
                System.out.printf("%s=%d\n", namesToSearch
                        , phoneBook.get(namesToSearch));
            }
            else {
                System.out.println("Not found");
            }
        }
    }
}