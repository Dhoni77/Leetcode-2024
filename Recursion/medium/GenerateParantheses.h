//
// Created by Aldrin on 19-01-2024.
//

#ifndef DOOCS_GENERATEPARANTHESES_H
#define DOOCS_GENERATEPARANTHESES_H
#include "bits/stdc++.h"
using namespace std;

class GenerateParantheses {
public:
    vector<string> result;
    void solve(int l, int r, string s) {
        if(l == 0 and r == 0) {
            result.push_back(s);
            return;
        }

        if(l > 0)
            solve(l-1, r, s + "(");
        if(r > 0 and r > l)
            solve(l, r-1, s + ")");
    }

    vector<string> generateParentheses(int n) {
        solve(n, n, "");
        return result;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------
    /**
     * Backtracking
     * class Solution {
public:

    void solve(int open, int close, vector<string> &ans, string s)
    {
        // base case
        if(open==0 && close==0)
        {
            ans.push_back(s);
            return;
        }

        if(open>0)
        {
            s.push_back('(');
            solve(open-1, close, ans, s);
            s.pop_back();
        }

        if(close>open)
        {
            s.push_back(')');
            solve(open, close-1, ans, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        int open=n;
        int close=n;
        string s="";

        solve(open, close, ans, s);

        return ans;
    }
};
     * **/
};


#endif //DOOCS_GENERATEPARANTHESES_H
