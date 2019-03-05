package org.elsys.postfix;

public class Main {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        calculator.addOperation(new Negate(calculator));
        calculator.addOperation(new Absolute(calculator));
        calculator.run(System.in, System.out);
    }
}