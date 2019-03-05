package org.elsys.postfix;

public class Absolute extends UnaryOperation {

    public Absolute(Calculator calculator) {
        super(calculator, "abs");
    }

    @Override
    protected double calculate(double arg) {
        return arg < 0 ? -arg : arg;
    }
}