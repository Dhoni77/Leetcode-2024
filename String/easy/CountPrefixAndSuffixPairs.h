//
// Created by Aldrin on 19-02-2024.
//

#ifndef DOOCS_COUNTPREFIXANDSUFFIXPAIRS_H
#define DOOCS_COUNTPREFIXANDSUFFIXPAIRS_H
#include "bits/stdc++.h"
using namespace std;

class CountPrefixAndSuffixPairs {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        // Iterate each string in the arr1
        for(int i=0;i<arr1.size();i++)
        {
            string val=to_string(arr1[i]);
            string prefix;
            // iterate each character, append it to prefix and add the prefix to the set
            // e.g. if val is 100, for 1st iteration, prefix="1", 2nd: prefix="10", 3rd: prefix="100" etc
            // after first outer loop, set = Set("1", "10", "100")
            for(auto ch:val)
            {
                prefix+=ch;
                st.insert(prefix);
            }
        }
        int ans=0;
        // Check every prefix combination in arr2, to see if it exists in the set we created above
        for(int i=0;i<arr2.size();i++)
        {
            string val=to_string(arr2[i]);
            string prefix;
            for(auto ch:val)
            {
                prefix+=ch;
                if(st.count(prefix))ans=max(ans,(int)prefix.size());
            }
        }
        return ans;

    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    // https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/solutions/4744549/z-function-and-rolling-hash-o-nm-c/
    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Time complexity: O(n * k)
        where n is the number of strings in the array and k is the average length of a string. This is because we iterate through each string once (O(n)), and for each string, we perform operations that are proportional to its length (O(k)).
        Space complexity: O(n * k)
        due to the prefix and suffix frequency maps.
     * class Solution {
        public:
            int countPrefixSuffixPairs(vector<string>& words) {
                int ans = 0;
                for(int i=0;i<words.size()-1;i++){
                    for(int j=i+1;j<words.size();j++){
                        if(words[j].starts_with(words[i])==true && words[j].ends_with(words[i])==true){
                            ans++;
                        }
                    }
                }
                return ans;
            }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * ZAlgo
     *
     *
class Solution {
public:

    vector<int> zFun(string &s) {
        int n = s.length();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for(int i=1; i<n; i++)  {
            if(i < r)   z[i] = min(r-i, z[i-l]);
            while(i+z[i] < n && s[i+z[i]] == s[z[i]])   z[i]++;
            if(i+z[i] > r)  l = i, r = i + z[i];
        }
        return z;
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        unordered_map<string, long long> mp;
        unordered_set<int> count;

        for(auto &s : words)    {
            vector<int> z = zFun(s);
            int n = s.length();
            for(int i=1; i<n; i++)  {
                if(i+z[i] == n && count.find(z[i]) != count.end())  {
                    string temp = s.substr(0, z[i]);
                    ans += mp[temp];
                }
            }
            if(mp.find(s) != mp.end())
                ans += mp[s];
            mp[s]++;
            count.insert(n);
        }

        return ans;
    }
};
    ["a","aba","ababa","aa"]
    ["pa","papa","ma","mama"]
    ["abab","ab"]
    ["a","a"]
    ["a","aa","aa","b","ab"]
    ["bcc","c","cbaaa","ba","cabbc","b","bcbb","baca","caa","aa","caa","ca","cacac"]
    */
};


#endif //DOOCS_COUNTPREFIXANDSUFFIXPAIRS_H
