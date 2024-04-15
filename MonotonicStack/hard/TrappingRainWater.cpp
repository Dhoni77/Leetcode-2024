//
// Created by Aldrin on 12-04-2024.
//

#include "TrappingRainWater.h"

int main() {
    TrappingRainWater trappingRainWater;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trappingRainWater.trap(height);
}