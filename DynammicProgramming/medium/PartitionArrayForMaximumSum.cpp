//
// Created by Aldrin on 03-02-2024.
//

#include "PartitionArrayForMaximumSum.h"

int main() {
    PartitionArrayForMaximumSum pam;

    vector<int> arr{1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << pam.maxSumAfterPartitioning(arr, k);
}