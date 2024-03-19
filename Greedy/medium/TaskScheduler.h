//
// Created by Aldrin on 19-03-2024.
//

#ifndef DOOCS_TASKSCHEDULER_H
#define DOOCS_TASKSCHEDULER_H
#include "bits/stdc++.h"
using namespace std;

class TaskScheduler {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        int x = 0;
        for (char c : tasks) {
            c -= 'A';
            ++cnt[c];
            x = max(x, cnt[c]);
        }
        int s = 0;
        for (int v : cnt) {
            s += v == x;
        }
        return max((int) tasks.size(), (x - 1) * (n + 1) + s);
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> freq(26, 0);
        int maxSizeFreq = 0, sz = tasks.size(), maxSize = 0;

        // update hash and also the maxSize
        for(auto ch : tasks){
            freq[ch-'A']++;
            maxSize = max(maxSize, freq[ch-'A']);
        }

        for(int i : freq){
            if(i == maxSize)maxSizeFreq++;
        }

        int time = ((n+1) * (maxSize-1)) + maxSizeFreq;

        return max(time, sz);
    }
};
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int counter[26] = {0};
    int maxF = 0; // max_freq
    int maxFc = 0; // no of ch having max_freq

    int N = tasks.size();

    for (int i = 0; i < N; i++) {
        counter[tasks[i] - 'A']++;
    }

    for (int x : counter) {
        if (maxF == x) {
            maxFc++;
        }
        if (maxF < x) {
            maxF = x;
            maxFc = 1;
        }
    }

    int gaps = maxF - 1; // number of gaps required

    int gaps_len = k - (maxFc - 1); // number of ch that can be fit in partition gaps

    int avail_slot = gaps * gaps_len; // empty slots = number of gaps * gaps_len

    int avail_task = N - maxF * maxFc;

    int idles = max(0, avail_slot - avail_task); // place available tasks in total available
    // slots and rest as idle

    return N + idles;

    }

};
     */
};


#endif //DOOCS_TASKSCHEDULER_H
