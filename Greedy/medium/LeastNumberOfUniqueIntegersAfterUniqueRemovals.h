//
// Created by Aldrin on 16-02-2024.
//

#ifndef MITOSO_LEASTNUMBEROFUNIQUEINTEGERSAFTERUNIQUEREMOVALS_H
#define MITOSO_LEASTNUMBEROFUNIQUEINTEGERSAFTERUNIQUEREMOVALS_H
#include "bits/stdc++.h"
using namespace std;

class LeastNumberOfUniqueIntegersAfterUniqueRemovals {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int a: arr)
            mp[a]++;

        for(auto m: mp)
            pq.push(m.second);

        // Greedily remove the k least frequent numbers to have the least number of
        // unique integers.
        while (k > 0)
            k -= pq.top(), pq.pop();

        return pq.size() + (k < 0 ? 1 : 0);
    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     * Sorting the frequencies
     *
     * TC: O(N LogN)
     * SC: O(N)
     *
     * class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        // Vector to track all the frequencies
        vector<int> frequencies;
        for (auto it : map) {
            frequencies.push_back(it.second);
        }

        // Sorting the frequencies
        sort(frequencies.begin(), frequencies.end());

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        for (int i = 0; i < frequencies.size(); i++) {
            // Removing frequencies[i] elements which equates to
            // removing one unique element
            elementsRemoved += frequencies[i];

            // If the number of elements removed exceeds k, we'll return
            // the remaining number of unique elements.
            if (elementsRemoved > k) {
                return frequencies.size() - i;
            }
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------
    /*Min Heap
     * TC: O(N log N)
     * SC: O(N)
     *
     *class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        // Min heap to track all the frequencies
        priority_queue<int, vector<int>, greater<int> > frequencies;
        for (auto it : map) {
            frequencies.push(it.second);
        }

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        // Traversing all frequencies
        while (!frequencies.empty()) {
            // Removing the least frequent element
            elementsRemoved += frequencies.top();

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size();
            }
            frequencies.pop();
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     * Counting Sort
     *
     * TC: O(N)
     * SC: O(N)
     *
     * class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        int n = arr.size();

        // Array to track the frequencies of frequencies!
        // The maximum possible frequency of any element
        // will be n so we'll initialize this array with size n + 1
        vector<int> countOfFrequencies(n + 1, 0);

        // Popoulating countOfFrequencies array
        for (auto it : map) {
            countOfFrequencies[it.second]++;
        }

        // Variable to track the remaining number of unique elements
        int remainingUniqueElements = map.size();

        // Traversing over all possible frequencies
        for (int i = 1; i <= n; i++) {
            // For each possible frequency i, we'd like to remove as
            // many elements with that frequency as possible.
            // k / i represents the number of maximum possible elements
            // we could remove with k elements left to remove.
            // countOfFrequencies[i] represents the actual number of elements
            // with frequency i.
            int numElementsToRemove = min(k / i, countOfFrequencies[i]);

            // Removing maximum possible elements
            k -= (i * numElementsToRemove);

            // numElementsToRemove is the count of unique elements removed
            remainingUniqueElements -= numElementsToRemove;

            // If the number of elements that can be removed is less
            // than the current frequency, we won't be able to remove
            // any more elements with a higher frequency so we can return
            // the remaining number of unique elements
            if (k < i) {
                return remainingUniqueElements;
            }
        }

        // We have traversed all possible frequencies i.e.,
        // removed all elements. Returning 0 in this case.
        return 0;
    }
};
     */
};


#endif //MITOSO_LEASTNUMBEROFUNIQUEINTEGERSAFTERUNIQUEREMOVALS_H
