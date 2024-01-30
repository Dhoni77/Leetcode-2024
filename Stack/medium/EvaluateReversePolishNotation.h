//
// Created by Aldrin on 30-01-2024.
//

#ifndef DOOCS_EVALUATEREVERSEPOLISHNOTATION_H
#define DOOCS_EVALUATEREVERSEPOLISHNOTATION_H
#include "bits/stdc++.h"
using namespace std;

class EvaluateReversePolishNotation {
public:
    int calculate(int first, int second, string op) {
        if(op == "+")
            return first + second;
        else if(op == "-")
            return first - second;
        else if(op == "*")
            return first * second;
        else
            return first / second;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                if(!st.empty()) {
                    int second = st.top();
                    st.pop();
                    int first = st.top();
                    st.pop();
                    st.push(calculate(first, second, s));
                }
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
    //--------------------------------------------------------------------------------------------------------------------------------
    /*
     *     int evalRPN(vector<string>& tokens) {
        stack<long> stack;
        const unordered_map<string, function<long(long, long)>> op{
                {"+", std::plus<long>()},
                {"-", std::minus<long>()},
                {"*", std::multiplies<long>()},
                {"/", std::divides<long>()}};

        for (const string& token : tokens)
            if (op.count(token)) {
                const long b = stack.top();
                stack.pop();
                const long a = stack.top();
                stack.pop();
                stack.push(op.at(token)(a, b));
            } else {
                stack.push(stoi(token));
            }

        return stack.top();
    }
     */
};


#endif //DOOCS_EVALUATEREVERSEPOLISHNOTATION_H
