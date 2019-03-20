package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Rank;
import org.elsys.cardgame.api.Suit;
import org.elsys.cardgame.factory.decks.BeloteDeck;
import org.elsys.cardgame.factory.decks.SantaseDeck;
import org.elsys.cardgame.factory.decks.WarDeck;
import org.elsys.cardgame.factory.implementations.CardImpementation;

import java.util.ArrayList;
import java.util.List;

public class DeckFactory {

	public static Deck defaultWarDeck() {
		List<Card> deck = generateCards(Rank.TWO);
		return new WarDeck(deck, 26);
	}

	public static Deck defaultSantaseDeck() {
		List<Card> deck = generateCards(Rank.NINE);
		return new SantaseDeck(deck, 6);
	}

	public static Deck defaultBeloteDeck() {
		List<Card> deck = generateCards(Rank.SEVEN);
		return new BeloteDeck(deck, 8);
	}

	private static List<Card> generateCards(Rank startRank) {
		List<Card> result = new ArrayList<>();
		Suit [] suits = Suit.values();
		Rank [] ranks = Rank.values();

		for (Suit suit : suits) {
			for (Rank rank : ranks) {
				if (rank.compareTo(startRank) >= 0) {
					result.add(new CardImpementation(rank, suit));
				}
			}
		}
		return result;
	}
}