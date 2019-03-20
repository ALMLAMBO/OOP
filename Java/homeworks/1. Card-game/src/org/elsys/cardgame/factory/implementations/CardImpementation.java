package org.elsys.cardgame.factory.implementations;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Rank;
import org.elsys.cardgame.api.Suit;

import java.util.Objects;

public class CardImpementation implements Card {

    private Rank rank;
    private Suit suit;

    public CardImpementation(Rank rank, Suit suit) {
        this.rank = rank;
        this.suit = suit;
    }

    @Override
    public Suit getSuit() {
        return suit;
    }

    @Override
    public Rank getRank() {
        return rank;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        CardImpementation that = (CardImpementation) o;
        return rank == that.rank &&
                suit == that.suit;
    }

    @Override
    public int hashCode() {
        return Objects.hash(rank, suit);
    }
}