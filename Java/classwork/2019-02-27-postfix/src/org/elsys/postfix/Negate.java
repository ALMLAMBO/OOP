package org.elsys.postfix;

public class Negate extends UnaryOperation {

    public Negate(Calculator calculator) {
        super(calculator, "neg");
    }

    @Override
    protected double calculate(double arg) {
        return -arg;
    }
}
