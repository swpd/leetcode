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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return NULL;
        ListNode *less_list = NULL, *greater_list = NULL;
        ListNode *less_last = NULL, *greater_last = NULL;
        ListNode *itr = head;
        while (itr) {
            if (itr->val < x) {
                if (!less_list) {
                    less_list = itr;
                    less_last = itr;
                } else {
                    less_last->next = itr;
                    less_last = itr;
                }
            } else {
                if (!greater_list) {
                    greater_list = itr;
                    greater_last = itr;
                } else {
                    greater_last->next = itr;
                    greater_last = itr;
                }
            }
            itr = itr->next;
        }
        if (!less_list) return greater_list;
        if (!greater_list) return less_list;
        less_last->next = greater_list;
        greater_last->next = NULL;
        return less_list;
    }
};
