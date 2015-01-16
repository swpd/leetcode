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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        ListNode *dummy_head = &dummy;
        dummy_head->next = head;
        ListNode *start, *prev = dummy_head;
        ListNode *itr = head;
        int i = 1;
        while (true) {
            if (i < m) {
                prev = itr;
                itr = itr->next;
            }
            else if (i == m) start = itr;
            else if (i <= n) {
                ListNode *current = start->next;
                start->next = current->next;
                current->next = prev->next;
                prev->next = current;
            } else break;
            i++;
        }
        return dummy_head->next;
    }
};
