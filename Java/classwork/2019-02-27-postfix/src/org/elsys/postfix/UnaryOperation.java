package org.elsys.postfix;

public abstract class UnaryOperation
        extends AbstractOperation {


    public UnaryOperation(Calculator calculator, String name) {
        super(calculator, name);
    }

    @Override
    public void execute() {
        double value = getCalculator().pop();
        double result = calculate(value);
        getCalculator().push(result);
    }

    protected abstract double calculate(double arg);
}
