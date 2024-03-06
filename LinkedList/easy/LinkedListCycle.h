//
// Created by Aldrin on 06-03-2024.
//

#ifndef DOOCS_LINKEDLISTCYCLE_H
#define DOOCS_LINKEDLISTCYCLE_H
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListCycle {
public:
        bool hasCycle(ListNode *head) {
            ListNode *slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                    return true;
                }
            }
            return false;
        }
};


#endif //DOOCS_LINKEDLISTCYCLE_H
