package org.elsys;

import java.util.Scanner;
import java.util.Stack;

public class JavaStack {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String commandLineArg = scanner.nextLine();
            System.out.println(
                    checkForBalancedParentheses(commandLineArg));
        }
    }

    private static boolean checkForBalancedParentheses(String arg) {
        Stack<Character> brackets = new Stack<>();
        for (int i = 0; i < arg.length(); i++) {
            if(arg.charAt(i) == '('
                    || arg.charAt(i) == '['
                    || arg.charAt(i) == '{') {
                brackets.push(arg.charAt(i));
            }
            else if(arg.charAt(i) == ')'
                    || arg.charAt(i) == ']'
                    || arg.charAt(i) == '}') {
                brackets.pop();
            }
        }
        return brackets.empty();
    }
}