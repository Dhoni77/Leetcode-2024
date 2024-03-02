//
// Created by Aldrin on 02-03-2024.
//

#include "SquaresOfASortedArray.h"

int main() {
    SquaresOfASortedArray squaresOfASortedArray;

//    vector<int> arr{-4,-1,0,3,4};
    vector<int> arr{1,2,3,4};

    vector<int> res = squaresOfASortedArray.sortedSquares(arr);

    for(int n : res) {
        cout << n << "\t";
    }
    cout << endl;
}