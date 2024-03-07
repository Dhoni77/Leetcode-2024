//
// Created by Aldrin on 07-03-2024.
//

#include "MiddleOfLinkedList.h"

int main() {
    MiddleOfLinkedList middleOfLinkedList;

    ListNode* listNode = new ListNode(1);
    listNode->next = new ListNode(2);
    listNode->next->next = new ListNode(3);
    listNode->next->next->next = new ListNode(4);
    listNode->next->next->next->next = new ListNode(5);

    middleOfLinkedList.middleNode(listNode);
}