package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class TernaryOperation extends AbstractOperation {

    public TernaryOperation(Calculator calculator, String token) {
        super(calculator, token);
    }

    @Override
    public void calculate() {
        double v1 = getCalculator().popValue();
        double v2 = getCalculator().popValue();
        double v3 = getCalculator().popValue();
        double result = doCalculate(v1, v2, v3);
        getCalculator().addValue(result);
    }

    protected abstract double doCalculate(double v1, double v2, double v3);
}
