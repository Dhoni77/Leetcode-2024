//
// Created by Aldrin on 02-01-2024.
//

#ifndef DOOCS_CONVERTTO2DARRAYWITHCONDITIONS2610_H
#define DOOCS_CONVERTTO2DARRAYWITHCONDITIONS2610_H
#include "bits/stdc++.h"
using namespace std;

class ConvertTo2DArrayWithConditions2610 {
public:
    /**
     * vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> mp;
        int limit = INT_MIN;
        for(auto num: nums) {
            mp[num]++;
            limit = max(limit, mp[num]);
        }
        for(int i=0;i<limit;i++) {
            vector<int> ans;
            for(auto m: mp) {
                if(m.second > 0) {
                    ans.push_back(m.first);
                    mp[m.first]--;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
     * **/

    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> mp;
        for(auto num: nums) {
            mp[num]++;
        }
        while(!mp.empty()) {
            vector<int> temp;
            for(auto it=mp.begin(); it!=mp.end();) {
                temp.push_back(it->first);
                it->second--;
                if(it->second == 0) {
                    it = mp.erase(it);
                } else {
                    it++;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};


#endif //DOOCS_CONVERTTO2DARRAYWITHCONDITIONS2610_H
