//
// Created by Aldrin on 31-01-2024.
//

#include "ValidParantheses.h"

int main() {
    ValidParantheses vp;

    cout << vp.isValid("([{}])");
    cout << vp.isValid("((()))");
    cout << vp.isValid("]()]");
    cout << vp.isValid("]");
}