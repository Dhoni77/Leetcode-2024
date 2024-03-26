//
// Created by Aldrin on 23-03-2024.
//

#include "ReorderList.h"

int main() {
    ReorderList reorderList;

    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);

    reorderList.reorderList(node);
}