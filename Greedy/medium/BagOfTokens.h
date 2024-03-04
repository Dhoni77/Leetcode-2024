//
// Created by Aldrin on 04-03-2024.
//

#ifndef DOOCS_BAGOFTOKENS_H
#define DOOCS_BAGOFTOKENS_H
#include "bits/stdc++.h"
using namespace std;

class BagOfTokens {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1, score = 0, maxi = 0;

        while(i <= j) {
            if(tokens[i] <= power) {
                power -= tokens[i++];
                score++;
            }
            else {
                power += tokens[j--];
                maxi = max(maxi, score--);
            }
            if(score < 0)
                return 0;
        }

        return maxi;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int low = 0;
        int high = tokens.size() - 1;
        int score = 0;
        sort(tokens.begin(), tokens.end());

        while (low <= high) {
            // When we have enough power, play lowest token face-up
            if (power >= tokens[low]) {
                score += 1;
                power -= tokens[low];
                low += 1;
            // We don't have enough power to play a token face-up
            // If there is at least one token remaining,
            // and we have enough score, play highest token face-down
            } else if (low < high && score > 0) {
                score -= 1;
                power += tokens[high];
                high -= 1;
            // We don't have enough score, power, or tokens
            // to play face-up or down and increase our score
            } else {
                return score;
            }
        }
        return score;
    }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        deque<int> deque(tokens.begin(), tokens.end());

        while (!deque.empty()) {
            // When we have enough power, play token face-up
            if (power >= deque.front()) {
                power -= deque.front();
                deque.pop_front();
                score += 1;
            // We don't have enough power to play a token face-up
            // When there is at least one token remaining,
            // and we have enough score, play token face-down
            } else if (deque.size() > 1 && score > 0) {
                power += deque.back();
                deque.pop_back();
                score -= 1;
            // We don't have enough score, power, or tokens
            // to play face-up or down and increase our score
            } else {
                return score;
            }
        }
        return score;
    }
};
     */
};


#endif //DOOCS_BAGOFTOKENS_H
