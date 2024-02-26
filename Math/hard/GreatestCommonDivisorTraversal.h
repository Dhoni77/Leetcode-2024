//
// Created by Aldrin on 25-02-2024.
//

#ifndef DOOCS_GREATESTCOMMONDIVISORTRAVERSAL_H
#define DOOCS_GREATESTCOMMONDIVISORTRAVERSAL_H
#include "bits/stdc++.h"
using namespace std;

const int MAX = 1e5 + 5;
bool prime[MAX]; // Is that number prime or not
int spf[MAX]; // Smallest prime Factor of that number

void sieve() {
    fill(prime, prime + MAX, true);
    for (int i = 1; i < MAX; i++)
        spf[i] = i;
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i ; j < MAX ; j += i) {
                if (prime[j])
                    spf[j] = i;
                prime[j] = false;
            }
        }
    }
}

class GreatestCommonDivisorTraversal {
public:

// Multiple Query ( Use Sieve for this ) ( All prime factors but as  {prime factor, count} )
    vector<int> getFactorization2(int x)
    {
        vector<int> ret;
        unordered_map<int, int> mp;
        while (x != 1) {
            mp[spf[x]]++;
            x = x / spf[x];
        }

        for (auto p : mp) ret.push_back(p.first);
        return ret;
    }


    int ct;
    void dfs(int node, unordered_map<int, vector<int>>& gr, vector<bool>& vis){
        if(vis[node])
            return;

        vis[node] = true;
        ct++;
        for(auto ne : gr[node]){
            if(vis[ne]==0)
                dfs(ne, gr, vis);
        }
    }

        bool canTraverseAllPairs(vector<int>& nums) {
            sieve();

            int n = nums.size();
            unordered_map<int, vector<int>> mp;
            for(int i=0;i<n;i++){
                mp[i] = getFactorization2(nums[i]);
            }


            unordered_map<int, vector<int>> rmp;
            for(auto p : mp){
                int id = p.first;

                for(auto prime : p.second)
                    rmp[prime].push_back(id);
            }

            unordered_map<int, vector<int>> gr;
            for(auto p : rmp){
                vector<int> ids = p.second;
                if(ids.size()<=1)
                    continue;

                for(int i=1;i<ids.size();i++){
                    int u = ids[i-1];
                    int v = ids[i];

                    gr[u].push_back(v);
                    gr[v].push_back(u);
                }
            }

            vector<bool> vis(n, 0);
            ct = 0;
            dfs(0, gr, vis);
            if(ct==n)
                return true;

            return false;
        }
};


#endif //DOOCS_GREATESTCOMMONDIVISORTRAVERSAL_H
