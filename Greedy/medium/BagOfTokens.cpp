//
// Created by Aldrin on 04-03-2024.
//

#include "BagOfTokens.h"

int main() {
    BagOfTokens bagOfTokens;
    int power = 200;
    vector<int> tokens{100,200,300,400};

    cout << bagOfTokens.bagOfTokensScore(tokens, power);
}