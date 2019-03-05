package org.elsys.postfix;

public abstract class AbstractOperation
        implements Operation {

    private String name;
    private Calculator calculator;

    public AbstractOperation(Calculator calculator, String name) {
        this.calculator = calculator;
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }

    protected Calculator getCalculator() {
        return calculator;
    }
}