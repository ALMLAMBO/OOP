package org.elsys;

public class InverterGate extends org.elsys.AbstractGate {
    private Wire in;
    private Wire out;

    public InverterGate(Wire in, Wire out) {
        addInput(in);
        addOutput(out);

        this.in = in;
        this.out = out;
    }

    @Override
    public void act() {
        out.setSignal(!in.getSignal());
    }
}