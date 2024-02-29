//
// Created by Aldrin on 28-02-2024.
//

#include "RottingOranges.h"

int main() {
    RottingOranges rottingOranges;

//    vector<vector<int>> grid{
//            {2, 1, 1},
//            {1, 1, 1},
//            {0, 1, 2}
//    };

    vector<vector<int>> grid{
            {0, 2}
    };

    cout << rottingOranges.orangesRotting(grid);
}