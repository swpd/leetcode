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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int len = 0;
        ListNode *itr = head;
        while (itr) {
            len++;
            itr = itr->next;
        }
        int n = k % len;
        if (n == 0) return head;
        itr = head;
        ListNode *itr_n = head;
        for (int i = 0; i < n; ++i) itr_n = itr_n->next;
        while (itr_n->next) {
            itr_n = itr_n->next;
            itr = itr->next;
        }
        itr_n->next = head;
        head = itr->next;
        itr->next = NULL;
        return head;
    }
};
