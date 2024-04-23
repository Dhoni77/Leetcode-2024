//
// Created by Aldrin on 20-04-2024.
//

#ifndef DOOCS_FINDALLGROUPSOFFARMLAND_H
#define DOOCS_FINDALLGROUPSOFFARMLAND_H
#include "bits/stdc++.h"
using namespace std;

class FindAllGroupsOfFarmland {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int row = land.size(), col = land[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for(int r1=0;r1<row;r1++) {
            for(int c1=0;c1<col;c1++) {
                if(land[r1][c1] and !vis[r1][c1]) {
                    int r2 = r1, c2 = c1;

                    for(r2=r1;r2<row and land[r2][c1];r2++) {
                        for(c2=c1;c2<col and land[r2][c2];c2++) {
                            vis[r2][c2] = 1;
                        }
                    }

                    ans.push_back({r1, c1, r2 - 1, c2 - 1});
                }
            }
        }

        return ans;
    }
};


#endif //DOOCS_FINDALLGROUPSOFFARMLAND_H
