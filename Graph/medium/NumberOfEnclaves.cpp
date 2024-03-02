//
// Created by Aldrin on 01-03-2024.
//

#include "NumberOfEnclaves.h"

int main() {
    NumberOfEnclaves numberOfEnclaves;

//    vector<vector<int>> grid{
//            {0, 0, 0, 0},
//            {1, 0, 1, 0},
//            {0, 1, 1, 0},
//            {0, 0, 0, 0}
//    };

        vector<vector<int>> grid{{0,0,1,1,1,0,1,1,1,0,1},
                                 {1,1,1,1,0,1,0,1,1,0,0},
                                 {0,1,0,1,1,0,0,0,0,1,0},
                                 {1,0,1,1,1,1,1,0,0,0,1},
                                 {0,0,1,0,1,1,0,0,1,0,0},
                                 {1,0,0,1,1,1,0,0,0,1,1},
                                 {0,1,0,1,1,0,0,0,1,0,0},
                                 {0,1,1,0,1,0,1,1,1,0,0},
                                 {1,1,0,1,1,1,0,0,0,0,0},
                                 {1,0,1,1,0,0,0,1,0,0,1}};

    cout << numberOfEnclaves.numEnclaves(grid);
}