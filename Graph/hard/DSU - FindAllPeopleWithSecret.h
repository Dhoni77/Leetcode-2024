//
// Created by Aldrin on 24-02-2024.
//

#ifndef DOOCS_DSU_FINDALLPEOPLEWITHSECRET_H
#define DOOCS_DSU_FINDALLPEOPLEWITHSECRET_H
#include "bits/stdc++.h"
using namespace std;

class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);

        for(int i=0;i<n;i++) parent[i] = i;
    }

    int Find(int node){
        return parent[node] = (parent[node] == node) ? node : Find(parent[node]);
    }

    void Reset(int node){
        parent[node] = node;
    }

    void Union(int nodea, int nodeb){
        int apar = Find(nodea), bpar = Find(nodeb);
        if(apar != bpar){
            rank[apar] < rank[bpar] ? parent[apar] = bpar : parent[bpar] = apar;
            rank[apar] += rank[apar] == rank[bpar] ? 1 : 0;
        }
    }
};

class DSU {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // sort meetings based on start time
        auto compare = [](const vector<int>& a, const vector<int>& b){
            if(a[2] == b[2]){
                return a[0] < b[0];
            }else{
                return a[2] < b[2];
            }
        };
        sort(meetings.begin(), meetings.end(), compare);

        // initialize DSU
        DSU dsu(n);

        // union . person 0 who knows secret with first person
        dsu.Union(0, firstPerson);

        // for each meeting
        // if meeting time is same push to same room
        // if person does not know the secret remove from room
        for(int i=0;i<meetings.size();) {
            vector<int> persons;
            int currMeet = meetings[i][2];
            while(i < meetings.size() && currMeet == meetings[i][2]) {
                dsu.Union(meetings[i][0], meetings[i][1]);
                persons.push_back(meetings[i][0]);
                persons.push_back(meetings[i][1]);
                i++;
            }

            for(int person: persons) {
                if(dsu.Find(person) != dsu.Find(0)) {
                    dsu.Reset(person);
                }
            }
        }

        vector<int> ans;
        // Add all persons knowing secret to the answer
        for(int i=0;i<n;i++) {
            if(dsu.Find(i) == dsu.Find(0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


#endif //DOOCS_DSU_FINDALLPEOPLEWITHSECRET_H
