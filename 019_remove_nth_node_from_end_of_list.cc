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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return NULL;
        ListNode dummy(0);
        ListNode *dummy_head = &dummy;
        dummy_head->next = head;
        ListNode *itr = dummy_head, *n_itr = dummy_head;
        for (int i = 0; i < n; ++i) {
            if (n_itr) n_itr = n_itr->next;
        }
        if (!n_itr) return head;
        ListNode *prev_node;
        while (n_itr) {
            n_itr = n_itr->next;
            prev_node = itr;
            itr = itr->next;
        }
        prev_node->next = itr->next;
        return dummy_head->next;
    }
};
