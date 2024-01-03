//
// Created by Aldrin on 15-03-2022.
//

#ifndef DOOCS_SORTCOLORS_H
#define DOOCS_SORTCOLORS_H
#include "bits/stdc++.h"
using namespace std;

class SortColors {
public:
    //dutch national flag
    void sortColors(vector<int>& nums) {
       int l = 0;
       int h = nums.size()-1;
       int mid = 0;
        while (mid <= h){
            if(nums[mid] == 2)
                swap(nums[mid], nums[h--]);
            else if(nums[mid]==1)
                mid++;
            else swap(nums[l++], nums[mid++]);
        }
    }

    //counting sort approach
    /*
     class Solution {
public:
    void sortColors(vector<int>& nums) {
        //using counting sort (although best approach is dutch national flag algo., this is an alternate approach)
        int num0 = 0, num1 = 0, num2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                num0++;
            else if(nums[i] == 1)
                num1++;
            else if(nums[i] == 2)
                num2++;
        }
        for(int x = 0; x < num0; x++)
            nums[x] = 0;
        for(int y = num0; y < num0 + num1; y++)
            nums[y] = 1;
        for(int z = num0 + num1; z < nums.size(); z++)
            nums[z] = 2;
    }
};
     */
};


#endif //DOOCS_SORTCOLORS_H
