//
// Created by Aldrin on 01-03-2024.
//

#ifndef DOOCS_WORDLADDER_H
#define DOOCS_WORDLADDER_H
#include "bits/stdc++.h"
using namespace std;

class WordLadder {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> st(wordList.begin(), wordList.end());
        q.emplace(beginWord, 1);

        while(!q.empty()) {
            string word = q.front().first;
            int sz = word.size(), distance = q.front().second;
            q.pop();

            if(word == endWord)
                return distance;

            for(int i=0;i<sz;i++) {
                char original = word[i];
                for(char k='a';k<='z';k++) {
                    word[i] = k;
                    if(st.count(word)) {
                        st.erase(word);
                        q.emplace(word, distance + 1);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};


#endif //DOOCS_WORDLADDER_H
