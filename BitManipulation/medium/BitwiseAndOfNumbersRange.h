//
// Created by Aldrin on 21-02-2024.
//

#ifndef DOOCS_BITWISEANDOFNUMBERSRANGE_H
#define DOOCS_BITWISEANDOFNUMBERSRANGE_H
#include "bits/stdc++.h"
using namespace std;

class BitwiseAndOfNumbersRange {
public:
        // TC: O(32)
        // SC: O(1)
        int rangeBitwiseAnd(int m, int n) {
            int shiftBits = 0;

            while (m != n) {
                m >>= 1;
                n >>= 1;
                ++shiftBits;
            }

            return m << shiftBits;
        }
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
    public:
        int rangeBitwiseAnd(int left, int right) {
            while (left < right) {
                right &= (right - 1);
            }
            return right;
        }
};
     */
    //--------------------------------------------------------------------------------------------------------------------------
    /*
     *https://leetcode.wang/leetcode-201-Bitwise-AND-of-Numbers-Range.html#
     * https://leetcode.com/problems/bitwise-and-of-numbers-range/solutions/56827/fast-three-line-c-solution-and-explanation-with-no-loops-or-recursion-and-one-extra-variable/?envType=daily-question&envId=2024-02-21
     * class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int x = m ^ n;
        x |= x >> 1, x |= x >> 2, x |= x >> 4, x |= x >> 8, x |= x >> 16;
        return m & ~x;
    }
};
     */
};


#endif //DOOCS_BITWISEANDOFNUMBERSRANGE_H
