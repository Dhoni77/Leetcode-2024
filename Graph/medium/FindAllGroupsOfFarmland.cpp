//
// Created by Aldrin on 20-04-2024.
//

#include "FindAllGroupsOfFarmland.h"

int main() {
    FindAllGroupsOfFarmland findAllGroupsOfFarmland;

    vector<vector<int>> mat {
            {1, 0, 0},
            {0, 1, 1},
            {0, 1, 1}
    };

    findAllGroupsOfFarmland.findFarmland(mat);
}