//
// Created by Aldrin on 31-01-2024.
//

#ifndef DOOCS_VALIDPARANTHESES_H
#define DOOCS_VALIDPARANTHESES_H
#include "bits/stdc++.h"
using namespace std;

class ValidParantheses {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch: s) {
            if(ch == '(') {
                st.push(')');
            }
            else if(ch == '[') {
                st.push(']');
            }
            else if(ch == '{') {
                st.push('}');
            }
            else if(!st.empty()) {
                char open = st.top();
                st.pop();
                if(open != ch) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return st.empty();
    }
};


#endif //DOOCS_VALIDPARANTHESES_H
