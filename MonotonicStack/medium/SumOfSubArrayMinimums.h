//
// Created by Aldrin on 20-01-2024.
//

#ifndef DOOCS_SUMOFSUBARRAYMINIMUMS_H
#define DOOCS_SUMOFSUBARRAYMINIMUMS_H
#include "bits/stdc++.h"
using namespace std;

class SumOfSubArrayMinimums {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (i - left[i]) * (right[i] - i) * arr[i] % mod;
            ans %= mod;
        }
        return ans;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Using Monotonic Stack
    /*
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        long long sum = 0;
        vector<int> dp(n, -1);
        int mod = 1e9+7;
        for(int i=0;i<n;i++) {
            // Monotic Increasing stack
            while(!st.empty() and arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if(!st.empty()) {
                int j = st.top();
                dp[i] = (dp[j] + arr[i] * (i - j)) % mod;
            }
            else dp[i] = (arr[i] * (i + 1)) % mod;
            st.push(i);
        }
        for(int x:dp)
            sum += x;

        return (int)(sum % mod);
    }
     */
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
    // TC: O(N ^ 2)
    // Inefficient approach
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), sum = 0, mod = 1e9+7;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++) {
            dp[i][i] = arr[i];
            sum += arr[i];
        }

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                dp[i][j] = min(arr[j], dp[i][j-1]);
                sum += dp[i][j];
            }
        }
        return sum % mod;
    }
     */
};


#endif //DOOCS_SUMOFSUBARRAYMINIMUMS_H
