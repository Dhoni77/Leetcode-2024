//
// Created by Aldrin on 23-04-2024.
//

#include "MinimumHeightTrees.h"

int main() {
    MinimumHeightTrees minimumHeightTrees;

    vector<vector<int>> edges{{0,1},{1,2},{2,3},{0,4},{4,5},{4,6},{6,7}};

    int n = 8;

    minimumHeightTrees.findMinHeightTrees(n, edges);
}