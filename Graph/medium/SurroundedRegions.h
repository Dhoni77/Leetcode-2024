//
// Created by Aldrin on 01-03-2024.
//

#ifndef DOOCS_SURROUNDEDREGIONS_H
#define DOOCS_SURROUNDEDREGIONS_H
#include "bits/stdc++.h"
using namespace std;

class SurroundedRegions {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    void dfs(int i, int j, int row, int col, vector<vector<char>>& board) {
        if(i < 0 or j < 0 or i == row or j == col)
            return;

        if(board[i][j] == 'O') {
            board[i][j] = 'M';
            for(int k=0;k<4;k++) {
                int x = i + dirs[k], y = j + dirs[k+1];
                dfs(x, y, row, col, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(i == 0 or j == 0 or i == row - 1 or j == col - 1) {
                    if(board[i][j] == 'O')
                        dfs(i, j, row, col, board);
                }
            }
        }

        // Unmark Marked cells back to 'O'
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(board[i][j] == 'M')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * DFS
     *
     * class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    void dfs(int i,int j,vector<vector<char>>& board){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() ){
            return;
        }
        if(board[i][j]!='O') return;

        board[i][j]='*';
        dfs(i,j+1,board);
        dfs(i+1,j,board);
        dfs(i,j-1,board);
        dfs(i-1,j,board);
    }

    void solve(vector<vector<char>>& board) {
        if(board.size()<2) return;
        for(int i=0;i<board.size();i++){
            dfs(i,0,board);
            dfs(i,board[0].size()-1,board);
        }
        for(int j=1;j<board[0].size();j++){
            dfs(0,j,board);
            dfs(board.size()-1,j,board);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='*') board[i][j]='O';
            }
        }
    }
};
     */
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * BFS
     *
     * class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty())
      return;

    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = board.size();
    const int n = board[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (board[i][j] == 'O') {
            q.emplace(i, j);
            board[i][j] = '*';
          }

    // Mark the grids that stretch from the four sides with '*'.
    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (board[x][y] != 'O')
          continue;
        q.emplace(x, y);
        board[x][y] = '*';
      }
    }

    for (vector<char>& row : board)
      for (char& c : row)
        if (c == '*')
          c = 'O';
        else if (c == 'O')
          c = 'X';
  }
};
     */
};


#endif //DOOCS_SURROUNDEDREGIONS_H
