package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public class Multiplication extends BinaryOperation {

    public Multiplication(Calculator calculator) {
        super(calculator, "*");
    }

    @Override
    protected double doCalculate(double v1, double v2) {
        return v1 * v2;
    }
}