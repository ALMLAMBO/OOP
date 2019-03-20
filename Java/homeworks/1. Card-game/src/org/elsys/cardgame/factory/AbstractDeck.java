package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.*;
import org.elsys.cardgame.factory.implementations.HandImplementation;

import java.util.*;

public class AbstractDeck implements Deck {

    private List<Card> cards;
    private int handSize;

    public AbstractDeck(List<Card> cards, int handSize) {
        this.handSize = handSize;
        this.cards = cards;
    }

    public void setCards(List<Card> cards) {
        this.cards.addAll(cards);
    }

    @Override
    public List<Card> getCards() {
        return cards;
    }

    @Override
    public int size() {
        return cards.size();
    }

    @Override
    public int handSize() {
        return handSize;
    }

    @Override
    public Card drawTopCard() {
        return cards.remove(0);
    }

    @Override
    public Card topCard() {
        return cards.get(0);
    }

    @Override
    public Card drawBottomCard() {
        return cards.remove(cards.size()  - 1);
    }

    @Override
    public Card bottomCard() {
        return cards.get(cards.size() - 1);
    }

    @Override
    public Hand deal() {
        ArrayList<Card> dealDeck =
                new ArrayList<>(cards);

        //for (int i = 0; i < handSize; i++) {
        //    cards.remove(i);
        //}

        cards.subList(0, handSize).clear();

        return new HandImplementation(dealDeck, handSize);
    }

    @Override
    public void sort() {
        //https://github.com/tlehman/PlayingCards/blob/master/src/com/definidev/Card.java
        cards.sort(new Comparator<Card>() {
            @Override
            public int compare(Card o1, Card o2) {
                //int comparison = o1.getRank().toString()
                //        .compareTo(o2.getRank().toString());
                //if(comparison == 0) {
                //    comparison = o1.getSuit().toString()
                //            .compareTo(o2.getSuit().toString());
                //}
                //return comparison;
                Rank rankOfFirstCard = o1.getRank();
                Rank rankOfSecondCard = o2.getRank();

                return rankOfFirstCard.compareTo(rankOfSecondCard);
            }
        });

        cards.sort(new Comparator<Card>() {
            @Override
            public int compare(Card o1, Card o2) {
                Suit suitOfFirstCard = o1.getSuit();
                Suit suitOfSecondCard = o2.getSuit();

                return suitOfFirstCard.compareTo(suitOfSecondCard);
            }
        });
    }

    @Override
    public void shuffle() {
//        Random random = new Random();
//        List<Card> list = new ArrayList<>();
//        for (int i = 0; i < cards.size(); i++) {
//             list.add(cards.get(random.nextInt(cards.size())));
//        }
//        cards.clear();
//        cards.addAll(list);
        Collections.shuffle(cards);
    }
}