//
// Created by Aldrin on 07-02-2024.
//

#ifndef DOOCS_SORTCHARACTERSBYFREQUENCY_H
#define DOOCS_SORTCHARACTERSBYFREQUENCY_H
#include "bits/stdc++.h"
using namespace std;

class Compare {
public:
    bool operator()(pair<char, int> &a, pair<char, int> &b) {
        return a.second == b.second ? a.first < b.first : b.second > a.first;
    }
};

class SortCharactersByFrequency {
    string frequencySort(string s) {
        string result = "";
        unordered_map<char, int> mp;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        if(s.length() == 1)
            return s;
        for(char ch: s) {
            mp[ch]++;
        }

        for(auto m: mp) {
            pq.push({m.first, m.second});
        }

        while(!pq.empty()) {
            int freq = pq.top().second;
            while(freq-- > 0) {
                result += pq.top().first;
            }
            pq.pop();
        }
        return result;
    }
    //---------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    typedef pair<char,int> P;
    string frequencySort(string s) {
        vector<P> vec(123);

        for(char &ch:s){
            int freq=vec[ch].second;
            vec[ch]={ch,freq+1};
        }
        auto lambda=[&](P &p1, P &p2){
            return p1.second>p2.second;
        };
        sort(begin(vec),end(vec),lambda);
        string result="";

        for(int i=0;i<=122;i++){
            if(vec[i].second>0){
                char ch= vec[i].first;
                int freq=vec[i].second;
                string temp=string(freq,ch);
                result+=temp;
            }
        }
    return result;

    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char& c : s) {
            ++cnt[c];
        }
        vector<char> cs;
        for (auto& [c, _] : cnt) {
            cs.push_back(c);
        }
        sort(cs.begin(), cs.end(), [&](char& a, char& b) {
            return cnt[a] > cnt[b];
        });
        string ans;
        for (char& c : cs) {
            ans += string(cnt[c], c);
        }
        return ans;
    }
};
     */
};


#endif //DOOCS_SORTCHARACTERSBYFREQUENCY_H
