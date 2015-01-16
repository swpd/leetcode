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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *tail = headA;
        while (tail->next) tail = tail->next;
        tail->next = headB;
        ListNode *itr = headA;
        ListNode *fast_itr = headA->next;
        while (fast_itr && fast_itr->next && fast_itr != itr) {
            fast_itr = fast_itr->next->next;
            itr = itr->next;
        }
        if (!fast_itr || !fast_itr->next) {
            tail->next = NULL;
            return NULL;
        }
        itr = headA;
        fast_itr = fast_itr->next;
        while (itr != fast_itr) {
            itr = itr->next;
            fast_itr = fast_itr->next;
        }
        tail->next = NULL;
        return itr;
    }
};
