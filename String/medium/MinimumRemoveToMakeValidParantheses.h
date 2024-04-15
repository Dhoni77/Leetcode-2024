//
// Created by Aldrin on 06-04-2024.
//

#ifndef DOOCS_MINIMUMREMOVETOMAKEVALIDPARANTHESES_H
#define DOOCS_MINIMUMREMOVETOMAKEVALIDPARANTHESES_H
#include "bits/stdc++.h"
using namespace std;

class MinimumRemoveToMakeValidParantheses {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        int open = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') {
                open++;
            }
            else if(s[i] == ')') {
                if(open == 0) {
                    s[i] = '*';
                }
                else open--;
            }
        }

        for(int i=s.size()-1;i>=0;i--) {
            if(open > 0 and s[i] == '(') {
                s[i] = '*';
                open--;
            }
        }

        for(char ch: s)
            if(ch != '*')
                result += ch;

        return result;
    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    stack<int> stack;  // unpaired '(' indices

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '(') {
        stack.push(i);  // Record the unpaired '(' index.
      } else if (s[i] == ')') {
        if (stack.empty())
          s[i] = '*';  // Mark the unpaired ')' as '*'.
        else
          stack.pop();  // Find a pair!
      }

    // Mark the unpaired '(' as '*'.
    while (!stack.empty())
      s[stack.top()] = '*', stack.pop();

    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
  }
};
     */
};


#endif //DOOCS_MINIMUMREMOVETOMAKEVALIDPARANTHESES_H
