package org.elsys.cardgame.factory.implementations;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Hand;

import java.util.List;
import java.util.Objects;

public class HandImplementation implements Hand {

    private List<Card> cards;
    private int size;

    public HandImplementation(List<Card> cards, int size) {
        this.cards = cards;
        this.size = size;
    }

    @Override
    public List<Card> getCards() {
        return cards;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        HandImplementation that = (HandImplementation) o;
        return size == that.size &&
                Objects.equals(cards, that.cards);
    }

    @Override
    public int hashCode() {
        return Objects.hash(cards, size);
    }
}