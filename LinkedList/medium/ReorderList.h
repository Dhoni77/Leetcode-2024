//
// Created by Aldrin on 23-03-2024.
//

#ifndef DOOCS_REORDERLIST_H
#define DOOCS_REORDERLIST_H
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReorderList {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // Step 1: Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode *prev = nullptr, *curr = slow, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Merge the first half and the reversed second half
        ListNode *first = head, *second = prev;
        while (second->next) {
            next = first->next;
            first->next = second;
            first = next;

            next = second->next;
            second->next = first;
            second = next;
        }
    }
//    void reorderList(ListNode* head) {
//        stack<ListNode*> st;
//        ListNode* node = head;
//
//        while (node != nullptr) {
//            st.push(node);
//            node = node->next;
//        }
//
//        ListNode* curr = head;
//        int n = st.size(), sz = n / 2;
//        for(int i=0;i<sz;i++) {
//            st.top()->next = curr->next;
//            curr->next = st.top();
//            curr = curr->next->next;
//            st.pop();
//        }
//        curr->next = nullptr;
//    }
    //-------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // Step 1: Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode *prev = nullptr, *curr = slow, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Merge the first half and the reversed second half
        ListNode *first = head, *second = prev;
        while (second->next) {
            next = first->next;
            first->next = second;
            first = next;

            next = second->next;
            second->next = first;
            second = next;
        }
    }
     */
    //---------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next)
      return;

    ListNode* mid = findMid(head);
    ListNode* reversed = reverse(mid);
    merge(head, reversed);
  }

 private:
  ListNode* findMid(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;

    return slow;
  }

  ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }

  void merge(ListNode* l1, ListNode* l2) {
    while (l2) {
      ListNode* next = l1->next;
      l1->next = l2;
      l1 = l2;
      l2 = next;
    }
  }
};
     */
};


#endif //DOOCS_REORDERLIST_H
