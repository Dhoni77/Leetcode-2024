//
// Created by Aldrin on 09-04-2024.
//

#include "TimeNeededToBuyTickets.h"

int main() {
    TimeNeededToBuyTickets timeNeededToBuyTickets;
    vector<int> tickets = {2,3,2};
    int k = 2;

    cout << timeNeededToBuyTickets.timeRequiredToBuy(tickets, k);
}