package org.elsys;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class TestFullAdder {

    private Wire a;
    private Wire b;
    private Wire cIn;
    private Wire sum;
    private Wire cOut;

    private Gate fullAdder;

    @Before
    public void beforeEach() {
        a = new Wire();
        b = new Wire();
        cIn = new Wire();

        sum = new Wire();
        cOut = new Wire();

        fullAdder = GateFactory.makeFullAdder(a, b, cIn, sum, cOut);
        assertNotNull(fullAdder);
    }

    @Test
    public void testBase() {
        assertFalse(sum.getSignal());
        assertFalse(cOut.getSignal());
    }

    @Test
    public void testTrueCin() {
        cIn.setSignal(true);

        assertTrue(sum.getSignal());
        assertFalse(cOut.getSignal());
    }

    @Test
    public void testTrueB() {
        b.setSignal(true);

        assertTrue(sum.getSignal());
        assertFalse(cOut.getSignal());
    }
    @Test
    public void testTrueA() {
        a.setSignal(true);

        assertTrue(sum.getSignal());
        assertFalse(cOut.getSignal());
    }

    @Test
    public void testTrueCinTrueB() {
        cIn.setSignal(true);
        b.setSignal(true);

        assertFalse(sum.getSignal());
        assertTrue(cOut.getSignal());
    }

    @Test
    public void testTrueCinTrueA() {
        cIn.setSignal(true);
        a.setSignal(true);

        assertFalse(sum.getSignal());
        assertTrue(cOut.getSignal());
    }

    @Test
    public void testTrueATrueB() {
        a.setSignal(true);
        b.setSignal(true);

        assertFalse(sum.getSignal());
        assertTrue(cOut.getSignal());
    }

    @Test
    public void testTrueATrueBTrueCin() {
        a.setSignal(true);
        b.setSignal(true);
        cIn.setSignal(true);

        assertTrue(sum.getSignal());
        assertTrue(cOut.getSignal());
    }
}