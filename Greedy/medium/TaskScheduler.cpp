//
// Created by Aldrin on 19-03-2024.
//

#include "TaskScheduler.h"

int main() {
    TaskScheduler taskScheduler;

    vector<char> tasks{"A","A","A","B","B","B"};
    int n = 2;

    cout << taskScheduler.leastInterval(tasks, n);
}