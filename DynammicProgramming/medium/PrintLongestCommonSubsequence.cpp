//
// Created by Aldrin on 12-03-2024.
//

#include "PrintLongestCommonSubsequence.h"

int main() {
    PrintLongestCommonSubsequence printLongestCommonSubsequence;

    string word1 = "abcd", word2 = "abcde";

    cout << printLongestCommonSubsequence.findLCS(word1.size(), word2.size(), word1, word2);
}