//
// Created by Aldrin on 29-01-2024.
//

#ifndef DOOCS_PALINDROMEPARTITIONING_H
#define DOOCS_PALINDROMEPARTITIONING_H
#include "bits/stdc++.h"
using namespace std;

class PalindromePartitioning {
public:
    /*
     *     vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int n = s.size();
        if(n == 1)
            return true;
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void solve(string s, vector<string>& temp) {
        int n = s.size();
        if(s.size() == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i < n;i++) {
            string aux = s.substr(0, i + 1);
            if(isPalindrome(aux)) {
                temp.push_back(aux);
                solve(s.substr(i + 1), temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, temp);
        return ans;
    }
     */
    //--------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> subs;
        vector<vector<string>> result;
        dfs(0,s,subs,result);
        return result;
    }

    void dfs(int ind,string& s,vector<string>& subs,vector<vector<string>>& result)
    {
        if(ind==s.size())
        {
            result.push_back(subs);
            return;
        }

        for(int i=ind;i<s.size();i++)
        {
            if(isPalindrome(s,ind,i))
            {
                subs.push_back(s.substr(ind,i-ind+1));
                dfs(i+1,s,subs,result);
                subs.pop_back();
            }
        }
    }

    bool isPalindrome(string& s,int ind,int i)
    {
        int f=0;
        while(ind<i+1)
        {
            if(s[ind]!=s[i])
            {
                f=1;
                break;
            }
            ind++;
            i--;
        }
        if(f==1)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
};
     */
    //----------------------------------------------------------------------------------------------------------------------------
        bool isPalindrome(string &s,int start,int end){
            while(start<=end){
                if(s[start++]!=s[end--]){
                    return false;
                }
            }
            return true;
        }
        void helper(vector<vector<string>>&ans,vector<string>&temp,string &s,int ind){
            if(ind==s.size()){
                ans.push_back(temp);
                return;
            }
            for(int i=ind;i<s.size();++i){
                if(isPalindrome(s,ind,i)){
                    temp.push_back(s.substr(ind,i-ind+1));
                    helper(ans,temp,s,i+1);
                    temp.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> temp;
            helper(ans,temp,s,0);
            return ans;
        }
};


#endif //DOOCS_PALINDROMEPARTITIONING_H
