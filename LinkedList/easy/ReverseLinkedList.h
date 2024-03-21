//
// Created by Aldrin on 21-03-2024.
//

#ifndef DOOCS_REVERSELINKEDLIST_H
#define DOOCS_REVERSELINKEDLIST_H
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReverseLinkedList {
public:
  ListNode* reverse(ListNode* root) {
    ListNode* prev = nullptr;
    while(root) {
        ListNode* curr = root;
        root = root->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
  }
  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  /*
   *
   *  ListNode* reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
   */
  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  /*
   *
   * ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
   */
};


#endif //DOOCS_REVERSELINKEDLIST_H
