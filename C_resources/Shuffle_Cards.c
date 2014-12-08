/*
 * Shuffle Cards
 *
 * Write a method to shuffle a deck of cards.
 * It must be a perfect shuffle - in other words, each 52! permutations of
 * the deck has to be equally likely.
 * Assume that you are given a random number generator which is perfect.
 */

public static void shuffleArray(int[] cards) {
    int i, idx;
    int n = cards.size();

    for (i = 0; i < n; i++) {
        idx = rand() % (n-i) + i;
        swap(cards[i], cards[idx]);
    }
}

