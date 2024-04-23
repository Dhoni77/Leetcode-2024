//
// Created by Aldrin on 22-04-2024.
//

#ifndef DOOCS_OPENTHELOCK_H
#define DOOCS_OPENTHELOCK_H
#include "bits/stdc++.h"
using namespace std;

class OpenTheLock {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = 0;
        queue<string> q;
        unordered_set<string> st(deadends.begin(), deadends.end());
        if (st.count("0000")) return -1;
        if (target == "0000") return 0;
        q.emplace("0000");
        st.insert("0000");

        while(!q.empty()) {
            ++ans;
            for(int n = q.size();n>0;--n) {
                string temp = q.front();
                q.pop();

                for(string word: next(temp)) {
                    if(word == target)
                        return ans;
                    if(!st.count(word)) {
                        st.insert(word);
                        q.push(word);
                    }
                }
            }
        }

        return -1;
    }

    vector<string> next(string t) {
        vector<string> result;
        for(int i=0;i<4;i++) {
            char c = t[i];
            t[i] = c == '0' ? '9' : (char) (c - 1);
            result.push_back(t);
            t[i] = c == '9' ? '0' : (char) (c + 1);
            result.push_back(t);
            t[i] = c;
        }

        return result;
    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Map the next slot digit for each current slot digit.
        unordered_map<char, char> nextSlot = {
            {'0', '1'},
            {'1', '2'},
            {'2', '3'},
            {'3', '4'},
            {'4', '5'},
            {'5', '6'},
            {'6', '7'},
            {'7', '8'},
            {'8', '9'},
            {'9', '0'}
        };
        // Map the previous slot digit for each current slot digit.
        unordered_map<char, char> prevSlot = {
            {'0', '9'},
            {'1', '0'},
            {'2', '1'},
            {'3', '2'},
            {'4', '3'},
            {'5', '4'},
            {'6', '5'},
            {'7', '6'},
            {'8', '7'},
            {'9', '8'}
        };

        // Hash set to store visited and dead-end combinations.
        unordered_set<string> visitedCombinations(deadends.begin(), deadends.end());
        // Queue to store combinations generated after each turn.
        queue<string> pendingCombinations;

        // Count the number of wheel turns made.
        int turns = 0;

        // If the starting combination is also a dead-end,
        // then we can't move from the starting combination.
        if (visitedCombinations.find("0000") != visitedCombinations.end()) {
            return -1;
        }

        // Start with the initial combination '0000'.
        pendingCombinations.push("0000");
        visitedCombinations.insert("0000");

        while (!pendingCombinations.empty()) {
            // Explore all the combinations of the current level.
            for (int currLevelNodesCount = pendingCombinations.size();
                 currLevelNodesCount > 0; --currLevelNodesCount) {
                // Get the current combination from the front of the queue.
                string currentCombination = pendingCombinations.front();
                pendingCombinations.pop();

                // If the current combination matches the target,
                // return the number of turns/level.
                if (currentCombination == target) {
                    return turns;
                }

                // Explore all possible new combinations by turning each wheel in both directions.
                for (int wheel = 0; wheel < 4; wheel += 1) {
                    // Generate the new combination by turning the wheel to the next digit.
                    string newCombination = currentCombination;
                    newCombination[wheel] = nextSlot[newCombination[wheel]];
                    // If the new combination is not a dead-end and was never visited,
                    // add it to the queue and mark it as visited.
                    if (visitedCombinations.find(newCombination) == visitedCombinations.end()) {
                        pendingCombinations.push(newCombination);
                        visitedCombinations.insert(newCombination);
                    }

                    // Generate the new combination by turning the wheel to the previous digit.
                    newCombination = currentCombination;
                    newCombination[wheel] = prevSlot[newCombination[wheel]];
                    // If the new combination is not a dead-end and is never visited,
                    // add it to the queue and mark it as visited.
                    if (visitedCombinations.find(newCombination) == visitedCombinations.end()) {
                        pendingCombinations.push(newCombination);
                        visitedCombinations.insert(newCombination);
                    }
                }
            }
            // We will visit the next-level combinations.
            turns += 1;
        }
        // We never reached the target combination.
        return -1;
    }
};
     */
};


#endif //DOOCS_OPENTHELOCK_H
