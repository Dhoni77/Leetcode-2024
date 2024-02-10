//
// Created by Aldrin on 10-02-2024.
//

#ifndef DOOCS_VALIDPARANTHESISSTRING_H
#define DOOCS_VALIDPARANTHESISSTRING_H
#include "bits/stdc++.h"
using namespace std;

class ValidParanthesisString {
public:
    //TC: O(N^2)
    //SC: O(N*N)
    vector<vector<int>> dp;
    bool isValid(string s, int index, int open, int n) {
        if(index == n) {
            return open == 0;
        }

        if(dp[index][open] != -1) {
            return dp[index][open];
        }

        bool ans = false;

        if(s[index] == '*') {
            ans |= isValid(s, index + 1, open+1, n);
            if(open)
                ans |= isValid(s, index + 1, open-1, n);
            ans |= isValid(s, index + 1, open, n);
        }
        else if(s[index] == '(') {
            ans = isValid(s, index + 1, open + 1, n);
        }
        else if(open) {
            ans = isValid(s, index + 1, open - 1, n);
        }

        return dp[index][open] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return isValid(s, 0, 0, n);
    }
    //-----------------------------------------------------------------------------------------------------------
    /*
     * Tabulation
     *     bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[n][0] = 1;

        for(int ind = n - 1;ind >= 0;ind--) {
            for(int openingBracket = 0;openingBracket < n;openingBracket++) {
                bool ans = false;
                if(s[ind] == '*') {
                    // when '('
                    ans |= dp[ind + 1][openingBracket + 1];
                    // when ')'
                    if(openingBracket)
                        ans |= dp[ind + 1][openingBracket - 1];
                    // when '*'
                    ans |= dp[ind + 1][openingBracket];
                }
                else {
                    if(s[ind] == '(') {
                        ans |= dp[ind + 1][openingBracket + 1];
                    }
                    else {
                        if(openingBracket)
                            ans |= dp[ind + 1][openingBracket - 1];
                    }
                }
                dp[ind][openingBracket] = ans;
            }
        }

        return dp[0][0];
    }
     */
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Greedy Optimal
     *
     *https://leetcode.com/problems/valid-parenthesis-string/solutions/302732/c-o-s-time-o-1-space-one-pass-with-explanation/
     * minDiff means the diff we got if we always try to replace * with ). If minDiff become -1, it means that this replacement results in more ) than (, so it should be avoided. To avoid it, we simply reset minDiff from -1 to 0 which implies we only replace * with ( or empty string.

        Example: (**)

        Seeing (, the range becomes [1, 1].
        Seeing *, the range becomes [0, 2]. 0 correponds to (), 1 to (_, 2 to ((.
        Seeing *, the range becomes [-1,3]. But -1 is invalid because it means ()) and should be avoided. So we correct the range to [0, 3].
        Seeing ), the range becomes [-1, 2]. Again, we correct the range to [0, 2] (because -1 means ()_) or (_)))
        The final [0, 2] range means that we can either get a perfect string, or has 1 or 2 more ( available (which are created by *).
    class Solution {
    public boolean checkValidString(String s) {
            int lo = 0, hi = 0;
            for (char c: s.toCharArray()) {
                lo += c == '(' ? 1 : -1;
                hi += c != ')' ? 1 : -1;
                if (hi < 0) break;
                lo = Math.max(lo, 0);
            }
            return lo == 0;
        }
    }
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Greedy Approach
     *   public boolean checkValidString(String s) {
    int leftBalance = 0;
    for (int i=0; i<s.length(); i++) {
      if ((s.charAt(i) == '(') || (s.charAt(i) == '*'))
        leftBalance++;
      else
        leftBalance--;

      if (leftBalance<0) return false; // We know we have unbalanced parenthesis
    }

    // We can already check if parenthesis are valid
    if (leftBalance == 0) return true;

    int rightBalance = 0;
    for (int i=s.length()-1; i>=0; i--) {
      if ((s.charAt(i) == ')') || (s.charAt(i) == '*'))
        rightBalance++;
      else
        rightBalance--;

      if (rightBalance<0) return false;  // We know we have unbalanced parenthesis
    }

    // Here we know we have never been unbalanced parsing from left to right e.g. ')('
    // We've also already substituted '*' either by '(' or by ')'
    // So we only have 3 possible scenarios here:
    // 1. We had the same amount of '(' and ')'
    // 2. We had more '(' then ')' but enough '*' to substitute
    // 3. We had more ')' then '(' but enough '*' to substitute
    return true;
  }
     */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /* Two Stacks
     *     bool checkValidString(string s) {
        stack<char>st1;
        stack<char>st2;

        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                st2.push(i);

            }
            else if(s[i]==')'){
                if(!st1.empty())st1.pop();
                else if(!st2.empty())st2.pop();
                else return false;
            }
            else {
                st1.push(i);
            }
        }
        if(st1.empty())return true;
        while(!st1.empty()&&!st2.empty()){

            if(st1.top()>st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return st1.empty();
    }
     */
};


#endif //DOOCS_VALIDPARANTHESISSTRING_H
