package org.elsys.cardgame.factory.decks;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.factory.AbstractDeck;

import java.util.List;

public class WarDeck extends AbstractDeck {

    public WarDeck(List<Card> cards, int handSize) {
        super(cards, handSize);
    }
}