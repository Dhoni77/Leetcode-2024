//
// Created by Aldrin on 12-03-2024.
//

#ifndef DOOCS_REMOVEZEROSUMCONSECUTIVENODESFROMLINKEDLIST_H
#define DOOCS_REMOVEZEROSUMCONSECUTIVENODESFROMLINKEDLIST_H
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class RemoveZeroSumConsecutiveNodesFromLinkedList {
public:
    /*
     * We may need to remove the head of the linked list if it is part of a sequence of zero-sum
     * consecutive nodes. We will save a ListNode dummy with any arbitary value whose next field
     * points to head. If head is deleted, dummy->next will be updated to the next remaining node,
     * so we still have a reference to the dummy of final linked list.
     *
     * When we encounter a prefix sum that we have seen before, we have discovered a zero-sum consecutive sequence.
     *
     * The crucial insight is that the prefix sum from the front node to node A will be equal to the sum from the front node to node B
     * if and only if the sum from node A.next to node B is 0.
     *
     *  All nodes between the first occurrence of a prefix sum through node B need to be deleted because they are part of a zero-sum consecutive sequence.
     */
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        int prefixSum = 0;

        while(head != nullptr) {
            prefixSum += head->val;

            if(mp.find(prefixSum) != mp.end()) {
                ListNode* start = mp[prefixSum];
                ListNode* temp = start;
                int sum = prefixSum;

                while(temp != head) {
                    temp = temp->next;
                    sum += temp->val;
                    if(temp!=head)
                        mp.erase(sum);
                }
                start->next = head->next;
            }
            else {
                mp[prefixSum] = head;
            }
            head = head->next;
        }

        return dummy->next;
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     * class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        while (current != nullptr) {
            // Add current's value to the prefix sum
            prefixSum += current->val;

            // If prefixSum is already in the hashmap,
            // we have found a zero-sum sequence:
            if (prefixSumToNode.find(prefixSum) != prefixSumToNode.end()) {
                ListNode* prev = prefixSumToNode[prefixSum];
                current = prev->next;

                // Delete zero sum nodes from hashmap
                // to prevent incorrect deletions from linked list
                int p = prefixSum + current->val;
                while (p != prefixSum) {
                    prefixSumToNode.erase(p);
                    current = current->next;
                    p += current->val;
                }

                // Make connection from the node before
                // the zero sum sequence to the node after
                prev->next = current->next;
            } else {
                // Add new prefixSum to hashmap
                prefixSumToNode[prefixSum] = current;
            }
            // Progress to next element in list
            current = current->next;
        }
        return front->next;
    }
};
     */
};


#endif //DOOCS_REMOVEZEROSUMCONSECUTIVENODESFROMLINKEDLIST_H
