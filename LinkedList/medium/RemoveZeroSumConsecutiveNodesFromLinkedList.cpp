//
// Created by Aldrin on 12-03-2024.
//

#include "RemoveZeroSumConsecutiveNodesFromLinkedList.h"

int main() {
    RemoveZeroSumConsecutiveNodesFromLinkedList removeZeroSumConsecutiveNodesFromLinkedList;

    auto* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(-3);
    root->next->next->next->next = new ListNode(-2);

    auto* ans = removeZeroSumConsecutiveNodesFromLinkedList.removeZeroSumSublists(root);
    while(ans != nullptr) {
        cout << ans->val << "\t";
        ans = ans->next;
    }
    cout << endl;
}