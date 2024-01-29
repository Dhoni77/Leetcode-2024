//
// Created by Aldrin on 29-01-2024.
//

#ifndef DOOCS_IMPLEMENTQUEUEUSINGSTACKS_H
#define DOOCS_IMPLEMENTQUEUEUSINGSTACKS_H
#include "bits/stdc++.h"
using namespace std;

class ImplementQueueUsingStacks {
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x) {
        if(s1.empty() and s2.empty()) {
            s2.push(x);
        }
        else {
            // copy from s2 to s1
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            // insert x in s1
            s1.push(x);
            // copy to s2
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    int pop() {
        int element = s2.top();
        s2.pop();
        return element;
    }

    int peek() {
        return s2.empty() ? -1 : s2.top();
    }

    bool empty() {
        return s2.empty() ? 1 : 0;
    }
    //----------------------------------------------------------------------------------------------------------------------------
    /*
     * class MyQueue {
         public:
          void push(int x) {
            input.push(x);
          }

          int pop() {
            peek();
            const int val = output.top();
            output.pop();
            return val;
          }

          int peek() {
            if (output.empty())
              while (!input.empty())
                output.push(input.top()), input.pop();
            return output.top();
          }

          bool empty() {
            return input.empty() && output.empty();
          }

         private:
          stack<int> input;
          stack<int> output;
        };
     */
};


#endif //DOOCS_IMPLEMENTQUEUEUSINGSTACKS_H
