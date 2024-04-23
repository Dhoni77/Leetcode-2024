//
// Created by Aldrin on 21-04-2024.
//

#include "FindIfPathExistsInAGraph.h"

int main() {
    FindIfPathExistsInAGraph findIfPathExistsInAGraph;

    vector<vector<int>> gr{
            {2, 9},
            {7, 8},
            {5, 9},
            {7, 2},
            {3, 8},
            {2, 8},
            {1, 6},
            {3, 0},
            {7, 0},
            {8, 5}
    };

    int source= 1, destination = 0, n = 10;

    cout << findIfPathExistsInAGraph.validPath(n, gr, source, destination);
}