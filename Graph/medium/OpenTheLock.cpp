//
// Created by Aldrin on 22-04-2024.
//

#include "OpenTheLock.h"

int main() {
    OpenTheLock openTheLock;

    vector<string> deadends{"0201","0101","0102","1212","2002"};
    string target = "0202";

    cout << openTheLock.openLock(deadends, target);
}