//
// Created by Aldrin on 23-01-2024.
//

#ifndef DOOCS_MAXIMUMLENGTHOFACONCATENATEDSTRINGWITHUNIQUECHARACTERS_H
#define DOOCS_MAXIMUMLENGTHOFACONCATENATEDSTRINGWITHUNIQUECHARACTERS_H
#include "bits/stdc++.h"
using namespace std;

class MaximumLengthOfAConcatenatedStringWithUniqueCharacters {
public:
    /**
     * Recursion
     *int solve(int idx, int charBit, int n, vector<string> arr) {
        if(idx == n) {
            // count the set bits
            int count = 0;
            for(int i=0;i<26;i++) {
                if(((1 << i) & charBit) != 0) {
                    count++;
                }
            }
            return count;
        }

        int newCharBit = charBit;
        bool isEligible_to_pick = true;

        for(char ch: arr[idx]) {
            int bit = 1 << ch - 'a';
            if((newCharBit & bit) == 0) {
                newCharBit |= bit;
            }
            else {
                isEligible_to_pick = false;
                break;
            }
        }

        int pick = 0;
        if(isEligible_to_pick) {
            pick = solve(idx + 1, newCharBit, n, arr);
        }
        int notpick = solve(idx + 1, charBit, n, arr);

        return max(pick, notpick);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        return solve(0, 0, arr.size(), arr);
    }
     * **/
    //----------------------------------------------------------------------------------------------------------
    /**
     *
     *int solve(int idx, bitset<26> &charBit, int n, vector<string> &arr) {
        if (idx == n) {
            // count the set bits
            return charBit.count();
        }

        bitset<26> newCharBit = charBit;
        bool isEligible_to_pick = true;
        for (char ch: arr[idx]) {
            int bit = ch - 'a';
            if (!newCharBit[bit]) {
                newCharBit[bit] = true;
            } else {
                isEligible_to_pick = false;
                break;
            }
        }
        int pick = 0;
        if (isEligible_to_pick) {
            pick = solve(idx + 1, newCharBit, n, arr);
        }
        int notpick = solve(idx + 1, charBit, n, arr);
        return max(pick, notpick);
    }

    int maxLength(vector<string> &arr) {
        int n = arr.size();
        bitset<26> b;

        return solve(0, b, n, arr);
    }
     */
    //-------------------------------------------------------------------------------------------------------------------------------------
    // Backtracking
    /*
     * class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Use depth first search recursion through arr
        // with backracking and a map for results
        unordered_map<char, int> resMap;
        return backtracking(arr, 0, resMap);
    }

private:
    int backtracking(vector<string>& arr, int pos, unordered_map<char, int>& resMap) {
        // Check for duplicate characters
        for (auto& kv : resMap)
            if (kv.second > 1)
                return 0;

        // Recurse through each possible next option
        // and find the best answer
        int best = resMap.size();
        for (int i = pos; i < arr.size(); i++) {
            // Add the current word to the result map
            // and recurse to the next position
            string& word = arr[i];
            for (char& c : word) {
                if (resMap.find(c) != resMap.end()) {
                    resMap[c]++;
                } else {
                    resMap[c] = 1;
                }
            }
            best = max(best, backtracking(arr, i + 1, resMap));

            // Backtrack the result map before continuing
            for (char& c : word) {
                if (resMap[c] == 1) {
                    resMap.erase(c);
                } else {
                    resMap[c]--;
                }
            }
        }
        return best;
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------
    /*
     * Backtracking optimized
     *
     *
     */
    int maxLength(vector<string>& arr) {
        // Pre-process arr with an optimizing helper
        // which converts each word to its character bitset
        // and then uses a set to prevent duplicate results
        unordered_set<int> optSet;
        for (auto& word : arr)
            wordToBitSet(optSet, word);

        // Convert the set back to an array for iteration
        // then start up the recursive helper
        vector<int> optArr(optSet.begin(), optSet.end());
        return backtracking(optArr, 0, 0, 0);
    }

    void wordToBitSet(unordered_set<int>& optSet, string& word) {
        // Initialize an empty int to use as a character bitset
        int charBitSet = 0;
        for (char& c : word) {
            // If the bitset contains a duplicate character
            // then discard this word with an early return
            // otherwise add the character to the bitset
            int mask = 1 << (c - 'a');
            if (charBitSet & mask)
                return;
            charBitSet += mask;
        }

        // Store the length of the word in the unused space
        // then add the completed bitset to our optimized set
        optSet.insert(charBitSet + (word.length() << 26));
    }

    int backtracking(vector<int>& optArr, int pos, int resChars, int resLen) {
        // Recurse through each possible next option
        // and find the best answer
        int best = resLen;
        for (int i = pos; i < optArr.size(); i++) {
            int newChars = optArr[i] & ((1 << 26) - 1);
            int newLen = optArr[i] >> 26;

            // If the two bitsets overlap, skip to the next result
            if (newChars & resChars)
                continue;

            // Add the current word to the result
            // and recurse to the next position
            resChars += newChars;
            resLen += newLen;
            best = max(best, backtracking(optArr, i + 1, resChars, resLen));

            // Backtrack the result before continuing
            resChars -= newChars;
            resLen -= newLen;
        }
        return best;
    }
    //--------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Pre-process arr with an optimizing helper
        // which converts each word to its character bitset
        // and then uses a set to prevent duplicate results
        unordered_set<int> optSet;
        for (auto& word : arr)
            wordToBitSet(optSet, word);

        // Convert the set back to an array for iteration
        // then start up the recursive helper
        vector<int> optArr(optSet.begin(), optSet.end());
        return dfs(optArr, 0, 0);
    }

private:
    void wordToBitSet(unordered_set<int>& optSet, string& word) {
        // Initialize an empty int to use as a character bitset
        int charBitSet = 0;
        for (char& c : word) {
            // If the bitset contains a duplicate character
            // then discard this word with an early return
            // otherwise add the character to the bitset
            int mask = 1 << c - 'a';
            if (charBitSet & mask)
                return;
            charBitSet += mask;
        }

        // Store the length of the word in the unused space
        // then add the completed bitset to our optimized set
        optSet.insert(charBitSet + (word.length() << 26));
    }

    int dfs(vector<int>& optArr, int pos, int res) {
        // Separate the parts of the bitset res
        int oldChars = res & ((1 << 26) - 1);
        int oldLen = res >> 26;
        int best = oldLen;

        // Iterate through the remaining results
        for (int i = pos; i < optArr.size(); i++) {
            int newChars = optArr[i] & ((1 << 26) - 1);
            int newLen = optArr[i] >> 26;

            // If the two bitsets overlap, skip to the next result
            if (newChars & oldChars)
                continue;

            // Combine the two results and trigger the next recursion
            int newRes = newChars + oldChars + (newLen + oldLen << 26);
            best = max(best, dfs(optArr, i + 1, newRes));
        }
        return best;
    }
};
     */
};
#endif //DOOCS_MAXIMUMLENGTHOFACONCATENATEDSTRINGWITHUNIQUECHARACTERS_H
