//
// Created by Aldrin on 06-02-2024.
//

#ifndef DOOCS_GROUPANAGRAMS_H
#define DOOCS_GROUPANAGRAMS_H
#include "bits/stdc++.h"
using namespace std;

class GroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }

        for(auto m: mp) {
            ans.push_back(m.second);
        }
        return ans;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Counting
     *
     * class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (auto& s : strs) {
            int cnt[26] = {0};
            for (auto& c : s) ++cnt[c - 'a'];
            string k;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    k += 'a' + i;
                    k += to_string(cnt[i]);
                }
            }
            d[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : d) ans.emplace_back(v);
        return ans;
    }
};
     */
};


#endif //DOOCS_GROUPANAGRAMS_H
