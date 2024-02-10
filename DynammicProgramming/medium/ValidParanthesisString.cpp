//
// Created by Aldrin on 10-02-2024.
//

#include "ValidParanthesisString.h"

int main() {
    ValidParanthesisString vps;

    cout << vps.checkValidString("(((((*)))**");
    cout << vps.checkValidString("(((()*))*(()(()*((((*)(((()(*())(((()*((())*))))(()(()())())((*()))((((()(*(())((()(()))((()()()*()");
}