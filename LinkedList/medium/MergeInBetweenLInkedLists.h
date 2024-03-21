//
// Created by Aldrin on 20-03-2024.
//

#ifndef DOOCS_MERGEINBETWEENLINKEDLISTS_H
#define DOOCS_MERGEINBETWEENLINKEDLISTS_H
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode*  next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode  *next) : val(x), next(next) {}
};

class MergeInBetweenLInkedLists {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* leftPrev = nullptr, *rightPrev = nullptr, *head = list1;
        int ind = 0;
        while(head) {
            if(ind == a - 1)
                leftPrev = head;
            if(ind == b+1)
                rightPrev = head;
            head = head->next;
            ind++;
        }

        ListNode* mid = list2;

        while(list2->next != nullptr) {
            list2 = list2->next;
        }

        leftPrev->next = mid;
        list2->next=rightPrev;

        return list1;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = nullptr;
        ListNode* end = list1;

        // Set start to node a - 1 and end to node b
        for (int index = 0; index < b; index++) {
            if (index == a - 1) {
                start = end;
            }
            end = end->next;
        }
        // Connect the start node to list2
        start->next = list2;

        // Find the tail of list2
        ListNode* tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        // Set the tail of list2 to end.next
        tail->next = end->next;
        end->next =  nullptr;

        return list1;
    }
};
     */
};


#endif //DOOCS_MERGEINBETWEENLINKEDLISTS_H
