//
// Created by Aldrin on 13-02-2024.
//

#ifndef DOOCS_FINDFIRSTPALINDROMICSTRINGINTHEARRAY_H
#define DOOCS_FINDFIRSTPALINDROMICSTRINGINTHEARRAY_H
#include "bits/stdc++.h"
using namespace std;

class FindFirstPalindromicStringInTheArray {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& w : words) {
            bool ok = true;
            for (int i = 0, j = w.size() - 1; i < j; ++i, --j) {
                if (w[i] != w[j]) {
                    ok = false;
                }
            }
            if (ok) {
                return w;
            }
        }
        return "";
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * auto firstPalindrome(vector<string> words) -> string{
        auto const& result = find_if(cbegin(words), cend(words), [](auto const &word){
            return equal(cbegin(word), cbegin(word) + sizeof(word) / 2, crbegin(word));
        });
        return result == cend(words) ? "" : *result;
    }
     */
};


#endif //DOOCS_FINDFIRSTPALINDROMICSTRINGINTHEARRAY_H
