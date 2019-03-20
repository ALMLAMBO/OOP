package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class CalculateThreeNumbers extends TernaryOperation {

    public CalculateThreeNumbers(Calculator calculator) {
        super(calculator, "ter");
    }

    @Override
    protected double doCalculate(double v1, double v2, double v3)  {
        return -(v1 * v2 * v3);
    }
}