//
// Created by Aldrin on 22-02-2024.
//

#include "FindTheTownJudge.h"

int main() {
    FindTheTownJudge ft;

    vector<vector<int>> edges {
            {1, 3}, {2, 3}
    };

    cout << ft.findJudge(3, edges);
}