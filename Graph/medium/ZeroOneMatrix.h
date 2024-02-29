//
// Created by Aldrin on 29-02-2024.
//

#ifndef DOOCS_ZEROONEMATRIX_H
#define DOOCS_ZEROONEMATRIX_H
#include "bits/stdc++.h"
using namespace std;

class ZeroOneMatrix {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> dirs{-1, 0, 1, 0, -1};
        int row = mat.size(), col = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(row, vector<int>(col, -1));

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int x = node.first + dirs[i], y = node.second + dirs[i+1];
                if(x >= 0 and y >= 0 and x < row and y < col and ans[x][y] == -1) {
                    ans[x][y] = ans[node.first][node.second] + 1;
                    q.emplace(x, y);
                }
            }
        }

        return ans;
    }
};


#endif //DOOCS_ZEROONEMATRIX_H
