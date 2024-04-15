//
// Created by Aldrin on 08-04-2024.
//

#ifndef DOOCS_NUMBEROFSTUDENTSUNABLETOEATLUNCH_H
#define DOOCS_NUMBEROFSTUDENTSUNABLETOEATLUNCH_H
#include "bits/stdc++.h"
using namespace std;

class NumberOfStudentsUnableToEatLunch {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentsQueue;
        stack<int> sandwichStack;
        int miss = 0;
        int n = students.size();

        for(int i=0;i<n;i++) {
            studentsQueue.push(students[i]);
            sandwichStack.push(sandwiches[n-i-1]);
        }

        while(!studentsQueue.empty()) {
            if(studentsQueue.front() == sandwichStack.top()) {
                studentsQueue.pop();
                sandwichStack.pop();
                miss = 0;
            }
            else {
                studentsQueue.push(studentsQueue.front());
                studentsQueue.pop();
                miss++;
                if(miss == studentsQueue.size())
                    break;
            }
        }

        return studentsQueue.size();
    }
    //------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *     int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int oneCnt = 0, zeroCnt = 0;
        for(int s: students) {
            if(s) {
                oneCnt++;
            }
            else zeroCnt++;
        }

        for(int s:sandwiches) {
            if(s == 0 and zeroCnt == 0) {
                return oneCnt;
            }
            if(s == 1 and oneCnt == 0) {
                return zeroCnt;
            }
            if(s == 0) {
                zeroCnt--;
            }
            else oneCnt--;
        }

        return 0;
    }
     */
};


#endif //DOOCS_NUMBEROFSTUDENTSUNABLETOEATLUNCH_H
