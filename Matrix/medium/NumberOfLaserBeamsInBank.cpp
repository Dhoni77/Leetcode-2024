//
// Created by Aldrin on 03-01-2024.
//

#include "NumberOfLaserBeamsInBank.h"

int main() {
    NumberOfLaserBeamsInBank nl;
    vector<string> bank {"011001","000000","010100","001000"};
//    vector<string> bank {"000","111","000"};
    cout << nl.numberOfBeams(bank);
}