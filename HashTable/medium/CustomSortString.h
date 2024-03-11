//
// Created by Aldrin on 11-03-2024.
//

#ifndef DOOCS_CUSTOMSORTSTRING_H
#define DOOCS_CUSTOMSORTSTRING_H
#include "bits/stdc++.h"
using namespace std;

class CustomSortString {
public:
    string customSortString(string order, string s) {
        vector<int> alpha(26, 0);
        string ans = "";
        // hash string s
        for(int i=0;i<s.size();i++) {
            alpha[s[i] - 'a']++;
        }
        // add chars from order to result
        for(int i=0;i<order.size();i++) {
            if(alpha[order[i] - 'a'] > 0) {
                ans += order[i];
                alpha[order[i] - 'a']--;
            }
        }
        for(int i=0;i<26;i++) {
            if(alpha[i] > 0) {
                ans += char(i + 'a');
            }
        }

        return ans;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    string customSortString(string order, string s) {
        string custom;
        vector<int> freq(26, 0);
        for (char c: s) {
            freq[c - 'a']++;
        }
        for (char c: order) {
            while (freq[c - 'a']) {
                custom += c;
                freq[c - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (freq[i]) {
                custom += i + 'a';
                freq[i]--;
            }
        }
        return custom;
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> charMap;
        unordered_set<char> found;

        for(auto &ch: s) charMap[ch]++;

        string ans = "";
        for(auto &ch: order) {
            if (charMap.find(ch) != charMap.end()) {
                ans += string(charMap[ch], ch);
                found.insert(ch);
            }
        }

        for(auto &entry: charMap) {
            if (found.find(entry.first) == found.end())
                ans += string(entry.second, entry.first);
        }
        return ans;
    }
};
    b -> c -> a -> f -> g
    aabbccddabcdabcdabcd
     */
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    static string str;
    static bool compare(char char1,char char2){
        return(str.find(char1) < str.find(char2));
    }
    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(),s.end(),compare);
        return s;
    }
};
 string Solution::str;
     */
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
     *  class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> pos(26,INT_MAX);
        for(int i=0; i<order.size(); i++){
             pos[order[i]-'a'] = i;
        }

        sort(s.begin(),s.end(),[&pos](char c1,char c2){
            return pos[c1-'a'] < pos[c2-'a'];
        });
        return s;
    }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    string customSortString(string order, string s) {
    // Define the custom comparator as lambda
        sort(s.begin(), s.end(), [order](char c1, char c2) {
            return order.find(c1) < order.find(c2);
        });
    return s;
    }
};
     */
};


#endif //DOOCS_CUSTOMSORTSTRING_H
