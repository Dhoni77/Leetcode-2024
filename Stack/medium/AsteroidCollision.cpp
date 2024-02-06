//
// Created by Aldrin on 06-02-2024.
//

#include "AsteroidCollision.h"

int main() {
    AsteroidCollision ac;

    vector<vector<int>> arr {
            {-1, 1, -2, 2, -3, 4},
            {5, 10, -5},
            {1, -2, -2, -2},
            {10, 2, -5},
            {8, -8},
            {-2,-1,1,2},
            {46, -36, 3, 39, 20, -33, 35, 4, -26, -37, 27, -50, -23, 48, 5, -1, 29, -34, 34, 11, 22, 8, 41, -20, -10, 17, 35,
             -14, -9, 3, 12, -13, -47, 23, -39, 25, -43, -2, 26, -26, -42, -5, -4, 34, 3, 25, 20, 27, -6},
            {-2,-2,-2,1},
            {-1,-1,1,-1,5}
    };

    for(auto a: arr) {
        vector<int> ans = ac.asteroidCollision(a);
        for(auto ab: ans)
            cout << ab << "\t";
        cout << endl;
    }
}