//
// Created by Aldrin on 24-04-2024.
//

#ifndef DOOCS_NTHTRIBONACCINUMBER_H
#define DOOCS_NTHTRIBONACCINUMBER_H
#include "bits/stdc++.h"
using namespace std;

class NthTribonacciNumber {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n <= 2)
            return 1;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int tribonacci(int n) {
        long long a = 0, b = 1, c = 1;
        while (n--) {
            long long d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return (int) a;
    }
};
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *     int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n <= 2) {
            return 1;
        }

        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
     */
};


#endif //DOOCS_NTHTRIBONACCINUMBER_H
