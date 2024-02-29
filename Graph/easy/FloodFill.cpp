//
// Created by Aldrin on 28-02-2024.
//

#include "FloodFill.h"

int main() {
    FloodFill floodFill;

    vector<vector<int>> image{{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;

    floodFill.floodFill(image, sr, sc, color);
}