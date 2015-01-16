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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *itr = head, *fast_itr = head->next;
        while (fast_itr && fast_itr->next) {
            itr = itr->next;
            fast_itr = fast_itr->next->next;
        }
        ListNode *p1 = head, *p2 = itr->next;
        itr->next = NULL;
        /* reverse the second part */
        ListNode *new_p2 = NULL, *curr = NULL;
        while (p2) {
            curr = p2;
            p2 = p2->next;
            curr->next = new_p2;
            new_p2 = curr;
        }
        p2 = new_p2;
        ListNode *h1, *h2;
        while (p2) {
            h1 = p1;
            h2 = p2;
            p1 = p1->next;
            p2 = p2->next;
            h1->next = h2;
            h2->next = p1;
        }
    }
};
