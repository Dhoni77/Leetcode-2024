//
// Created by Aldrin on 01-03-2024.
//

#include "SurroundedRegions.h"

int main() {
    SurroundedRegions surroundedRegions;

    vector<vector<char>> graph {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'O'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
    };

//    vector<vector<char>> graph {
//            {'X', 'X', 'X', 'X'},
//            {'X', 'O', 'O', 'X'},
//            {'X', 'X', 'O', 'X'},
//            {'X', 'O', 'X', 'X'},
//    };

    surroundedRegions.solve(graph);
}