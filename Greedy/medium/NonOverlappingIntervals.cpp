//
// Created by Aldrin on 21-02-2024.
//

#include "NonOverlappingIntervals.h"

int main() {
    NonOverlappingIntervals no;

    vector<vector<int>> intervals{
        {-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}
    };

    cout << no.eraseOverlapIntervals(intervals);
}