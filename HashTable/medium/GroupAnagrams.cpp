//
// Created by Aldrin on 06-02-2024.
//

#include "GroupAnagrams.h"

int main() {
    GroupAnagrams ga;

    vector<string> arr {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> res =  ga.groupAnagrams(arr);

    for(auto r: res) {
        for(auto i:r) {
            cout << i << endl;
        }
        cout << endl;
    }
}