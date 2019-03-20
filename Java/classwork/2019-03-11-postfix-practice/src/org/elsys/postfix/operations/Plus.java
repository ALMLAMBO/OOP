package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Plus extends BinaryOperation {
    public Plus(Calculator calculator) {
        super(calculator, "+");
    }

    @Override
    protected double doCalculate(double v1, double v2) {
        return v1 + v2;
    }
}
