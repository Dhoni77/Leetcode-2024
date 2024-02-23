//
// Created by Aldrin on 22-02-2024.
//

#ifndef DOOCS_FINDTHETOWNJUDGE_H
#define DOOCS_FINDTHETOWNJUDGE_H
#include "bits/stdc++.h"
using namespace std;

class FindTheTownJudge {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);

        for(int i=0;i<trust.size();i++) {
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        }

        for(int i=1;i<=n;i++) {
            if(in[i] == n - 1 and out[i] == 0)
                return i;
        }

        return -1;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int findJudge(int n, vector<vector<int>> trust) {
        if (trust.size() == 0 && n == 1)
            return 1;
        vector<int> count(n + 1);
        for (auto person : trust) {
            //count[person[0]]--; decrements the trust count of the first person in the pair. This is done because if the first person trusts the second person, it means that the first person does not trust themselves.
            count[person[0]]--;
            //count[person[1]]++; increments the trust count of the second person in the pair. This is done because if the first person trusts the second person, it means that the second person is trusted by the first person.
            count[person[1]]++;
        }

        for (int person = 0; person < count.size(); person++) {
            // check if there is a person who is trusted by everyone except themselves (n-1 people) and if such person exists it returns the index of that person.
            if (count[person] == n - 1) return person;
        }
        return -1;
    }
};
     */
};


#endif //DOOCS_FINDTHETOWNJUDGE_H
