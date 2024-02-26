//
// Created by Aldrin on 26-02-2024.
//

#ifndef DOOCS_KTHLARGESTELEMENTINANARRAY_H
#define DOOCS_KTHLARGESTELEMENTINANARRAY_H
#include "bits/stdc++.h"
using namespace std;

class KThLargestElementInAnArray {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        int n = nums.size();

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }

        while(k-- > 1){
            pq.pop();
        }

        return pq.top();
    }
};


#endif //DOOCS_KTHLARGESTELEMENTINANARRAY_H
