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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        ListNode **itr = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                *itr = l1;
                l1 = l1->next;
            } else {
                *itr = l2;
                l2 = l2->next;
            }
            itr = &((*itr)->next);
        }
        if (l1) *itr = l1;
        if (l2) *itr = l2;
        return head;
    }
};
