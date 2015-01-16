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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        ListNode dummy(0);
        ListNode *dummy_head = &dummy;
        dummy_head->next = head;
        ListNode *itr1 = head->next, *itr2, *prev1 = head, *prev2;
        while (itr1) {
            prev2 = dummy_head;
            itr2 = dummy_head->next;
            while (itr2 != itr1) {
                if (itr2->val > itr1->val) break;
                prev2 = prev2->next;
                itr2 = itr2->next;
            }
            if (itr1 == itr2) {
                itr1 = itr1->next;
                prev1 = prev1->next;
                continue;
            }
            prev1->next = itr1->next;
            prev2->next = itr1;
            itr1->next = itr2;
            itr1 = prev1->next;
        }
        return dummy_head->next;
    }
};
