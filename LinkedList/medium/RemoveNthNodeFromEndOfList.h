//
// Created by Aldrin on 03-03-2024.
//

#ifndef DOOCS_REMOVENTHNODEFROMENDOFLIST_H
#define DOOCS_REMOVENTHNODEFROMENDOFLIST_H
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode*  next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode  *next) : val(x), next(next) {}
};

class RemoveNthNodeFromEndOfList {
public:
    static int len(ListNode* root) {
        int length = 0;
        while(root != nullptr) {
            length++;
            root = root->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = len(head);

        if(length - n == 0) {
            return head->next;
        }
        else if(n == 1) {
            ListNode* temp = head;
            while(temp->next->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nullptr;
        }
        else {
            int idx = 0, stop = length - n;
            ListNode* start = head;
            while(start != nullptr) {
                if(++idx == stop) {
                    ListNode* end = start->next->next;
                    start->next = end;
                    break;
                }
                start = start->next;
            }
        }

        return head;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* dummyHead = new ListNode(0); // Create a dummy node
            dummyHead->next = head;

            ListNode* fast = dummyHead;
            ListNode* slow = dummyHead;

            // Move 'fast' pointer n steps ahead
            for (int i = 0; i < n; i++) {
                fast = fast->next;
            }

            // Move both 'fast' and 'slow' until 'fast' reaches the end
            while (fast->next != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }

            // Now 'slow' points to the node before the one to be removed
            slow->next = slow->next->next;

            return dummyHead->next;
        }
    };
     */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *
     *
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* temp =head;
            int list_size=0;
            while(temp!=NULL){
                temp =temp->next;
                list_size++;
            }

            temp =head;
            if(list_size-n==0){return head->next;}
            for (int cnt = 0; cnt < list_size - n - 1; cnt++) {
                temp = temp->next;
            }
            temp->next=temp->next->next;

            return head;
        }
    };
     */
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     * Recursion
     *
     * class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(1);
        dummy->next = head;
        ListNode *current = dummy;
        ListNode *last = dummy;
        NthFromEnd(current, last, n);
        head = dummy->next;
        return head;
    }
private:
        int NthFromEnd(ListNode* current, ListNode* last, int n){
            int retNum;
            if(current->next == NULL){
                retNum = 1;
            }
            else{
                retNum = NthFromEnd(current->next, current, n) + 1;
            }
            if(retNum == n){
                last->next = current->next;
            }
            return retNum;
        }
};
     */
};


#endif //DOOCS_REMOVENTHNODEFROMENDOFLIST_H
