//
// Created by Aldrin on 12-03-2024.
//

#include "DistinctSubsequences.h"

int main() {
    DistinctSubsequences distinctSubsequences;

    string s = "babgbag", t = "bag";

    cout << distinctSubsequences.numDistinct(s, t);
}