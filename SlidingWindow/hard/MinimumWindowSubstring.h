//
// Created by Aldrin on 05-02-2024.
//

#ifndef DOOCS_MINIMUMWINDOWSUBSTRING_H
#define DOOCS_MINIMUMWINDOWSUBSTRING_H
#include "bits/stdc++.h"
using namespace std;

class MinimumWindowSubstring {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0, n = s.size(), minStart = INT_MAX, minLen = INT_MAX, count = 0;
        unordered_map<char, int> mp;

        // hash the string t
        for(char ch:t) {
            mp[ch]++;
            count++;
        }

        while(j < n) {
            if(mp[s[j]] > 0)
                count--;
            mp[s[j]]--;
            j++;

            while(count == 0) {
                if(j - i < minLen) {
                    minLen = j - i;
                    minStart = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0)
                    count++;
                i++;
            }

            return minLen != INT_MAX ? s.substr(minStart, minLen) : "";
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0, N = s.length(), M = t.length();
        vector<int> mask(256, 0);
        for (auto &c: t) mask[c] += 1;

        int counter = 0;
        int res_start = -1, res_size = INT_MAX;
        while (end < N) {
            if (mask[s[end]] > 0) {
                // present in t
                counter += 1;
            }

            // Decrement irrespective of whether present in t or not
            mask[s[end]] -= 1;

            while (counter == M) {
                // valid substring
                if (end - start + 1 < res_size) {
                    res_start = start;
                    res_size = end - start + 1;
                }

                // Update start
                mask[s[start]] += 1;
                if (mask[s[start]] > 0) counter -= 1; // present in t
                start += 1;
            }
            end += 1;
        }
        if (res_start == -1) return "";
        return s.substr(res_start, res_size);
    }
};
     */
    //-----------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    string minWindow(string s, string t) {
        int need[128]{};
        int window[128]{};
        int m = s.size(), n = t.size();
        for (char& c : t) {
            ++need[c];
        }
        int cnt = 0, j = 0, k = -1, mi = 1 << 30;
        for (int i = 0; i < m; ++i) {
            ++window[s[i]];
            if (need[s[i]] >= window[s[i]]) {
                ++cnt;
            }
            while (cnt == n) {
                if (i - j + 1 < mi) {
                    mi = i - j + 1;
                    k = j;
                }
                if (need[s[j]] >= window[s[j]]) {
                    --cnt;
                }
                --window[s[j++]];
            }
        }
        return k < 0 ? "" : s.substr(k, mi);
    }
};
     */
};


#endif //DOOCS_MINIMUMWINDOWSUBSTRING_H
