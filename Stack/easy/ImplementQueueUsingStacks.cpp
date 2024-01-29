//
// Created by Aldrin on 29-01-2024.
//

#include "ImplementQueueUsingStacks.h"

int main() {
    ImplementQueueUsingStacks implementQueueUsingStacks;

    implementQueueUsingStacks.push(1);
    implementQueueUsingStacks.push(2);
    implementQueueUsingStacks.push(3);
    cout << implementQueueUsingStacks.peek();
    cout << implementQueueUsingStacks.pop();
    cout << implementQueueUsingStacks.peek();
    cout << implementQueueUsingStacks.empty();
    cout << implementQueueUsingStacks.pop();
    cout << implementQueueUsingStacks.peek();
    cout << implementQueueUsingStacks.pop();
    cout << implementQueueUsingStacks.empty();
}