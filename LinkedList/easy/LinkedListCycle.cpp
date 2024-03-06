//
// Created by Aldrin on 06-03-2024.
//

#include "LinkedListCycle.h"

int main() {
    LinkedListCycle linkedListCycle;

    ListNode* root = new ListNode(3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next = root->next;

    cout << linkedListCycle.hasCycle(root);
}