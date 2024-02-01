//
// Created by Aldrin on 31-01-2024.
//

#ifndef DOOCS_SUDOKUSOLVER_H
#define DOOCS_SUDOKUSOLVER_H
#include "bits/stdc++.h"
using namespace std;

class SudokuSolver {
public:
    bool isValid(vector < vector < char >> & board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;

            if (board[row][i] == c)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool solveSudoku(vector<vector<char>>& maze) {
        int n = maze.size();
        for(int i = 0;i< n;i++) {
            for(int j = 0;j < n;j++) {
                if(maze[i][j] == '.') {
                    for(char ch = '1';ch <= '9';ch++) {
                        if(isValid(maze, i, j, ch)) {
                            maze[i][j] = ch;
                            if(solveSudoku(maze))
                                return true;
                            else
                                maze[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};


#endif //DOOCS_SUDOKUSOLVER_H
