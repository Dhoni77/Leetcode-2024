//
// Created by Aldrin on 01-02-2024.
//

#ifndef DOOCS_MINSTACK_H
#define DOOCS_MINSTACK_H
#include "bits/stdc++.h"
using namespace std;

class MinStack {
public:

    stack<int> stk;
    stack<pair<int, int>> minStack;

    MinStack() {

    }

    void push(int x) {
        stk.push(x);

        if(minStack.empty() || x < minStack.top().first) {
            minStack.push({x, 1});
        }
        else if(x == minStack.top().first)
            minStack.top().second++;
    }

    void pop() {
        if(stk.top() == minStack.top().first)
            minStack.top().second--;

        if(minStack.top().second == 0)
            minStack.pop();

        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStack.top().first;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Two Stacks
    // TC: O(1)
    // SC: O(N)
    /*
     *  stack<int> s1;
        stack<int> s2;

        MinStack() {
            s2.push(INT_MAX);
        }

        void push(int val) {
            s1.push(val);
            s2.push(min(val, s2.top()));
        }

        void pop() {
            s1.pop();
            s2.pop();
        }

        int top() {
            return s1.top();
        }

        int getMin() {
            return s2.top();
        }
     */
 //--------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class MinStack {
public:
    MinStack() {
        stack_.clear();
        min_stack_.clear();
    }

    void push(int val) {
        stack_.push_back(val);
        if (min_stack_.empty()) {
            min_stack_.push_back(val);
        } else {
            min_stack_.push_back(min(min_stack_.back(), val));
        }
    }

    void pop() {
        stack_.pop_back();
        min_stack_.pop_back();
    }

    int top() {
        return stack_.back();
    }

    int getMin() {
        return min_stack_.back();
    }
private:
    vector<int> stack_;
    vector<int> min_stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
    //----------------------------------------------------------------------------------------------------------------------------------
    /*
     * TC: O(1) for all operations
     * SC: O(N)
     * class MinStack {
public:
    stack<pair<int, int>> s1;

    MinStack() {
    }

    void push(int val) {
        s1.push({ val, s1.empty() ? val : min(val, s1.top().second) });
    }

    void pop() {
        s1.pop();
    }

    int top() {
        return s1.top().first;
    }

    int getMin() {
        return s1.top().second;
    }
};
     */
};


#endif //DOOCS_MINSTACK_H
