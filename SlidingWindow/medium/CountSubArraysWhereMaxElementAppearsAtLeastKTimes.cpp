//
// Created by Aldrin on 29-03-2024.
//

#include "CountSubArraysWhereMaxElementAppearsAtLeastKTimes.h"

int main() {
    CountSubArraysWhereMaxElementAppearsAtLeastKTimes countSubArraysWhereMaxElementAppearsAtLeastKTimes;
    vector<int> nums{1,3,2,3,3};
    int k = 2;
    cout << countSubArraysWhereMaxElementAppearsAtLeastKTimes.countSubarrays(nums, k);
}