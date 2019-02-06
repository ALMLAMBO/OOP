package org.elsys;

import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        //compiling files to object code ->
        //sth between Java code and assembly
        //javac filename.java
        //executing files
        //java filename.class
        System.out.printf("Hello, Java world!, Mr. %s\n"
                , args[0]);
        int []integers = new int[4];
        int a = 5;
        integers[0] = a;
        Scanner scanner = new Scanner(System.in);
        //everything is reference except int, double, float, char and so on
        //another way of def object
        //java.util.Scanner scanner = new java.util.Scanner(System.in);
        /* Organisation of the memory
        * call stack -> all methods and their parameters
        * and local variables
        * Garbage collector -> checks if there are any left references
        * and delete the remaining references
        * heap -> all dynamic variables
        * the newest objects are on the top of the heap and
        * during the execution it goes down in the heap
        * garbage collector checks the top part of the heap most commonly
        * and the bottom only if there is out of memory
        * */
        for (int i = 1; i < 4; i++) {
            integers[i] = Integer
                    .parseInt(scanner.nextLine());

            //System.out.println(integers[i]);
        }
        System.out.println(pow(a));
        System.out.println();
        System.out.println(toString(integers));
        System.out.println(toString(power(integers)));
    }

    private static int[] power(int[] array) {
        int[] result = new int[array.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = array[i] * array[i];
        }
        return result;
    }

    public static int pow(int value) {
        return value * value;
    }

    private static String toString(int[] array) {
        String result = "";
        for (int i : array) {
            result += i + " ";
        }
        return result;
    }
}