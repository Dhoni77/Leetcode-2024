//
// Created by Aldrin on 03-03-2024.
//

#include "RemoveNthNodeFromEndOfList.h"

int main() {
    RemoveNthNodeFromEndOfList removeNthNodeFromEndOfList;

    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    ListNode* temp = removeNthNodeFromEndOfList.removeNthFromEnd(root, 3);

    while (temp != NULL) {
        cout << temp->val << "\t";
        temp = temp->next;
    }
}