//
// Created by Aldrin on 24-02-2024.
//

#include "DSU - FindAllPeopleWithSecret.h"

int main() {
    DSU fa;
    int n = 6, firstPerson = 1;
    vector<vector<int>> meetings{{1,2,5},{2,3,8},{1,5,10}};

    fa.findAllPeople(n, meetings, firstPerson);
}