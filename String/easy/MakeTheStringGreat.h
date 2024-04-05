//
// Created by Aldrin on 05-04-2024.
//

#ifndef DOOCS_MAKETHESTRINGGREAT_H
#define DOOCS_MAKETHESTRINGGREAT_H
#include "bits/stdc++.h"
using namespace std;

class MakeTheStringGreat {
public:
    string makeGood(string s) {
        stack<char> st;
        string result = "";
        for(char c: s) {
            char expected;
            if(c >= 97 and c <= 122) {
                expected = c - 32;
            }
            else {
                expected = c + 32;
            }

            if(!st.empty() and st.top() == expected) {
                st.pop();
                continue;
            }
            else {
                st.push(c);
            }
        }

        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        uint8_t d = 'a' - 'A';
        for(char ch : s) {
            if(st.size() && (abs(st.top() - ch) == d)) {
                st.pop();
                continue;
            }
            st.push({ch});
        }
        string ans;
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
 public:
  string makeGood(string s) {
    string ans;
    for (const char c : s)
      if (!ans.empty() && isBadPair(ans.back(), c))
        ans.pop_back();
      else
        ans.push_back(c);
    return ans;
  }

  bool isBadPair(char a, char b) {
    return a != b && tolower(a) == tolower(b);
  }
};
     */
};


#endif //DOOCS_MAKETHESTRINGGREAT_H
