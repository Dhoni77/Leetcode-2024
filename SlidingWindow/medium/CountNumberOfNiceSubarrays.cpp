//
// Created by Aldrin on 16-01-2024.
//

#include "CountNumberOfNiceSubarrays.h"

int main() {
    CountNumberOfNiceSubarrays cn;

    vector<int> n{2, 4, 6};
    int k = 1;

    cout << cn.numberOfSubarrays(n, k);
}