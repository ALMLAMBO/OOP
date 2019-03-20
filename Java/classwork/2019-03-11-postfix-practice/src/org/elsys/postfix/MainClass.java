package org.elsys.postfix;

import org.elsys.postfix.operations.*;

public class MainClass {
    public static void main(String[] args) {
        Calculator calculator = new Calculator(System.in, System.out);
        calculator.run();
    }
}