//
// Created by Aldrin on 28-02-2024.
//

#ifndef DOOCS_FLOODFILL_H
#define DOOCS_FLOODFILL_H
#include "bits/stdc++.h"
using namespace std;

class FloodFill {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> dirs{-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        int pick = image[sr][sc], row = image.size(), col = image[0].size();

        if(pick == color)
            return image;

        while(!q.empty()) {
            int sz = (int)q.size();

            while (sz--) {
                auto node = q.front();
                q.pop();

                if(image[node.first][node.second] == pick)
                    image[node.first][node.second] = color;

                for(int i=0;i<4;i++) {
                    int x = node.first + dirs[i], y = node.second + dirs[i+1];
                    if(x >= 0 and y >= 0 and x < row and y < col and image[x][y] == pick) {
                        image[x][y] = color;
                        q.emplace(x, y);
                    }
                }
            }
        }

        return image;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * DFS
     *
     * TC: O(N)
     * SC: O(N)
     *
     *      vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor) {
            int color = image[sr][sc];
            if (color != newColor) {
                dfs(image, sr, sc, color, newColor);
            }
            return image;
     }

     void dfs(vector<vector<int>> image, int r, int c, int color, int newColor) {
            if (image[r][c] == color) {
                image[r][c] = newColor;
                if (r >= 1) {
                    dfs(image, r - 1, c, color, newColor);
                }
                if (c >= 1) {
                    dfs(image, r, c - 1, color, newColor);
                }
                if (r + 1 < image.size()) {
                    dfs(image, r + 1, c, color, newColor);
                }
                if (c + 1 < image[0].size()) {
                    dfs(image, r, c + 1, color, newColor);
                }
            }
     }
     */
};


#endif //DOOCS_FLOODFILL_H
