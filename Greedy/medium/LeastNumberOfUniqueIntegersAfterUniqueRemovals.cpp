//
// Created by Aldrin on 16-02-2024.
//

#include "LeastNumberOfUniqueIntegersAfterUniqueRemovals.h"

int main() {
   vector<int> arr = {4,3,1,1,3,3,2};
   int k = 3;
    LeastNumberOfUniqueIntegersAfterUniqueRemovals ln;
   cout << ln.findLeastNumOfUniqueInts(arr, k);
}