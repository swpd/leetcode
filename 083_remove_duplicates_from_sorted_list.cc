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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;
        while (next) {
            if (next->val == curr->val) {
                curr->next = next->next;
                delete next;
            } else curr = next;
            next = curr->next;
        }
        return head;
    }
};
