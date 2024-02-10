//
// Created by Aldrin on 08-02-2024.
//

#ifndef DOOCS_PERFECTSQUARES_H
#define DOOCS_PERFECTSQUARES_H
#include "bits/stdc++.h"
using namespace std;

class PerfectSquares {
public:

    /*
     *Recursion
     * int numSquares(int n) {
        if(n <= 0)
            return 0;
        int ans = n;
        for(int i=1;i<=n;i++) {
            for(int j=1;j*j <= i;j++) {
                int square = j*j;
                ans = min(ans, 1 + numSquares(n-square));
            }
        }
        return ans;
    }
     */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Bottom Up
     *
     */
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1;i<= n;i++) {
            dp[i] = i;

            for(int j=1;j*j<=i;j++) {
                int square = j*j;
                dp[i] = min(dp[i], 1 + dp[i-square]);
            }
            printf("dp[%d]=%d\n", i,dp[i]);
        }
        return dp[n];
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Bfs
     *     int numSquares(int n) {
        queue<int> q;
        vector<int> perfectSquares;
        set<int> visited;
        int step = 1;
        // Build perfect squares array
        for(int i=1;i*i<=n;i++) {
            int squares = i*i;
            if(squares == n)
                return step;
            q.push(squares);
            perfectSquares.push_back(squares);
            visited.insert(squares);
        }

        while(!q.empty()) {
            step++;
            int size = q.size();
            for(int i=0;i<size;i++) {
                int num = q.front();
                for(auto val: perfectSquares) {
                    int sum = num + val;
                    if(sum == n)
                        return step;
                    if(sum < n and !visited.count(sum)) {
                        q.push(sum);
                        visited.insert(sum);
                    }
                }
                q.pop();
            }
        }

        return -1;
    }
     */
};


#endif //DOOCS_PERFECTSQUARES_H
