package org.elsys;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class TestNandNotGate {

    private Wire in;
    private Wire out;

    private Gate gate;

    @Before
    public void beforeEach() {
        in = new Wire();
        out = new Wire();

        gate = NandFactory.makeNotGate(in, out);
        assertNotNull(gate);
        in.setSignal(true);
        in.setSignal(false);
    }


    @Test
    public void testInFalse() {
        assertTrue(out.getSignal());
    }

    @Test
    public void testInTrue() {
        in.setSignal(true);
        assertFalse(out.getSignal());
    }
}