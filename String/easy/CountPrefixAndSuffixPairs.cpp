//
// Created by Aldrin on 19-02-2024.
//

#include "CountPrefixAndSuffixPairs.h"

int main() {
    CountPrefixAndSuffixPairs cp;
    vector<string> words {"a","aba","ababa","aa"};
    cout << cp.countPrefixSuffixPairs(words);
}