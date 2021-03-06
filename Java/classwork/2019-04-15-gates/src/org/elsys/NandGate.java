package org.elsys;


public class NandGate extends BinaryGate {

    public NandGate(Wire in1, Wire in2, Wire out) {
        super(in1, in2, out);
    }

    @Override
    public void act() {
        getOut().setSignal(!(getIn1()
                .getSignal() && getIn2().getSignal()));
    }
}