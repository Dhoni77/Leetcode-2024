//
// Created by Aldrin on 23-01-2024.
//

#include "MaximumLengthOfAConcatenatedStringWithUniqueCharacters.h"

int main() {
    MaximumLengthOfAConcatenatedStringWithUniqueCharacters ml;
    vector<string> ss{ "cha","aple",};

    for(int i = 29;i >=0;i--) {
        cout << i << "\t";
    }
    cout << endl;

    cout << ml.maxLength(ss);
}