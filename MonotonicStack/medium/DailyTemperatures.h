//
// Created by Aldrin on 31-01-2024.
//

#ifndef DOOCS_DAILYTEMPERATURES_H
#define DOOCS_DAILYTEMPERATURES_H
#include "bits/stdc++.h"
using namespace std;

class DailyTemperatures {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n  = temperatures.size();
        st.push(0);

        for(int i=1;i<n;i++) {
            if(st.empty()) {
                st.push(i);
                continue;
            }

            while(!st.empty() and temperatures[st.top()] < temperatures[i]) {
                temperatures[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()) {
            temperatures[st.top()] = 0;
            st.pop();
        }

        return temperatures;
    }
    //-----------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        stack<int> st;
        vector<int> ret(temperatures.size(), 0);
        int i = 0;
        while(i < temperatures.size()){
            if(st.empty() || temperatures[st.top()] >= temperatures[i]){
                st.push(i);
                i++;
            }
            else{
                ret[st.top()] = i - st.top();
                st.pop();
            }
        }

        return ret;
    }

};
     */
    //--------------------------------------------------------------------------------------------------------------------------------
    /*
     * Approach 2: Array, Optimized Space
        Intuition

        With the monotonic stack, we iterated forward through the array and moved backwards when we found a warmer day. In this approach, we'll do the reverse - iterate backwards through the array, and move forwards to find the number of days until a warmer day.

        In the first approach, answer exists only to hold the answer. An important thing to notice is that answer carries information that we can use to solve the problem. We can save space and replace the functionality of the stack by using information from answer.

        Let's use the example test case temperatures = [73, 74, 75, 71, 69, 72, 76, 73]. Iterating backwards, after 5 days we have: answer = [0, 0, 0, 2, 1, 1, 0, 0].

        The next day to calculate is the day at index 2 with temperature 75. How can we use answer to help us do this? Well, let's first check the next day - we might be lucky and it could be warmer. The next day (at index 3) has a temperature of 71, which is not warmer. However, answer[3] tells us that the day at index 3 will not see a warmer temperature for 2 more days. A temperature warmer than 75 must also be warmer than 71 - so we know it is pointless to check answer[4]. We should check temperatures[3 + answer[3]] = temperatures[5] = 72, which is not warmer than 75. Again, we know from answer[5] that we will not have a warmer temperature than 72 for 1 day. Therefore, the next day to check is temperatures[5 + answer[5]] = temperatures[6] = 76, which is warmer - we found our day.

        To keep track of the number of days, we can use a variable days initially set to 1 and continuously add to it to query the next day. Using the above example, we would start with currDay = 2, and query temperatures[currDay + days] = temperatures[2 + 1]. After finding that it is not warmer, we will add answer[3] to days, and our next search will be at temperatures[currDay + days] = temperatures[2 + 3]. When we find our warmer day, we can set answer[currDay] = days.

        From this small example, it may seem like this algorithm isn't very efficient. However, imagine if we had something like answer = [0, 85134, ...] and we needed to calculate the answer for the first day (at index 0). If the second day is not warmer than the first day, then this algorithm allows us to skip over 85000 days, because we already know that none of those days could be warmer than the first day.

        One last note: this process does not work for a day that does not have a warmer day in the future. Therefore, we need to use a variable hottest to keep track of the hottest day seen so far. If a day is warmer than hottest, then we know the answer for that day is 0, and we don't need to go through the process described above.

        Algorithm

        Initialize an array answer with the same length as temperatures and all values initially set to 0. Also, initialize an integer hottest = 0 to track the hottest temperature seen so far.

        Iterate backwards through the input. At each index currDay, check if the current day is the hottest one seen so far. If it is, update hottest and move on. Otherwise, do the following:

        Initialize a variable days = 1 because the next warmer day must be at least one day in the future.
        While temperatures[currDay + days] <= temperatures[currDay]:
        Add answer[currDay + days] to days. This effectively jumps directly to the next warmer day.
        Set answer[currDay] = days.
        Return answer.

                class Solution {
            public int[] dailyTemperatures(int[] temperatures) {
                int n = temperatures.length;
                int hottest = 0;
                int answer[] = new int[n];

                for (int currDay = n - 1; currDay >= 0; currDay--) {
                    int currentTemp = temperatures[currDay];
                    if (currentTemp >= hottest) {
                        hottest = currentTemp;
                        continue;
                    }

                    int days = 1;
                    while (temperatures[currDay + days] <= currentTemp) {
                        // Use information from answer to search for the next warmer day
                        days += answer[currDay + days];
                    }
                    answer[currDay] = days;
                }

                return answer;
            }
        }
     */
};


#endif //DOOCS_DAILYTEMPERATURES_H
