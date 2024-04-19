//
// Created by Aldrin on 18-04-2024.
//

#ifndef DOOCS_ISLANDPERIMETER_H
#define DOOCS_ISLANDPERIMETER_H
#include "bits/stdc++.h"
using namespace std;

class IslandPerimeter {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j]) {
                    int up = 0, down = 0, left = 0, right = 0;
                    // up
                    if(i == 0)
                        up = 1;
                    else up = grid[i-1][j] == 0;
                    // down
                    if(i == row - 1)
                        down = 1;
                    else down = grid[i+1][j] == 0;
                    // left
                    if(j == 0)
                        left = 1;
                    else left = grid[i][j-1] == 0;
                    // right
                    if(j == col - 1)
                        right = 1;
                    else right = grid[i][j+1] == 0;

                    ans += (up + down + left + right);
                }
            }
        }
        return ans;
    }
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=4;
                    if(i>0&&grid[i-1][j]==1) ans-=2;
                    if(j>0&&grid[i][j-1]==1) ans-=2;
                }
            }
        }
        return ans;
    }
     */
};


#endif //DOOCS_ISLANDPERIMETER_H
