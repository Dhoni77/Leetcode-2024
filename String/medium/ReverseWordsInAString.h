//
// Created by Aldrin on 09-01-2024.
//

#ifndef DOOCS_REVERSEWORDSINASTRING_H
#define DOOCS_REVERSEWORDSINASTRING_H
#include "bits/stdc++.h"
using namespace std;

class ReverseWordsInAString {
public:
    string reverseWords(string s)
    {
        string temp = "";
        stack<string> st;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch ==' '){
                if(temp!=""){
                    st.push(temp);
                }
                temp = "";
            }
            else{
                temp+=ch;
            }
        }

        if(temp!=""){
            st.push(temp);
        }

        string ans="";
        while(!st.empty()){
            ans+= (st.top() + " ");
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------
    /**
     *     string reverseWords(string s) {
        string ans = "";
        stack<string> st;
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i] == ' ')
                continue;
            else if(isalnum(s[i])) {
                ans = s[i] + ans;
                if((i-1 >= 0 and s[i-1] == ' ') or i == 0) {
                    st.push(ans);
                    ans = "";
                }
            }
        }
        ans = "";
        while(!st.empty()) {
            ans = st.top() + ' ' + ans;
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
     * **/
};


#endif //DOOCS_REVERSEWORDSINASTRING_H
