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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(0);
        ListNode *dummy_ptr = &dummy;
        dummy_ptr->next = NULL;
        ListNode *itr = head;
        ListNode *remain_itr = dummy_ptr;
        int cur;
        while (itr && itr->next) {
            if (itr->val == itr->next->val) {
                cur = itr->val;
                while (itr && itr->val == cur) {
                    itr = itr->next;
                }
            } else {
                remain_itr->next = itr;
                itr = itr->next;
                remain_itr = remain_itr->next;
            }
        }
        remain_itr->next = itr;
        return dummy_ptr->next;
    }
};
