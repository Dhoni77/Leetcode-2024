//
// Created by Aldrin on 18-04-2024.
//

#include "IslandPerimeter.h"

int main() {
    IslandPerimeter islandPerimeter;

    vector<vector<int>> mat{
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}
    };

    cout << islandPerimeter.islandPerimeter(mat);
}