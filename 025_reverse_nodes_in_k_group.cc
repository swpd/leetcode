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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k == 1) return head;
        ListNode *slow = head, *fast = head;
        int i = 1;
        while (fast && i < k) {
            fast = fast->next;
            i++;
        }
        if (fast) {
            ListNode *next = reverseKGroup(fast->next, k);
            fast->next = nullptr;
            ListNode *cur = nullptr;
            //reverse
            while (slow) {
                cur = slow;
                slow = slow->next;
                cur->next = next;
                next = cur;
            }
            return fast;
        } else {
            return head;
        }
    }
};
