//
// Created by Aldrin on 19-01-2024.
//

#include "MinimumFallingPathSum.h"

int main() {
    MinimumFallingPathSum mfp;

//    vector<vector<int>> arr {
//            {2, 1, 3},
//            {6, 5, 4},
//            {7, 8, 9}
//    };
    vector<vector<int>> arr {
            {-19, 57},
            {-40, -5}
    };

    cout << mfp.minFallingPathSu(arr);
}