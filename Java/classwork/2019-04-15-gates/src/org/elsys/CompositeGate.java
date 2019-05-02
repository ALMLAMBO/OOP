package org.elsys;

import java.util.ArrayList;
import java.util.List;

public class CompositeGate extends org.elsys.AbstractGate {

    private List<Gate> gates = new ArrayList<Gate>();

    public void addGate(Gate gate) {
        if(!gates.contains(gate)) {
            gates.add(gate);
        }
    }

    @Override
    public void act() {
        for(Gate gate: gates) {
            gate.act();
        }
    }
}