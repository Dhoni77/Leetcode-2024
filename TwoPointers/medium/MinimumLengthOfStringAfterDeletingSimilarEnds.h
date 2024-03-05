//
// Created by Aldrin on 05-03-2024.
//

#ifndef DOOCS_MINIMUMLENGTHOFSTRINGAFTERDELETINGSIMILARENDS_H
#define DOOCS_MINIMUMLENGTHOFSTRINGAFTERDELETINGSIMILARENDS_H
#include "bits/stdc++.h"
using namespace std;

class MinimumLengthOfStringAfterDeletingSimilarEnds {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n == 1)
            return 1;
        int i = 0, j = n - 1, len = n;

        while (i < j and s[i] == s[j]) {
            char curr = s[i];
            while(i < j and s[i] == curr) {
                len--,i++;
            }
            while(i <= j and s[j] == curr)
                len--, j--;
        }

        return len;
    }
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int minimumLength(string s) {
        int begin = 0;
        int end = s.length() - 1;

        // Delete similar ends until the ends differ or they meet in the middle
        while (begin < end && s[begin] == s[end]) {
            char c = s[begin];

            // Delete consecutive occurrences of c from prefix
            while (begin <= end && s[begin] == c) {
                begin++;
            }

            // Delete consecutive occurrences of c from suffix
            while (end > begin && s[end] == c) {
                end--;
            }
        }

        // Return the number of remaing characters
        return end - begin + 1;
    }
};
     */
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *     int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            while (i + 1 < j && s[i] == s[i + 1]) {
                ++i;
            }
            while (i < j - 1 && s[j] == s[j - 1]) {
                --j;
            }
            ++i;
            --j;
        }
        return max(0, j - i + 1);
    }
     */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * TC: O(N)
     * SC: O(1)
     * class Solution {
 public:
  int minimumLength(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < j && s[i] == s[j]) {
      const char c = s[i];
      while (i <= j && s[i] == c)
        ++i;
      while (i <= j && s[j] == c)
        --j;
    }

    return j - i + 1;
  }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Tail Recursive solution
     *
     * class Solution {
        public:
            int minimumLength(string s) {
                return deleteSimilarEnds(s, 0, s.length() - 1);
            }
        private:
            // Deletes similar ends and returns remaining length
            int deleteSimilarEnds(string &s, int begin, int end) {
                // The ends differ or meet in the middle
                if (begin >= end || s[begin] != s[end]){
                    return end - begin + 1;
                } else {
                    char c = s[begin];

                    // Delete consecutive occurrences of c from prefix
                    while (begin <= end && s[begin] == c)
                        begin++;

                    // Delete consecutive occurrences of c from suffix
                    while (end > begin && s[end] == c)
                        end--;

                    return deleteSimilarEnds(s, begin, end);
                }
            }
};
     */
};


#endif //DOOCS_MINIMUMLENGTHOFSTRINGAFTERDELETINGSIMILARENDS_H
