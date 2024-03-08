//
// Created by Aldrin on 08-03-2024.
//

#ifndef DOOCS_COUNTELEMENTSWITHMAXIMUMFREQUENCY_H
#define DOOCS_COUNTELEMENTSWITHMAXIMUMFREQUENCY_H
#include "bits/stdc++.h"
using namespace std;

class CountElementsWithMaximumFrequency {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int arr[101] = {0};
        int ans = 0, maxfreq = 0;

        for(int n: nums) {
            arr[n]++;

            if(arr[n] > maxfreq) {
                ans = arr[n];
            }
            else if(arr[n] == maxfreq)
                ans += arr[n];

            maxfreq = max(maxfreq, arr[n]);
        }
        return ans;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(100 ,0);
        for(int i=0; i<n; i++){
            freq[nums[i]-1]++;
        }
        int maxf = INT_MIN;
        for(int i=0; i<100; i++){
            maxf = max(maxf , freq[i]);
        }
        vector<int> maxfreq;
        for(int i=0; i<100; i++){
            if(freq[i] == maxf) maxfreq.push_back(i+1);
        }
        return ((maxfreq.size())*(maxf));
    }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        int maxFrequency = 0;
        int totalFrequencies = 0;

        // Find the frequency of each element
        // Determine the maximum frequency
        // Calculate the total frequencies of elements with the maximum frequency
        for (int num : nums) {
            frequencies[num]++;
            int frequency = frequencies[num];

            // If we discover a higher frequency element
            // Update maxFrequency
            // Re-set totalFrequencies to the new max frequency
            if (frequency > maxFrequency) {
                maxFrequency = frequency;
                totalFrequencies = frequency;
                // If we find an element with the max frequency, add it to the total
            } else if (frequency == maxFrequency) {
                totalFrequencies += frequency;
            }
        }
        return totalFrequencies;
    }
};
     */
};


#endif //DOOCS_COUNTELEMENTSWITHMAXIMUMFREQUENCY_H
