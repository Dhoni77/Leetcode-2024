//
// Created by Aldrin on 16-01-2024.
//

#ifndef DOOCS_INSERTDELETEGETRANDOM_H
#define DOOCS_INSERTDELETEGETRANDOM_H
#include "bits/stdc++.h"
using namespace std;

class InsertDeleteGetRandom {
public:
};

class RandomizedSet {
    RandomizedSet() {
    }

    bool insert(int val) {
        if (d.count(val)) {
            return false;
        }
        d[val] = q.size();
        q.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!d.count(val)) {
            return false;
        }
        int i = d[val];
        d[q.back()] = i;
        q[i] = q.back();
        q.pop_back();
        d.erase(val);
        return true;
    }

    int getRandom() {
        return q[rand() % q.size()];
    }

private:
    unordered_map<int, int> d;
    vector<int> q;
};


#endif //DOOCS_INSERTDELETEGETRANDOM_H
