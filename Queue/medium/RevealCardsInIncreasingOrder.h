//
// Created by Aldrin on 10-04-2024.
//

#ifndef DOOCS_REVEALCARDSININCREASINGORDER_H
#define DOOCS_REVEALCARDSININCREASINGORDER_H
#include "bits/stdc++.h"
using namespace std;

class RevealCardsInIncreasingOrder {
public:
        vector<int> deckRevealedIncreasing(vector<int>& deck) {
            int N = deck.size();
            queue<int> queue;

            // Create a queue of indexes
            for (int i = 0; i < N; i++) {
                queue.push(i);
            }

            sort(deck.begin(), deck.end());

            // Put cards at correct index in result
            vector<int> result(N);
            for (int i = 0; i < N; i++) {
                // Reveal Card
                result[queue.front()] = deck[i];
                queue.pop();

                // Move next card to bottom
                if (!queue.empty()) {
                    queue.push(queue.front());
                    queue.pop();
                }
            }
            return result;
        }
        //---------------------------------------------------------------------------------------------------------------------
        /*
         *
         * class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        vector<int> result(N);
        bool skip = false;
        int indexInDeck = 0;
        int indexInResult = 0;

        sort(deck.begin(), deck.end());

        while (indexInDeck < N) {
            // There is an available gap in result
            if (result[indexInResult] == 0) {

                // Add a card to result
                if (!skip) {
                    result[indexInResult] = deck[indexInDeck];
                    indexInDeck++;
                }

                // Toggle skip to alternate between adding and skipping cards
                skip = !skip;
            }
            // Progress to the next index of result array
            indexInResult = (indexInResult + 1) % N;
        }
        return result;
    }
};
         */
};


#endif //DOOCS_REVEALCARDSININCREASINGORDER_H
