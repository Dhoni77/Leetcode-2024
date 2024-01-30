//
// Created by Aldrin on 30-01-2024.
//

#include "EvaluateReversePolishNotation.h"

int main() {
    EvaluateReversePolishNotation evaluateReversePolishNotation;
    vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evaluateReversePolishNotation.evalRPN(tokens);
}