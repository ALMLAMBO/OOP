package org.elsys;

public class Main {
    public static void main(String[] args) {
        System.out.printf("Hello Java world from Mr ");
        for (int i = 0; i < args.length; i++) {
            System.out.printf("%s ", args[i]);
        }
        System.out.println();
    }
}