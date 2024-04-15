//
// Created by Aldrin on 08-04-2024.
//

#include "NumberOfStudentsUnableToEatLunch.h"

int main() {
    NumberOfStudentsUnableToEatLunch numberOfStudentsUnableToEatLunch;

    vector<int> students{1, 1, 1, 0, 0, 1}, sandwiches{1, 0, 0, 0, 1, 1};

    cout << numberOfStudentsUnableToEatLunch.countStudents(students, sandwiches);
}