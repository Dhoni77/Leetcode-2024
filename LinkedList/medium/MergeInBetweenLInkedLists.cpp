//
// Created by Aldrin on 20-03-2024.
//

#include "MergeInBetweenLInkedLists.h"

int main() {
    MergeInBetweenLInkedLists mergeInBetweenLInkedLists;

    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(4);
    list2->next = new ListNode(5);

    mergeInBetweenLInkedLists.mergeInBetween(root, 1, 2, list2);
}