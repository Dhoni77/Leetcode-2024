//
// Created by Aldrin on 21-03-2024.
//

#include "ReverseLinkedList.h"

int main() {
    ReverseLinkedList reverseLinkedList;

    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);

    ListNode* ans = reverseLinkedList.reverse(root);

    while(ans) {
        cout << ans->val << "\t";
        ans = ans->next;
    }
    cout << endl;
}