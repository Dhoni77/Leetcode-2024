//
// Created by Aldrin on 07-02-2024.
//

#ifndef DOOCS_REMOVEKDIGITS_H
#define DOOCS_REMOVEKDIGITS_H
#include "bits/stdc++.h"
using namespace std;

class RemoveKDigits {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size())
            return "0";

        int n = num.size();
        stack<char> st;
        string ans = "";

        for(int i=0;i<n;i++) {
            while(!st.empty() and st.top() > num[i] and k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // if s = '112'
        while(!st.empty() and k > 0) {
            st.pop();
            k--;
        }

        if(st.empty())
            return "0";

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i=0;
        while(ans[i] == '0')
            i++;
        ans = ans.substr(i, n-i);

        if(ans == "")
            return "0";
        return ans;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;
        for (char& c : num) {
            while (k && stk.size() && stk.back() > c) {
                stk.pop_back();
                --k;
            }
            stk += c;
        }
        while (k--) {
            stk.pop_back();
        }
        int i = 0;
        for (; i < stk.size() && stk[i] == '0'; ++i) {
        }
        string ans = stk.substr(i);
        return ans == "" ? "0" : ans;
    }
};
     */
    //----------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.length() == k)
      return "0";

    string ans;
    vector<char> stack;

    for (int i = 0; i < num.length(); ++i) {
      while (k > 0 && !stack.empty() && stack.back() > num[i]) {
        stack.pop_back();
        --k;
      }
      stack.push_back(num[i]);
    }

    while (k-- > 0)
      stack.pop_back();

    for (const char c : stack) {
      if (c == '0' && ans.empty())
        continue;
      ans += c;
    }

    return ans.empty() ? "0" : ans;
  }
};
     */
};


#endif //DOOCS_REMOVEKDIGITS_H
