//
// Created by Aldrin on 28-02-2024.
//

#ifndef DOOCS_ROTTINGORANGES_H
#define DOOCS_ROTTINGORANGES_H
#include "bits/stdc++.h"
using namespace std;

class RottingOranges {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row = grid.size(), col = grid[0].size(), freshFruits = 0, ans = 0;
        for(int i=0;i<row;i++) {
            for(int j = 0;j<col;j++) {
                if(grid[i][j] == 2) {
                    q.emplace(i, j);
                }
                else if(grid[i][j]) {
                    freshFruits++;
                }
            }
        }

        // if no fresh fruits
        if(freshFruits == 0)
            return 0;

        // if no rotten fruits are there
        if(q.empty())
            return -1;

        while(!q.empty() and freshFruits > 0) {
            int sz = (int)q.size();
            bool isWorkDone = false;
            while(sz-- > 0) {
                auto orange = q.front();
                q.pop();
                for(int i=0;i<4;i++) {
                    int x = orange.first + dirs[i], y = orange.second + dirs[i+1];
                    if(x >= 0 and y >= 0 and x < row and y < col and grid[x][y] == 1) {
                        q.emplace(x, y);
                        grid[x][y] = 2;
                        isWorkDone = true;
                        freshFruits--;
                    }
                }
            }
            if(isWorkDone)
                ans++;
        }

        return freshFruits == 0 ? ans : -1;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * BFS
     *
     * class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        typedef pair<int, int> pii;
        queue<pii> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    q.emplace(i, j);
                else if (grid[i][j] == 1)
                    ++cnt;
            }
        }
        int ans = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty() && cnt > 0) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                auto p = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p.first + dirs[j];
                    int y = p.second + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        --cnt;
                        grid[x][y] = 2;
                        q.emplace(x, y);
                    }
                }
            }
        }
        return cnt > 0 ? -1 : ans;
    }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * DFS
     *
     *     class Solution {
    public:
        void dfs(vector<vector<int>>&grid, int i, int j, int min=2)
        {
            if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or  grid[i][j]==0 or (1 < grid[i][j] and grid[i][j] < min))return ;
            grid[i][j]=min; // Assign the current minute to the grid
            dfs(grid,i+1,j,min+1);  // Recursive call to all 4 sides one by one and by incrementing tine by +1
            dfs(grid,i-1,j,min+1);
            dfs(grid,i,j+1,min+1);
            dfs(grid,i,j-1,min+1);
        }
        int orangesRotting(vector<vector<int>>& grid) {
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==2) dfs(grid,i,j); // We have to proceed on those orananges which are rotten already and start a recursive call and the reason why we are sending 2 is because we cannot mark time as 0,1,2 Since they are being used in the question (empty cell, fresh orange,rotten orange)
                }
            }
            int min=2;
            for(auto &i:grid)
            {
                for(auto &j:i)
                {
                    if(j==1) return -1; // if by any means, any value is 1, that means we weren't able to rot that orange, Here min= Total time (minutes)
                    min=max(min,j);  // otherwise, maximum time to rot.
                }
            }
            return min-2;
        }
    };
     */
};


#endif //DOOCS_ROTTINGORANGES_H
