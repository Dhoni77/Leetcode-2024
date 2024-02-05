//
// Created by Aldrin on 02-02-2024.
//

#ifndef DOOCS_SEQUENTIALDIGITS_H
#define DOOCS_SEQUENTIALDIGITS_H
#include "bits/stdc++.h"
using namespace std;

class SequentialDigits {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i=1;i<9;i++) {
            int x = i;
            for(int j=i+1;j<10;j++) {
                x = x * 10 + j;
                if(x >= low and x <= high) {
                    result.push_back(x);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
        public:
            string s = "123456789";

            vector<int> sequentialDigits(int L, int R) {
                vector<int> ans;
                for (int len = 1; len <= 9; len++) {
                    for (int i = 0; i + len <= 9; i++) {
                        int x = stoi(s.substr(i, len));
                        if (L <= x && x <= R) {
                            ans.push_back(x);
                        }
                        if (x > R) break;
                    }
                }
                return ans;
            }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Approach 2
        Sliding window

        Here we use substr function to access the substrings
        of width 2 to 9
        or we can say window of size 2 is slided over the string
        s="123456789"

        then window of size/width 3 is slided over the string
        then window of size/width 4 is slided over the string
        .
        .
        .
        .
        till width 9

        Why do we traverse according to width ? Because it ensures sorted
        order as well.

        now for width=2  and s="123456789"
        we start the substrings from j=0 to j=10-i-1;

        for width =3 j will stop at 10-3-1=6th index of s i.e. 789
        for width =5 j will stop at 10-5-1=4th index of s i.e  56789
        for width =8 j will stop at 10-8-1=1st index of s i.e  23456789
        Code 2
        class Solution {
        public:
            vector<int> sequentialDigits(int low, int high) {
                string s = "123456789";
                vector<int>res;
                for (int width=2;width<=9;width++){// width : window size
                    for(int j=0;j<=9-width;j++){
                        int num=stoi(s.substr(j,width));
                        if(num<=high && num>=low)
                            res.push_back(num);
                    }
                }
                return res;
            }
        };
        // s.substr(start position, length)
        We can further optimize the code by restricting the width-for loop
        even more by pre calculating the number of digits in low and high.

        Currently width loop goes from 2 to 9 but why should we traverse
        unwanted windows . For example :
        if low=1000 high=13000
        we should ignore all widths of less than 4
        and all width of greater than 5
     */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int l = to_string(low).size(); // l contains number of digits in low
        int h = to_string(high).size();// h contains number of digits in high
        vector<int>res;
        for (int width=l;width<=h;width++){// width : window size
            for(int j=0;j<=9-width;j++){
                int num=stoi(s.substr(j,width));
                if(num<=high && num>=low)
                    res.push_back(num);
            }
        }
        return res;
    }
};
     */
};


#endif //DOOCS_SEQUENTIALDIGITS_H
