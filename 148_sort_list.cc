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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        ListNode dummy(0);
        ListNode *dummy_ptr = &dummy;
        dummy_ptr->next = NULL;
        ListNode *itr = dummy_ptr;
        while (left && right) {
            if (left->val < right->val) {
                itr->next = left;
                left = left->next;
            } else {
                itr->next = right;
                right = right->next;
            }
            itr = itr->next;
        }
        if (left) itr->next = left;
        if (right) itr->next = right;
        return dummy_ptr->next;
    }
};
