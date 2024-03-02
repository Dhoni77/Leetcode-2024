//
// Created by Aldrin on 01-03-2024.
//

#include "WordLadder.h"

int main() {
    WordLadder wl;
    string begin = "hit", end = "cog";
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};

    cout << wl.ladderLength(begin, end, wordList);
}