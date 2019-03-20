package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public class Division extends BinaryOperation {

    public Division(Calculator calculator) {
        super(calculator, "/");
    }

    @Override
    protected double doCalculate(double v1, double v2) {
        try {
            if(v1 == 0) {
                throw new EmptyStackException();
            }
        }
        catch (EmptyStackException e) {

        }
        return v2 / v1;
    }
}
