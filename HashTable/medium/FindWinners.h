//
// Created by Aldrin on 15-01-2024.
//

#ifndef DOOCS_FINDWINNERS_H
#define DOOCS_FINDWINNERS_H
#include "bits/stdc++.h"
using namespace std;

class FindWinners {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> nums;
        unordered_map<int, int> winnerMap;
        unordered_map<int, int> loserMap;
        vector<vector<int>> result(2, vector<int>());

        for(auto m:matches) {
            winnerMap[m[0]]++;
            loserMap[m[1]]++;
            nums.insert(m[0]);
            nums.insert(m[1]);
        }

        for(auto n: nums) {
            if(winnerMap[n] > 0 and loserMap[n] == 0) {
                result[0].push_back(n);
            }
            else if(loserMap[n] == 1) {
                result[1].push_back(n);
            }
        }
        return result;
    }
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------
    // TC: O(n log n)
    // SC: O(N)
    /**
     * class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> zeroLoss, oneLoss, moreLoss;

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            // Add winner.
            if ((oneLoss.find(winner) == oneLoss.end()) &&
                (moreLoss.find(winner) == moreLoss.end())) {
                zeroLoss.insert(winner);
            }
            // Add or move loser.
            if (zeroLoss.find(loser) != zeroLoss.end()) {
                zeroLoss.erase(loser);
                oneLoss.insert(loser);
            } else if (oneLoss.find(loser) != oneLoss.end()) {
                oneLoss.erase(loser);
                moreLoss.insert(loser);
            } else if (moreLoss.find(loser) != moreLoss.end()) {
                continue;
            } else {
                oneLoss.insert(loser);
            }
        }

        vector<vector<int>> answer(2, vector<int>());
        answer[0].assign(zeroLoss.begin(), zeroLoss.end());
        answer[1].assign(oneLoss.begin(), oneLoss.end());
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};
     * **/
     //------------------------------------------------------------------------------------------------------------------------------------------------------------------
//     TC: O(n log n)
//     SC: O(N)
//     1 Set and 1 Map
     /**
      * class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> seen;
        unordered_map<int, int> lossesCount;

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            seen.insert(winner);
            seen.insert(loser);
            lossesCount[loser]++;
        }

        // Add players with 0 or 1 loss to the corresponding list.
        vector<vector<int>> answer(2, vector<int>());
        for (auto player : seen) {
            if (lossesCount.find(player) == lossesCount.end()) {
                answer[0].push_back(player);
            } else if (lossesCount[player] == 1) {
                answer[1].push_back(player);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};
      * **/
      //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
      /**
       * 1 Map
       * TC: O(n log n)
       * SC: O(N)
       *
       * class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lossesCount;
        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            if (lossesCount.find(winner) == lossesCount.end()) {
                lossesCount[winner] = 0;
            }
            lossesCount[loser]++;
        }

        vector<vector<int>> answer(2, vector<int>());
        for (auto [player, count] : lossesCount) {
            if (count == 0) {
                answer[0].push_back(player);
            } else if (count == 1) {
                answer[1].push_back(player);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};
       *
       * **/
       //---------------------------------------------------------------------------------------------------------------------------------------------------------------
       /**
        * Similar to Counting Sort
        * TC: O(N+K)
        * class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> lossesCount(100001, -1);

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            if (lossesCount[winner] == -1) {
                lossesCount[winner] = 0;
            }
            if (lossesCount[loser] == -1) {
                lossesCount[loser] = 1;
            } else {
                lossesCount[loser]++;
            }
        }

        vector<vector<int>> answer(2, vector<int>());
        for (int i = 1; i < 100001; ++i) {
            if (lossesCount[i] == 0) {
                answer[0].push_back(i);
            } else if (lossesCount[i] == 1) {
                answer[1].push_back(i);
            }
        }

        return answer;
    }
};
        * **/
       //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
};


#endif //DOOCS_FINDWINNERS_H
