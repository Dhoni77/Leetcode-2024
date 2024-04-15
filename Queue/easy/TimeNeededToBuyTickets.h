//
// Created by Aldrin on 09-04-2024.
//

#ifndef DOOCS_TIMENEEDEDTOBUYTICKETS_H
#define DOOCS_TIMENEEDEDTOBUYTICKETS_H
#include "bits/stdc++.h"
using namespace std;

class TimeNeededToBuyTickets {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i=0;i < tickets.size();i++)
            q.push(i);
        int ans = 0;
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            tickets[idx] > 0 ? ans++: ans;
            if(--tickets[idx] == 0 and idx == k) {
                return ans;
            }
            if(tickets[idx] > 0)
                q.push(idx);
        }
        return 0;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;

        // Initialize the queue with ticket indices
        for (int i = 0; i < tickets.size(); i++) {
            queue.push(i);
        }

        int time = 0;

        // Loop until the queue is empty
        while (!queue.empty()) {
            // Increment the time counter for each iteration
            time++;

            // Get the front element of the queue
            int front = queue.front();
            queue.pop();

            // Buy a ticket for the front person
            tickets[front]--;

            // If person k bought all their tickets, return time
            if (k == front && tickets[front] == 0) {
                return time;
            }

           // Re-add the current index to the queue for the next iteration if there are still tickets
            if (tickets[front] != 0) {
                queue.push(front);
            }
        }

        return time;
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        // If person k only needs one ticket, return the time to buy it
        if (tickets[k] == 1)
            return k + 1;

        // Continue buying tickets until person k buys all their tickets
        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {
                // Buy a ticket at index 'i' if available
                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }

                // If person k bought all their rickets, return the time
                if (tickets[k] == 0)
                    return time;
            }
        }

        return time;
    }
};
     */
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for (int i = 0; i < tickets.size(); i++) {
            // If the current person is before or at the desired person 'k'
            if (i <= k) {
                // Buy the minimum of tickets available at person 'k' and the current person
                time += min(tickets[k], tickets[i]);
            } else {
                // If the current person is after 'k', buy the minimum of
                // (tickets available at person 'k' - 1) and the current person
                time += min(tickets[k] - 1, tickets[i]);
            }
        }

        return time;
    }
};
     */
};


#endif //DOOCS_TIMENEEDEDTOBUYTICKETS_H
