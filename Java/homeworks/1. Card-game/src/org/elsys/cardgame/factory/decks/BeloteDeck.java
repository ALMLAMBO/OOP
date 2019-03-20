package org.elsys.cardgame.factory.decks;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.factory.AbstractDeck;

import java.util.List;

public class BeloteDeck extends AbstractDeck {

    public BeloteDeck(List<Card> cards, int handSize) {
        super(cards, handSize);
    }
}