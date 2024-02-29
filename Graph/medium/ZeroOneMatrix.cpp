//
// Created by Aldrin on 29-02-2024.
//

#include "ZeroOneMatrix.h"

int main() {
    ZeroOneMatrix zeroOneMatrix;

    vector<vector<int>> graph{
            {0, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
    };

    zeroOneMatrix.updateMatrix(graph);
}