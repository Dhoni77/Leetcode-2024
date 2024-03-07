//
// Created by Aldrin on 07-03-2024.
//

#ifndef DOOCS_MIDDLEOFLINKEDLIST_H
#define DOOCS_MIDDLEOFLINKEDLIST_H
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MiddleOfLinkedList {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};


#endif //DOOCS_MIDDLEOFLINKEDLIST_H
