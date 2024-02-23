//
// Created by Aldrin on 23-02-2024.
//

#include "CheapestFlightsWithKStops.h"

int main() {
    CheapestFlightsWithKStops cf;
//    vector<vector<int>> flights{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
//    int n = 4, src = 0, dst = 3, k = 1;

//    int n = 3, src = 0, dst = 2, k = 1;
//    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};

//    int n = 3, src = 0, dst = 2, k = 0;
//    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};

    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights{{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    cout << "cheap is" << cf.findCheapestPrice(n, flights, src, dst, k);
}