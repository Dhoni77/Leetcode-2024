//
// Created by Aldrin on 05-02-2024.
//

#ifndef DOOCS_FIRSTUNIQUECHARACTERINASTRING_H
#define DOOCS_FIRSTUNIQUECHARACTERINASTRING_H
#include "bits/stdc++.h"
using namespace std;

class FirstUniqueCharacterInAString {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        queue<pair<char, int>> q;
        int n = s.size();
        for(int i=0;i<n;i++) {
            mp[s[i]]++;
            if(mp[s[i]] > 1)
                continue;
            else
                q.push({s[i], i});
        }

        while (!q.empty()) {
            pair<char, int> p = q.front();
            q.pop();
            if(mp[p.first] == 1) {
                return p.second;
            }
        }

        return -1;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            arr[ch]++;
        }
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(arr[ch]==1)
            return i;
        }
        return -1;
    }
};
     */
};


#endif //DOOCS_FIRSTUNIQUECHARACTERINASTRING_H
