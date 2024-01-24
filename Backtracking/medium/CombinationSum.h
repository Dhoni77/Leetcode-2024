//
// Created by Aldrin on 24-01-2024.
//

#ifndef DOOCS_COMBINATIONSUM_H
#define DOOCS_COMBINATIONSUM_H
#include "bits/stdc++.h"
using namespace std;

class CombinationSum {
public:
    void solve(int ind, int target, int n, vector<int> arr, vector<vector<int>>& ans, vector<int>& res) {
        if(ind == n) {
            if(target == 0)
                ans.push_back(res);
            return;
        }

        if(arr[ind] <= target) {
            res.push_back(arr[ind]);
            solve(ind, target - arr[ind], n, arr, ans, res);
            res.pop_back();
        }

        solve(ind + 1, target, n, arr, ans, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        solve(0, target, candidates.size(), candidates, result, ans);
        return result;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    vector<vector<int>> ans;
    vector<int> candidates;
    vector<int> path;

    void dfs(int idx, int target) {
        if (idx >= candidates.size() || target <= 0) {
            if (target == 0) ans.push_back(path);
            return;
        }

        for (int i = 0; i * candidates[idx] <= target; i ++ ) {
            dfs(idx + 1, target - candidates[idx] * i);
            path.push_back(candidates[idx]);
        }

        for (int i = 0; i * candidates[idx] <= target; i ++ )
            path.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& _candidates, int target) {
        candidates = _candidates;

        dfs(0, target);

        return ans;
    }
};
     */
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int> &a, int sum, vector<vector<int>> &ans)
    {
        if(sum>target) return;
        if(sum==target)
        {
            ans.push_back(a);
            return;
        }
        for(int i=idx; i<candidates.size(); i++)
        {
            a.push_back(candidates[i]);
            sum+=candidates[i];
            solve(i, candidates, target, a, sum, ans);
            a.pop_back();
            sum-=candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> a;
        solve(0, candidates, target, a, 0, ans);
        return ans;
    }
};
     */
};


#endif //DOOCS_COMBINATIONSUM_H
