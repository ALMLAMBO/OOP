package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Minus extends BinaryOperation {

    public Minus(Calculator calculator) {
        super(calculator, "-");
    }

    @Override
    protected double doCalculate(double v1, double v2) {
        return v2 - v1;
    }
}
