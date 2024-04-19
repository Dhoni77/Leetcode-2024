//
// Created by Aldrin on 19-04-2024.
//

#include "NumberOfIslands.h"
using namespace std;

int main() {
    NumberOfIslands numberOfIslands;

    vector<vector<char>> mat{
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    
    cout << numberOfIslands.numIslands(mat);
}