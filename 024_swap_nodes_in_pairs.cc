/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        ListNode *dummy_head = &dummy;
        dummy_head->next = head;
        if (!head) return NULL;
        ListNode *first = head, *second = first->next, *prev = dummy_head;
        while (first && second) {
            ListNode *rest = second->next;
            second->next = first;
            first->next = rest;
            prev->next = second;
            prev = first;
            first = first->next;
            if (first) second = first->next;
        }
        return dummy_head->next;
    }
};
